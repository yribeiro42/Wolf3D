/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:50:04 by cblesche          #+#    #+#             */
/*   Updated: 2016/11/16 08:59:54 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			is_blank(char c)
{
	return ((c == ' ') || (c == '\t') || (c == '\n'));
}

static const char	*count_start(const char *s)
{
	while (is_blank(*s))
		s++;
	return (s);
}

static const char	*count_end(const char *s)
{
	if (!*s)
		return (s);
	s += ft_strlen(s);
	while (is_blank(*(s - 1)))
		s--;
	return (s);
}

char				*ft_strtrim(char const *start)
{
	char		*ret;
	const char	*end;

	if (!start)
		return (NULL);
	start = count_start(start);
	end = count_end(start);
	ret = ft_strsub(start, 0, (size_t)(end - start));
	return (ret);
}
