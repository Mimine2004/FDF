/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:15:31 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/12 13:19:01 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/fdf.h"
#include "mlx.h"

int	get_3D_width(t_point3D **map3D)
{
    int	i;

    if (!map3D || !map3D[0]) // Add null-checks
        return (0);
    i = 0;
    while (!map3D[0][i].last)
        i++;
    return (i);
}

int	get_3D_height(t_point3D **map3D)
{
    int	i;

    if (!map3D) // Add null-checks
        return (0);
    i = 0;
    while (map3D[i])
        i++;
    return (i);
}

void	free_map2D(t_point2D **map2D, int alloc)
{
    int	i;

    if (!map2D) // Check if map2D is NULL
        return;
    if (!alloc)
    {
        i = 0;
        while (map2D[i])
            free(map2D[i++]);
        free(map2D);
    }
}

t_point2D	**alloc_map2D(t_point3D **map3D)
{
	int			width;
	int			height;
	int			i;
	int			j;
	t_point2D	**map2D;

	width = get_3D_width(map3D);
	height = get_3D_height(map3D);
	i = 0;
	map2D = (t_point2D **)malloc(sizeof(t_point2D *) * (height + 1));
	if (!map2D)
		return (NULL);
	while (i < height)
	{
		map2D[i] = (t_point2D *)malloc(sizeof(t_point2D) * (width));
		if (!map2D[i])
			return (free_map2D(map2D, 1), NULL); // Assuming '1' is the correct alloc value
		j = 0;
		while (j < width - 1)
			map2D[i][j++].last = 0;
		map2D[i][j].last = 1;
		i++;
	}
	return (map2D);
}

void convert_map(t_fdf *prog)
{
    int i, j;
    t_point3D **rot;
    t_point3D pro;

    free_map2D(prog->matrix.matrix2D, 1);
    prog->matrix.matrix2D = alloc_map2D(prog->matrix.matrix3D);
    if (!prog->matrix.matrix2D)
        exit(EXIT_FAILURE);
    rot = get_rotor_matrix(prog->matrix);
    if (!rot)
        exit(EXIT_FAILURE);
    i = 0;
    while (prog->matrix.matrix2D[i])
    {
        j = 0;
        while (!prog->matrix.matrix2D[i][j].last)
        {
            pro = prog->matrix.matrix3D[i][j];
            pro.z = prog->matrix.matrix3D[i][j].z + prog->matrix.plus_z;
            pro = multiple(*rot[2], multiple(*rot[1], multiple(*rot[0], pro)));
            prog->matrix.matrix2D[i][j].x = pro.x * prog->matrix.scale + prog->matrix.t_x;
            prog->matrix.matrix2D[i][j].y = pro.y * prog->matrix.scale + prog->matrix.t_y;
            j++;
        }
        i++;
    }
	free_rotor_matrix(rot);
}
