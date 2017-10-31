/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:39:35 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/27 20:43:37 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long	get_xnumber_length(t_parser *p, va_list **args)
{
	long		number;

	number = va_arg(**args, long long);
	if (p->length == HH)
		number = (unsigned char)number;
	else if (p->length == H)
		number = (unsigned short)number;
	else if (p->length == L)
		number = (unsigned long)number;
	else if (p->length == LL)
		number = (unsigned long long)number;
	else if (p->length == J)
		number = (uintmax_t)number;
	else if (p->length == Z)
		number = (size_t)number;
	else if (p->length == DEFAULT)
		number = (unsigned int)number;
	return (number);
}

char		*ft_strupper(char *s)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}

int			process_hex(t_parser *p, va_list **args)
{
	long long	number;
	char		*retnbr;

	number = get_xnumber_length(p, args);
	if (p->specifier != POINTER && !number && p->dot && !p->width)
		return (0);
	if (p->specifier != POINTER && !number && !p->width)
		return (print_char('0'));
	retnbr = ft_itoa_base_u(number, 16);
	if (p->dot && !p->precision)
		process_replace(&retnbr);
	if (p->dot)
		process_precision(&retnbr, p);
	if (p->zero)
		process_zero(&retnbr, p);
	if (p->htag)
		process_htag(&retnbr, p);
	if (p->left)
		process_left(&retnbr, p);
	if (p->width)
		process_width(&retnbr, p);
	if (p->specifier == UPPERHEX)
		retnbr = ft_strupper(retnbr);
	return (print_ret(&retnbr));
}
