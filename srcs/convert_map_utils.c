/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:19:00 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/10 10:08:27 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"

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