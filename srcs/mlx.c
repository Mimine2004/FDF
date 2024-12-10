/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 08:19:04 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/10 09:11:28 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"

typedef struct s_mlx
{
	t_xvar     *mlx_ptr;  
	t_win_list *win_ptr;  
	int         width;
	int         height;
} t_mlx;

void mlx_init_background(t_mlx *mlx, int width, int height, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, color);
			y++;
		}
		x++;
	}
}

void	mlx_put_line(t_mlx *mlx, t_point2D a, t_point2D b, int color)
{
	double	x;
	double	y;
	int		i;

	x = a.x - b.x;
	y = a.y - b.y;
	i = (sqrt((x * x) + (y * y)));
	while (i--)
	{
		x = (x / i);
		y = (y / i);
		mlx_pixel_put(mlx, a.x, a.y, color);
		a.x -= x;
		a.y -= y;
	}
}

void	mlx_put_line(t_mlx *mlx, t_point2D a, t_point2D b, int color)
{
	double dx = b.x - a.x;
	double dy = b.y - a.y;
	double dist = fmax(fabs(dx), fabs(dy));

	if (dist < 1)
		return;
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (int)a.x, (int)a.y, color);
	a.x += dx / dist;
	a.y += dy / dist;
	mlx_put_line(mlx, a, b, color);
}