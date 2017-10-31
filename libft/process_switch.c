/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_switch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:26:31 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/27 20:23:49 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	process_emptystring(char **str)
{
	ft_strdel(str);
	*str = ft_strdup("");
}

int		print_ret(char **s)
{
	int ret;

	ft_putstr(*s);
	ret = ft_strlen(*s);
	ft_strdel(s);
	return (ret);
}

int		print_char(char c)
{
	ft_putchar(c);
	return (1);
}

void	ft_switch(char **str)
{
	int	i;

	i = 0;
	while (str[0][i] && str[0][i] != '0')
		i++;
	if (i != (int)ft_strlen(str[0]))
		str[0][i] = '-';
	i++;
	while (str[0][i] && str[0][i] != '-')
		i++;
	if (i != (int)ft_strlen(str[0]))
		str[0][i] = '0';
}

void	process_switch(char **str)
{
	ft_switch(str);
}
