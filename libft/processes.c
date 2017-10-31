/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:06:53 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/27 20:22:11 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	process_sign(char **str, t_parser *p)
{
	if (!p->neg)
		*str = ft_strjoin_free(ft_strdup("+"), *str);
}

void	process_space(char **str, t_parser *p)
{
	if (**str != '-' && !p->showsign)
		*str = ft_strjoin_free(ft_strdup(" "), *str);
}

void	process_left(char **str, t_parser *p)
{
	while (ft_strlen(*str) < p->width)
		*str = ft_strjoin_free(*str, ft_strdup(" "));
}

void	process_htag(char **str, t_parser *p)
{
	if (p->specifier == LOWERHEX || p->specifier == POINTER)
		*str = ft_strjoin_free(ft_strdup("0x"), *str);
	if (p->specifier == UPPERHEX)
		*str = ft_strjoin_free(ft_strdup("0X"), *str);
	if (p->specifier == OCTAL)
		*str = ft_strjoin_free(ft_strdup("0"), *str);
}

void	process_width(char **str, t_parser *p)
{
	while (ft_strlen(*str) < p->width)
		*str = ft_strjoin_free(ft_strdup(" "), *str);
}
