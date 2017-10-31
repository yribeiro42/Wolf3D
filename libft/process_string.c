/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:14:04 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/27 20:20:09 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		process_string(t_parser *p, va_list **args)
{
	char	*str;
	int		ret;

	str = ft_strdup(va_arg(**args, char*));
	if (!str)
		str = ft_strdup("(null)");
	if (p->dot)
		process_precision(&str, p);
	if (p->width && p->zero)
		process_zero(&str, p);
	if (p->left)
		process_left(&str, p);
	if (p->width)
		process_width(&str, p);
	ft_putstr(str);
	ret = ft_strlen(str);
	ft_strdel(&str);
	return (ret);
}
