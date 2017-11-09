/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 08:10:36 by cblesche          #+#    #+#             */
/*   Updated: 2017/03/27 09:56:29 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		sort_asc(int *tab, size_t size)
{
	size_t	i;
	int		tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			if (i > 0)
				i--;
		}
		else
			i++;
	}
}

static void		sort_dsc(int *tab, size_t size)
{
	size_t	i;
	int		tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] < tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			if (i > 0)
				i--;
		}
		else
			i++;
	}
}

void			ft_sort_tab(int *tab, size_t size, int asc)
{
	if (asc)
		return (sort_asc(tab, size));
	return (sort_dsc(tab, size));
}
