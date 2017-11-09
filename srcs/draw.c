/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:55:10 by cblesche          #+#    #+#             */
/*   Updated: 2017/11/02 06:37:05 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			draw_overlay(t_env *env)
{
	mlx_string_put(env->mlx, env->win, PADDING_LEFT, 0 * PADDING_TOP,
			0xFFFFFF, "Esc   : Quit");
	mlx_string_put(env->mlx, env->win, PADDING_LEFT, 1 * PADDING_TOP,
			0xFFFFFF, "< ^ v > : MOVE");
	return (0);
}

int			get_color(t_env *e, int side)
{
	if (side)
	{
		if ((e->stp_x == -1 && e->stp_y == -1) ||
			(e->stp_x == 1 && e->stp_y == -1))
			return (0xf68d4a);
		if ((e->stp_x == -1 && e->stp_y == 1) ||
			(e->stp_x == 1 && e->stp_y == 1))
			return (0xf6f14a);
	}
	if ((e->stp_x == -1 && e->stp_y == -1) ||
		(e->stp_x == -1 && e->stp_y == 1))
		return (0xf64a5d);
	return (0xa862f7);
}

int			draw_scene(void *env)
{
	int		col;
	t_env	*e;

	e = env;
	col = 0;
	image_reinit(env);
	while (col < WINDOW_W)
		cast_ray(env, col++);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	draw_overlay(e);
	return (0);
}
