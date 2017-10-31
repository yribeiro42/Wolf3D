/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:01:58 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/25 22:15:34 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		compte(unsigned long long nbr, int base)
{
	int ret;

	ret = 0;
	while (nbr != 0)
	{
		nbr /= base;
		ret++;
	}
	return (ret);
}

char			*ft_itoa_base_u(unsigned long long nbr, int base)
{
	char	*retour;
	int		nb;
	int		i;
	char	tab[17];

	if (nbr == 0)
		return (ft_strdup("0"));
	ft_strcpy(tab, "0123456789abcdef");
	nb = compte(nbr, base);
	retour = malloc(nb + 1);
	i = 1;
	while (nbr != 0)
	{
		retour[nb - i] = tab[nbr % base];
		nbr /= base;
		i++;
	}
	retour[nb] = '\0';
	return (retour);
}
