/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:09:09 by yribeiro          #+#    #+#             */
/*   Updated: 2016/11/28 20:10:46 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tmpdest;
	unsigned char		*tmpsrc;
	size_t				i;

	tmpdest = (unsigned char*)dest;
	tmpsrc = (unsigned char*)src;
	i = 0;
	if (tmpsrc < tmpdest)
	{
		while (n--)
			tmpdest[n] = tmpsrc[n];
	}
	else
	{
		while (i < n)
		{
			tmpdest[i] = tmpsrc[i];
			i++;
		}
	}
	return (dest);
}
