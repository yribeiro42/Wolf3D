/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:53:30 by cblesche          #+#    #+#             */
/*   Updated: 2016/11/16 08:20:45 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *cp;

	cp = dest;
	while (*dest)
		dest++;
	while (n && *src)
	{
		*dest++ = *src++;
		n--;
	}
	*dest = 0;
	return (cp);
}
