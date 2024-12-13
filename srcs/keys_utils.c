/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:14:28 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/13 10:26:52 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/fdf.h"

void	set_isometric(t_fdf *prog)
{
    if (!prog)
        return;
    prog->matrix.rot_x = 0.523599; // 30° in radians
    prog->matrix.rot_y = 0;
    prog->matrix.rot_z = 0.523599; // 30° in radians
    prog->matrix.t_x = 0.2;
}

int	set_color(int keyboard, t_fdf *prog)
{
    if (!prog)
        return (0);

    // Map keys to colors
    if (keyboard == KEYBOARD_1)
        prog->matrix.color = 0xFFFFFF; // White
    else if (keyboard == KEYBOARD_2)
        prog->matrix.color = 0x00FF00; // Green
    else if (keyboard == KEYBOARD_3)
        prog->matrix.color = 0xFF0000; // Red
    else if (keyboard == KEYBOARD_4)
        prog->matrix.color = 0x0000FF; // Blue
    else if (keyboard == KEYBOARD_5)
        prog->matrix.color = 0xFFFF00; // Yellow
    else if (keyboard == KEYBOARD_6)
        prog->matrix.color = 0xFF00FF; // Pink
    else if (keyboard == KEYBOARD_7)
        prog->matrix.color = 0x808080; // Grey
    else
        return (0);
    return (1);
}