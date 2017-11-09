/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:50:04 by cblesche          #+#    #+#             */
/*   Updated: 2016/11/28 19:11:55 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_digit(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char			*ret;
	size_t			len;
	unsigned int	nb;

	len = count_digit(n);
	if (n < 0 && (nb = -n))
		len++;
	else
		nb = n;
	if (!(ret = ft_strnew(len)))
		return (NULL);
	if (n == 0)
		*ret = '0';
	if (n < 0)
		ret[0] = '-';
	while (nb)
	{
		ret[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (ret);
}
