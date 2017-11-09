/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:51:48 by cblesche          #+#    #+#             */
/*   Updated: 2016/11/28 19:11:07 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*destcp;
	unsigned char	*srccp;

	destcp = (unsigned char *)dest;
	srccp = (unsigned char *)src;
	while (n--)
	{
		if ((*destcp++ = *srccp++) == (unsigned char)c)
			return (destcp);
	}
	return (NULL);
}
