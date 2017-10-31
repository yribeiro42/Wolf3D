/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:26:51 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/27 20:19:22 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long long	get_unumber_length(t_parser *p, va_list **args)
{
	unsigned long long	number;

	number = va_arg(**args, unsigned long long);
	if (p->umaj)
		number = (unsigned long)number;
	else if (p->length == HH)
		number = (unsigned char)number;
	else if (p->length == H)
		number = (unsigned int)number;
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

int					process_unsigned(t_parser *p, va_list **args)
{
	unsigned long long	number;
	char				*retnbr;

	number = get_unumber_length(p, args);
	retnbr = ft_itoa_u(number);
	if (!number && p->dot && !p->width)
		return (0);
	if (p->precision)
		process_precision(&retnbr, p);
	if (p->left)
		process_left(&retnbr, p);
	if (p->width && p->zero)
		process_zero(&retnbr, p);
	if (p->width)
		process_width(&retnbr, p);
	return (print_ret(&retnbr));
}
