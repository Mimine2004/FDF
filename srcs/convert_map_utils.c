/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:19:00 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/10 09:19:07 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"

int	get_3D_width(t_point3D **map3D)
{
	int	i;

	i = 0;
	while (map3D[0] && !map3D[0][i].last)
		i++;
	return (i);
}

int	get_3D_height(t_point3D **map3D)
{
	int	i;

	i = 0;
	while (map3D[i])
		i++;
	return (i);
}

void	free_map2D(t_point2D **map2D, int alloc)
{
	int	i;

	if (!alloc)
	{
		i = 0;
		while (map2D[i])
			free(map2D[i++]);
		free(map2D);
	}
	return (NULL);	
}