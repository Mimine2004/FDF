/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:16:37 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/13 13:19:04 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"


typedef struct s_point2D
{
	double	x;
	double	y;
	int		last;
}			t_point2D;

typedef struct s_point3D
{
	double	x;
	double	y;
	double	z;
	int		last;
}			t_point3D;

typedef struct s_mlx
{
	void	*img;
	int		bits_per_pixel;
	int		bits_per_line;
	int		endian;
	char	*buffer;
	t_xvar     *mlx_ptr;  
	t_win_list *win_ptr;  
	int         width;
	int         height;
	t_point2D	pos;
}			t_mlx;

typedef struct s_matrix
{
	t_point2D	**matrix2D;
	t_point3D	**matrix3D;
	int			t_x;
	int			t_y;
	double		rot_x;
	double		rot_y;
	double		rot_z;
	double		plus_z;
	double		scale;
	int			color;
}			t_matrix;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_mlx	img;
	t_matrix	matrix;
	t_point2D	mouse;
	int		mouse_down;
	int		mouse_right;
	int		mouse_left;
	char	*filename;
}			t_fdf;

char		*get_next_line(int fd);
void		free_map2D(t_point2D **map2D, int alloc);
t_point2D	**alloc_map2D(t_point3D **map3D);
void		convert_map(t_fdf *prog);
void		draw_order(t_fdf *prog);
void		draw_color_order(t_fdf *prog);
void		draw_line(t_mlx *mlx, t_point2D start, t_point2D end, int color);
void		draw_matrix(t_point2D **matrix, t_mlx *mlx, int color);
void		draw_matrix2(t_fdf *prog);
void		draw_carre(t_fdf *prog, t_point2D pos, int size, int color);
void		draw_rectangle(t_fdf *prog, t_point2D left, t_point2D right, int color);
void		ft_putstr_fd(char *s, int fd);
void		set_isometric(t_fdf *prog);
int			set_color(int keyboard, t_fdf *prog);
int			deal_key(int keyboard, void *param);
int			push_mouse(int keyboard, int x, int y, void *param);
int			release_mouse(int keyboard, int x, int y, void *param);
int			move_mouse(int x, int y, void *param);
void 		free_rotor_matrix(t_point3D **rotor);
t_point3D	**get_rotor_matrix(t_matrix matrix);
t_point3D 	multiple(t_point3D a, t_point3D b);
t_point2D	get_tpoint(int x, int y);
void 		mlx_init_background(void *mlx_ptr, void *win_ptr, int width, int height, int color);
void		mlx_put_line(void *mlx_ptr, void *win_ptr, t_point2D a, t_point2D b, int color);
void		free_map3D(t_point3D **map3D);

#endif
