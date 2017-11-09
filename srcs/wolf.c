/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:50:05 by cblesche          #+#    #+#             */
/*   Updated: 2017/11/02 06:38:17 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		map(t_env *env)
{
	int i;
	int j;

	i = 1;
	srand(time(NULL));
	while (i < 20 - 1)
	{
		env->map[0][i] = 1;
		env->map[20 - 1][i++] = 1;
	}
	i = 0;
	while (i < 20)
	{
		env->map[i][0] = 1;
		env->map[i++][20 - 1] = 1;
	}
	i = 1;
	while (i++ < 20 - 2)
	{
		j = 0;
		while (j++ < 20 - 2)
			env->map[1 + rand() % (20 - 2)][1 + rand() % (20 - 2)] = rand() % 2;
	}
}

void		spawn(t_env *env, int i, int j)
{
	env->map[i][j + 1] = 0;
	env->map[i][j - 1] = 0;
	env->map[i + 1][j] = 0;
	env->map[i + 1][j + 1] = 0;
	env->map[i + 1][j - 1] = 0;
	env->map[i - 1][j] = 0;
	env->map[i - 1][j + 1] = 0;
	env->map[i - 1][j - 1] = 0;
	env->pos_x = i;
	env->pos_y = j;
}

void		init_settings(t_env *env)
{
	int		i;
	int		j;

	i = 20 / 2;
	env->dir_x = -1;
	env->plne_y = 1.3;
	while (i < 20)
	{
		j = 20 / 2;
		while (j < 20)
		{
			if (env->map[i][j] == 0)
				return (spawn(env, i, j));
			j++;
		}
		i++;
	}
}

int			wolf(void)
{
	t_env	*env;

	if (!(env = init_mlx()))
		return (1);
	map(env);
	init_settings(env);
	env->win = mlx_new_window(env->mlx, WINDOW_W, WINDOW_H, "Wolf3d");
	mlx_hook(env->win, DestroyNotify, StructureNotifyMask, quit_program, env);
	mlx_hook(env->win, KeyPress, KeyPressMask, key_pressed, env);
	mlx_expose_hook(env->win, draw_scene, env);
	mlx_loop(env->mlx);
	return (0);
}

int			main(int argc, char **argv)
{
	argv = NULL;
	if (argc > 1)
	{
		ft_putendl_fd("Usage : ./wolf3d", 2);
		return (1);
	}
	return (wolf());
}
