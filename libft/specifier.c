/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 17:37:51 by anonymous         #+#    #+#             */
/*   Updated: 2017/10/27 20:36:59 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_specifier		return_specifier(char format)
{
	if (format == 'd' || format == 'D' || format == 'i')
		return (DECIMAL);
	if (format == 's' || format == 'S')
		return (STRING);
	if (format == 'p')
		return (POINTER);
	if (format == 'o' || format == 'O')
		return (OCTAL);
	if (format == 'u' || format == 'U')
		return (UNSIGNEDECI);
	if (format == 'x')
		return (LOWERHEX);
	if (format == 'X')
		return (UPPERHEX);
	if (format == 'c')
		return (CHARACTER);
	if (format == 'C')
		return (WIDECHAR);
	else if (format != '\n')
		return (format);
	return (ERROR);
}

int				parse_specifier(char **format, t_parser *p)
{
	if (**format == 'U')
		p->umaj = 1;
	else if (**format == 'D')
		p->dmaj = 1;
	else if (**format == 'O')
		p->omaj = 1;
	else if (**format == 'i')
		p->i = 1;
	if (p->specifier == ERROR)
		return (0);
	p->specifier = return_specifier(**format);
	return (0);
}

int				get_specifier(t_parser *p, va_list **args)
{
	int		read;

	read = 0;
	if (p->specifier == STRING)
		read = process_string(p, args);
	else if (p->specifier == POINTER)
		read = process_pointer(p, args);
	else if (p->specifier == DECIMAL)
		read = process_int(p, args);
	else if (p->specifier == OCTAL)
		read = process_octal(p, args);
	else if (p->specifier == LOWERHEX || p->specifier == UPPERHEX)
		read = process_hex(p, args);
	else if (p->specifier == UNSIGNEDECI)
		read = process_unsigned(p, args);
	else if (p->specifier == CHARACTER || p->specifier == WIDECHAR)
		read = process_character(p, args);
	else
		read = process_error(p);
	return (read);
}
