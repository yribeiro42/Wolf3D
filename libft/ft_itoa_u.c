/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:50:21 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/26 12:19:00 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_len(unsigned long long n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa_u(unsigned long long n)
{
	char				*str;
	size_t				str_len;
	unsigned long long	nb;

	str_len = nb_len(n);
	nb = n;
	str = ft_strnew(str_len);
	if (!str)
		return (NULL);
	str[--str_len] = nb % 10 + '0';
	while (nb /= 10)
		str[--str_len] = nb % 10 + '0';
	return (str);
}
