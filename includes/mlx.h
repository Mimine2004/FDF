/*
** mlx.h for MinilibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Jul 31 16:37:50 2000 Charlie Root
** Last update Tue May 15 16:23:28 2007 Olivier Crouzet
*/

/*
**   MinilibX -  Please report bugs
*/


/*
** FR msg - FR msg - FR msg
**
** La MinilibX utilise 2 librairies supplementaires qu'il
**      est necessaire de rajouter a la compilation :
**   -lmlx -lXext -lX11
**
** La MinilibX permet le chargement des images de type Xpm.
** Notez que cette implementation est incomplete.
** Merci de communiquer tout probleme de chargement d'image
** de ce type.
*/


#ifndef MLX_H

#define	MLX_H

#include "mlx_int.h"
#include "keyboard.h"
#include "fdf.h"
#include "../srcs/get_next_line/get_next_line.h"
#include <math.h>
# include <stdlib.h>
# include <unistd.h>

void	*mlx_init();
/*
**  needed before everything else.
**  return (void *)0 if failed
*/

void free_map3D(t_point3D **map3D);
/*
** Basic actions
*/
void	ft_putstr_fd(char *s, int fd);
/*
**  return void *0 if failed
*/

int		mlx_pixel_put(t_xvar *xvar,t_win_list *win,int x,int y,int color);
/*
**  origin for x & y is top left corner of the window
**  y down is positive
**  color is 0x00RRGGBB
*/
void	*mlx_new_window(t_xvar *xvar,int size_x,int size_y,char *title);
int		mlx_clear_window(t_xvar *xvar,t_win_list *win);
int		mlx_loop(t_xvar *xvar);
/*
** Image stuff
*/

void *mlx_new_image(t_xvar *xvar,int width, int height);
/*
**  return void *0 if failed
**  obsolete : image2 data is stored using bit planes
**  void	*mlx_new_image2(void *mlx_ptr,int width,int height);
*/
char	*mlx_get_data_addr(t_img *img,int *bits_per_pixel,
			   int *size_line,int *endian);
/*
**  endian : 0 = sever X is little endian, 1 = big endian
**  for mlx_new_image2, 2nd arg of mlx_get_data_addr is number_of_planes
*/
int	mlx_put_image_to_window(t_xvar *xvar,t_win_list *win,t_img *img,
				int x,int y);
int	mlx_get_color_value(t_xvar *xvar,int color)
;


/*
** dealing with Events
*/

int  mlx_mouse_hook(t_win_list *win,int (*funct)(),void *param);
int  mlx_key_hook(t_win_list *win,int (*funct)(),void *param);
int  mlx_expose_hook(t_win_list *win,int (*funct)(),void *param);

int mlx_loop_hook(t_xvar *xvar,int (*funct)(),void *param);
int   mlx_loop_end(t_xvar *xvar);
int   mlx_loop_end(t_xvar *xvar);

/*
**  hook funct are called as follow :
**
**   expose_hook(void *param);
**   key_hook(int keycode, void *param);
**   mouse_hook(int button, int x,int y, void *param);
**   loop_hook(void *param);
**
*/


/*
**  Usually asked...
*/

int		mlx_string_put(t_xvar *xvar,t_win_list *win,
			       int x,int y,int color,char *string);
void mlx_set_font(t_xvar *xvar, t_win_list *win, char *name);
void *mlx_xpm_to_image(t_xvar *xvar,char **xpm_data,int *width,int *height);
void *mlx_xpm_file_to_image(t_xvar *xvar,char *file,int *width,int *height);
int mlx_destroy_window(t_xvar *xvar,t_win_list *win);

int mlx_destroy_image(t_xvar *xvar, t_img *img);

int mlx_destroy_display(t_xvar *xvar);

/*
**  generic hook system for all events, and minilibX functions that
**    can be hooked. Some macro and defines from X11/X.h are needed here.
*/

int	mlx_hook(t_win_list *win, int x_event, int x_mask, 
		 int (*funct)(),void *param);

int mlx_do_key_autorepeatoff(t_xvar *xvar);
int mlx_do_key_autorepeaton(t_xvar *xvar);
int mlx_do_sync(t_xvar *xvar);

int		mlx_mouse_get_pos(t_xvar *xvar, t_win_list *win, \
			int *win_x_return, int *win_y_return);
int  mlx_mouse_move(t_xvar *xvar, t_win_list *win, int x, int y);
int  mlx_mouse_hide(t_xvar *xvar, t_win_list *win);
int  mlx_mouse_show(t_xvar *xvar, t_win_list *win);

int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

#endif /* MLX_H */
