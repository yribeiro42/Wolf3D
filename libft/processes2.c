/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:06:53 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/27 20:41:25 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	process_zero(char **str, t_parser *p)
{
	if (p->precision && p->specifier == DECIMAL)
		return ;
	if (p->htag && (p->specifier == LOWERHEX || p->specifier == UPPERHEX))
		p->width -= 2;
	if ((p->showsign && !p->neg) && p->width > 0)
		p->width--;
	if ((p->space && !p->neg) && p->width > 0)
		p->width--;
	while (ft_strlen(*str) < p->width)
		*str = ft_strjoin_free(ft_strdup("0"), *str);
}

void	process_precision(char **str, t_parser *p)
{
	if (p->specifier == STRING)
		*str = ft_strndup(*str, p->precision);
	else if (p->neg)
	{
		while ((ft_strlen(*str) - 1) < p->precision)
			*str = ft_strjoin_free(ft_strdup("0"), *str);
	}
	else
	{
		while (ft_strlen(*str) < p->precision)
			*str = ft_strjoin_free(ft_strdup("0"), *str);
	}
}

void	process_replace(char **str)
{
	char	*find;

	find = ft_strchr(*str, '0');
	while (find)
	{
		*find = ' ';
		find = ft_strchr(find + 1, '0');
	}
}
