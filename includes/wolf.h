/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 16:10:08 by cblesche          #+#    #+#             */
/*   Updated: 2017/11/02 06:37:45 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <time.h>
# include "/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h"
# define KEY_ESCAPE 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define WINDOW_W 1200
# define WINDOW_H 800
# define PADDING_LEFT 5
# define PADDING_TOP 25
# define MOVE_SPEED 0.10
# define ROT_SPEED 0.10

typedef struct	s_env
{
	int			map[20][20];
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plne_x;
	double		plne_y;
	double		p_wll_dst;
	double		s_dst_x;
	double		s_dst_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		ray_pos_x;
	double		ray_pos_y;
	double		dlt_dst_x;
	double		dlt_dst_y;
	int			map_x;
	int			map_y;
	int			stp_x;
	int			stp_y;
	void		*mlx;
	void		*win;
	int			*img;
	char		*pixels;
	int			sizeline;
	int			bpp;
	int			endian;
}				t_env;

t_env			*init_mlx(void);
void			destroy_mlx(t_env *env);
void			mlx_img_pixel_put(t_env *env, int x, int y, int color);
void			image_reinit(t_env *env);

int				get_color(t_env *env, int side);
int				draw_scene(void *env);
void			cast_ray(t_env *e, int col);

int				key_pressed(int keycode, void *env);
int				quit_program(int key, void *env);

#endif
