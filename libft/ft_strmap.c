/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:39:27 by cblesche          #+#    #+#             */
/*   Updated: 2016/11/16 08:38:57 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char *ret;
	char *cp;

	if (!s || !f || !(ret = ft_strnew(ft_strlen(s))))
		return (NULL);
	cp = ret;
	while (*s)
		*ret++ = f(*s++);
	return (cp);
}
