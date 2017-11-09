/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:53:59 by cblesche          #+#    #+#             */
/*   Updated: 2016/11/16 08:21:45 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int y;

	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	if (!*haystack || !*needle || haystack == needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		y = 0;
		while (needle[y] && haystack[i + y] == needle[y])
			y++;
		if (!needle[y])
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
