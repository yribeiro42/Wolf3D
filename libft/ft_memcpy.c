/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:52:17 by cblesche          #+#    #+#             */
/*   Updated: 2016/11/16 08:17:06 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *destcp;
	unsigned char *srccp;

	destcp = (unsigned char *)dest;
	srccp = (unsigned char *)src;
	while (n--)
		*destcp++ = *srccp++;
	return (dest);
}
