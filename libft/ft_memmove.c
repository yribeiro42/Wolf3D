/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:52:31 by cblesche          #+#    #+#             */
/*   Updated: 2016/11/16 08:58:08 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_revmemcpy(void *dest, const void *src, size_t n)
{
	unsigned char *destcp;
	unsigned char *srccp;

	destcp = (unsigned char *)dest + n;
	srccp = (unsigned char *)src + n;
	while (n--)
		*--destcp = *--srccp;
	return (dest);
}

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	else if (dest > src)
		return (ft_revmemcpy(dest, src, n));
	return ((void*)dest);
}
