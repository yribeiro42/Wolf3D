/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:53:48 by cblesche          #+#    #+#             */
/*   Updated: 2016/11/23 14:02:20 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int		i;
	int		y;
	size_t	size;

	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	if (!*haystack || !*needle || haystack == needle)
		return ((char *)haystack);
	i = 0;
	size = n;
	while (n && haystack[i])
	{
		y = 0;
		while (needle[y] && haystack[i + y] == needle[y])
			y++;
		if (!needle[y] && size >= (size_t)i + y)
			return ((char *)haystack + i);
		i++;
		n--;
	}
	return (NULL);
}
