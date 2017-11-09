/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:50:04 by cblesche          #+#    #+#             */
/*   Updated: 2016/11/28 19:09:42 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (*s)
	{
		if (!word && *s != c)
		{
			word = 1;
			i++;
		}
		if (word && *s == c)
			word = 0;
		s++;
	}
	return (i);
}

static int		word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		words;
	int		w_len;
	int		i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (words + 1))))
		return (NULL);
	i = 0;
	while (words)
	{
		while (*s && *s == c)
			s++;
		w_len = word_len(s, c);
		if (!(tab[i++] = ft_strsub(s, 0, w_len)))
			return (NULL);
		s += w_len;
		words--;
	}
	return (tab);
}
