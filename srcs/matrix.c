/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:22:49 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/10 09:23:00 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"

t_point3D multiple(t_point3D *a, t_point3D *b)
{
	t_point3D	res;

	res.x = a->x * b->x + a->y * b->y + a->z * b->z;
	res.y = a->x * b->x + a->y * b->y + a->z * b->z;
	res.z = a->x * b->x + a->y * b->y + a->z * b->z;
	return (res);
}

t_point2D	get_tpoint(int x, int y)
{
	t_point2D	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}