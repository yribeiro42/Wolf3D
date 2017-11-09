/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:01:47 by cblesche          #+#    #+#             */
/*   Updated: 2017/11/02 06:35:16 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	rotate_camera(t_env *env, double rot)
{
	double tmp;

	tmp = env->dir_x;
	env->dir_x = env->dir_x * cos(rot) - env->dir_y * sin(rot);
	env->dir_y = tmp * sin(rot) + env->dir_y * cos(rot);
	tmp = env->plne_x;
	env->plne_x = env->plne_x * cos(rot) - env->plne_y * sin(rot);
	env->plne_y = tmp * sin(rot) + env->plne_y * cos(rot);
}

void	move(int keycode, t_env *env)
{
	double x;
	double y;

	if (keycode == KEY_UP)
	{
		x = env->pos_x + env->dir_x * MOVE_SPEED;
		y = env->pos_y + env->dir_y * MOVE_SPEED;
		if (x >= 0 && x < 20 && !env->map[(int)x][(int)env->pos_y])
			env->pos_x = x;
		if (y >= 0 && y < 20 && !env->map[(int)env->pos_x][(int)y])
			env->pos_y = y;
	}
	if (keycode == KEY_DOWN)
	{
		x = env->pos_x - env->dir_x * MOVE_SPEED;
		y = env->pos_y - env->dir_y * MOVE_SPEED;
		if (x >= 0 && x < 20 && !env->map[(int)x][(int)env->pos_y])
			env->pos_x = x;
		if (y >= 0 && y < 20 && !env->map[(int)env->pos_x][(int)y])
			env->pos_y = y;
	}
	if (keycode == KEY_RIGHT)
		rotate_camera(env, -ROT_SPEED);
	if (keycode == KEY_LEFT)
		rotate_camera(env, ROT_SPEED);
}

int		quit_program(int key, void *env)
{
	t_env *e;

	e = env;
	key = 0;
	exit(0);
	return (0);
}

int		key_pressed(int keycode, void *env)
{
	t_env *e;

	e = env;
	if (keycode == KEY_ESCAPE)
	{
		destroy_mlx(e);
		exit(0);
	}
	move(keycode, e);
	draw_scene(env);
	return (0);
}
