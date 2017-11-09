/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:55:10 by cblesche          #+#    #+#             */
/*   Updated: 2017/11/02 06:37:12 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_col(int col, int height, int color, t_env *env)
{
	int vert;
	int wall_top;
	int wall_bottom;

	vert = 0;
	wall_bottom = WINDOW_H / 2 + height / 2;
	wall_top = WINDOW_H / 2 - height / 2;
	while (vert < WINDOW_H)
	{
		if (vert < wall_top)
			mlx_img_pixel_put(env, col, vert, 0x3399ff);
		else if (vert > wall_bottom)
			mlx_img_pixel_put(env, col, vert, 0x555555);
		else
			mlx_img_pixel_put(env, col, vert, color);
		vert++;
	}
}

void		get_ray_direction(t_env *e)
{
	if (e->ray_dir_x < 0)
	{
		e->stp_x = -1;
		e->s_dst_x = (e->ray_pos_x - e->map_x) * e->dlt_dst_x;
	}
	else
	{
		e->stp_x = 1;
		e->s_dst_x = (e->map_x + 1.0 - e->ray_pos_x) * e->dlt_dst_x;
	}
	if (e->ray_dir_y < 0)
	{
		e->stp_y = -1;
		e->s_dst_y = (e->ray_pos_y - e->map_y) * e->dlt_dst_y;
	}
	else
	{
		e->stp_y = 1;
		e->s_dst_y = (e->map_y + 1.0 - e->ray_pos_y) * e->dlt_dst_y;
	}
}

void		get_ray_colision(t_env *e, int *side)
{
	int		hit;

	hit = 0;
	while (!hit)
	{
		if (e->s_dst_x < e->s_dst_y)
		{
			e->s_dst_x += e->dlt_dst_x;
			e->map_x += e->stp_x;
			*side = 0;
		}
		else
		{
			e->s_dst_y += e->dlt_dst_y;
			e->map_y += e->stp_y;
			*side = 1;
		}
		if (e->map_x < 0 || e->map_y < 0 || e->map_x >= 20 ||
			e->map_y >= 20)
			return ;
		if (e->map[e->map_x][e->map_y] > 0)
			hit = 1;
	}
}

void		dda(t_env *e, int col)
{
	int		hit;
	int		side;
	int		h;

	hit = 0;
	e->s_dst_x = 0;
	e->s_dst_y = 0;
	get_ray_direction(e);
	get_ray_colision(e, &side);
	if (!side)
		e->p_wll_dst = (e->map_x - e->ray_pos_x + (1 - e->stp_x) / 2)
			/ e->ray_dir_x;
	else
		e->p_wll_dst = (e->map_y - e->ray_pos_y + (1 - e->stp_y) / 2)
			/ e->ray_dir_y;
	h = (64 * 5) / e->p_wll_dst;
	draw_col(col, h, get_color(e, side), e);
}

void		cast_ray(t_env *e, int col)
{
	double camera_x;

	camera_x = 2 * col / (double)WINDOW_W - 1;
	e->ray_pos_x = e->pos_x;
	e->ray_pos_y = e->pos_y;
	e->ray_dir_x = e->dir_x + e->plne_x * camera_x;
	e->ray_dir_y = e->dir_y + e->plne_y * camera_x;
	e->map_x = (int)e->ray_pos_x;
	e->map_y = (int)e->ray_pos_y;
	e->dlt_dst_x = sqrt(1 + (e->ray_dir_y * e->ray_dir_y) /
							(e->ray_dir_x * e->ray_dir_x));
	e->dlt_dst_y = sqrt(1 + (e->ray_dir_x * e->ray_dir_x) /
							(e->ray_dir_y * e->ray_dir_y));
	dda(e, col);
}
