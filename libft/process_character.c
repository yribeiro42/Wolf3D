/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 22:37:31 by anonymous         #+#    #+#             */
/*   Updated: 2017/10/27 20:41:02 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*fill_character(char c, size_t size)
{
	char	*ret;

	size = (!size) ? size : (size - 1);
	if (!(ret = ft_strnew(size)))
		exit(1);
	ft_memset(ret, c, size);
	return (ret);
}

int			process_nullchar(t_parser *p, char *width)
{
	int		ret;
	int		i;
	char	*cp;
	char	*tmp;

	ret = ft_strlen(width) + 1;
	if (!(tmp = ft_strnew(ret)))
		exit(1);
	cp = tmp;
	if (p->left)
		tmp++;
	i = -1;
	while (width[++i])
		tmp[i] = width[i];
	write(1, cp, ret);
	ft_strdel(&cp);
	return (ret);
}

int			process_character(t_parser *p, va_list **args)
{
	char	chr;
	char	*str;
	char	*width;

	chr = (char)va_arg(**args, int);
	if (!chr)
	{
		chr = (p->zero ? '0' : ' ');
		width = fill_character(chr, (p->width));
		return (process_nullchar(p, width));
	}
	str = malloc(sizeof(*str) * 2);
	str[0] = chr;
	str[1] = '\0';
	if (p->left)
		process_left(&str, p);
	if (p->width)
		process_width(&str, p);
	return (print_ret(&str));
}
