/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 08:19:04 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/11 11:00:49 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"

/* typedef struct s_mlx
{
	t_xvar     *mlx_ptr;  
	t_win_list *win_ptr;  
	int         width;
	int         height;
} t_mlx; */

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
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    double step = fmax(fabs(dx), fabs(dy));

    if (step == 0)
        return;
    
    double x_increment = dx / step;
    double y_increment = dy / step;

    while (step--)
    {
        mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, round(a.x), round(a.y), color);
        a.x += x_increment;
        a.y += y_increment;
    }
}

/* void	mlx_put_line(t_mlx *mlx, t_point2D a, t_point2D b, int color)
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
} */