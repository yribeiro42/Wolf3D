/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:01:35 by cblesche          #+#    #+#             */
/*   Updated: 2017/11/02 06:27:24 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_env	*init_mlx(void)
{
	t_env *env;

	if (!(env = (t_env*)ft_memalloc(sizeof(t_env))))
		return (NULL);
	env->mlx = mlx_init();
	env->img = mlx_new_image(env->mlx, WINDOW_W, WINDOW_H);
	env->pixels = mlx_get_data_addr(env->img, &(env->bpp),
									&(env->sizeline), &(env->endian));
	return (env);
}

void	image_reinit(t_env *env)
{
	env->img = mlx_new_image(env->mlx, WINDOW_W, WINDOW_W);
	env->pixels = mlx_get_data_addr(env->img, &(env->bpp),
									&(env->sizeline), &(env->endian));
}

void	destroy_mlx(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_window(env->mlx, env->win);
	free(env);
}

void	mlx_img_pixel_put(t_env *env, int x, int y, int color)
{
	int tmp;

	tmp = (x * env->bpp / 8) + (y * env->sizeline);
	env->pixels[tmp++] = color;
	env->pixels[tmp++] = color >> 8;
	env->pixels[tmp] = color >> 16;
}
