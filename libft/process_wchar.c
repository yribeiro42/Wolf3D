/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:07:32 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/26 18:25:51 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putwchar(wchar_t chr)
{
	if (chr <= 0x7F)
		ft_putchar(chr);
	else if (chr <= 0x7FF)
	{
		ft_putchar((chr >> 6) + 0xC0);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar((chr >> 12) + 0xE0);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putchar((chr >> 18) + 0xF0);
		ft_putchar(((chr >> 12) & 0x3F) + 0x80);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
	}
}

int		ft_wcharsize(wchar_t wc)
{
	int size;

	size = 0;
	if (wc <= 127)
		size = 1;
	else if (wc <= 2047)
		size = 2;
	else if (wc <= 65535)
		size = 3;
	else if (wc <= 1114111)
		size = 4;
	return (size);
}

int		process_wchar(t_parser *p, va_list **args)
{
	wchar_t		chr;
	int			ret;

	(void)p;
	ret = 0;
	chr = va_arg(**args, wchar_t);
	ft_putwchar(ret);
	ret = ft_wcharsize(ret);
	return (ret);
}
