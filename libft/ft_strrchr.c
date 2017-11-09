/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:53:52 by cblesche          #+#    #+#             */
/*   Updated: 2016/11/16 11:34:53 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*cp;

	cp = s + ft_strlen(s);
	if (!c)
		return ((char *)cp);
	while (*s != *cp)
	{
		if (*--cp == c)
			return ((char *)cp);
	}
	return (NULL);
}
