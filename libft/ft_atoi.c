/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:50:04 by cblesche          #+#    #+#             */
/*   Updated: 2016/11/16 08:13:28 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int nb;
	int neg;

	neg = -1;
	while ((*str == '\n') || (*str == '\t') || (*str == '\v') ||
	(*str == ' ') || (*str == '\f') || (*str == '\r'))
		str++;
	if (*str == '-')
		neg = 1;
	if (*str == '-' || *str == '+')
		str++;
	nb = 0;
	while (*str && ft_isdigit(*str))
	{
		nb *= 10;
		nb -= *str - '0';
		str++;
	}
	return (nb * neg);
}
