/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:19:49 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/12 13:33:38 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"

void	draw_line(t_mlx *mlx, t_point2D start, t_point2D end, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = fabs(end.x - start.x);
	dy = fabs(end.y - start.y);
	sx = start.x < end.x ? 1 : -1;
	sy = start.y < end.y ? 1 : -1;
	if (dx > dy)
		err = dx / 2;
	else
		err = -dy / 2;
	while (1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			start.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			start.y += sy;
		}
	}
}

void	draw_matrix(t_point2D **matrix, t_mlx *mlx, int color)
{
	int	x;
	int	y;

	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (!matrix[x][y].last)
		{
			if (matrix[x + 1])
				draw_line(mlx, matrix[x][y], matrix[x + 1][y], color);
			if (!matrix[x][y + 1].last)
				draw_line(mlx, matrix[x][y], matrix[x][y + 1], color);
			y++;
		}
		x++;
	}
}

void	draw_matrix2(t_fdf *prog)
{
	if (!prog->mouse_down)
	{
		mlx_init_background((t_mlx *)prog->mlx, ((t_mlx *)prog->mlx)->width, ((t_mlx *)prog->mlx)->height,
			0x000000);
		convert_map(prog);
		draw_matrix(prog->matrix.matrix2D, prog->mlx, prog->matrix.color);
		mlx_put_image_to_window(prog->mlx, prog->win, prog->img.img,
			prog->img.pos.x, prog->img.pos.y);
	}
	prog->mouse_down = 1;
}

void	draw_carre(t_fdf *prog, t_point2D pos, int size, int color)
{
    int	x;
    int	y;

    if (!prog || !prog->mlx || !prog->win) // Check for NULL pointers
        return;
    x = pos.x;
    while (x < pos.x + size)
    {
        y = pos.y;
        while (y < pos.y + size)
        {
            mlx_pixel_put(prog->mlx, prog->win, x, y, color);
            y++;
        }
        x++;
    }
}

void	draw_rectangle(t_fdf *prog, t_point2D left, t_point2D right, int color)
{
    int	x;
    int	y;

    if (!prog || !prog->mlx || !prog->win) // Check for NULL pointers
        return;
    x = left.x;
    while (x < right.x)
    {
        y = left.y;
        while (y < right.y)
        {
            mlx_pixel_put(prog->mlx, prog->win, x, y, color);
            y++;
        }
        x++;
    }
}