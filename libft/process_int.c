/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:14:02 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/27 20:24:14 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long	get_number_length(t_parser *p, va_list **args)
{
	long	number;

	number = va_arg(**args, long long);
	if (p->dmaj)
		number = (long)number;
	else if (p->length == HH)
		number = (char)number;
	else if (p->length == H)
		number = (short)number;
	else if (p->length == L)
		number = (long)number;
	else if (p->length == LL)
		number = (long long)number;
	else if (p->length == J)
		number = (intmax_t)number;
	else if (p->length == Z)
		number = (size_t)number;
	else if (p->length == DEFAULT)
		number = (int)number;
	return (number);
}

int			process_int(t_parser *p, va_list **args)
{
	long long	number;
	char		*str;

	number = get_number_length(p, args);
	p->neg = (number < 0) ? 1 : 0;
	str = ft_itoa(number);
	if (p->dot && !p->precision && number == 0)
		process_emptystring(&str);
	if (p->dot)
		process_precision(&str, p);
	if (p->zero)
		process_zero(&str, p);
	if (p->showsign)
		process_sign(&str, p);
	if (p->space)
		process_space(&str, p);
	if (p->left)
		process_left(&str, p);
	if (p->width)
		process_width(&str, p);
	if (p->neg && (p->zero || p->precision))
		process_switch(&str);
	return (print_ret(&str));
}
