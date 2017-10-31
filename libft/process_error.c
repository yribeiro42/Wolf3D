/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:24:25 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/27 19:45:12 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		process_error(t_parser *p)
{
	char	*str;
	int		ret;

	str = ft_strnew(1);
	str[0] = p->specifier;
	if (p->left)
		process_left(&str, p);
	if (p->width)
		process_width(&str, p);
	ft_putstr(str);
	ret = ft_strlen(str);
	ft_strdel(&str);
	return (ret);
}
