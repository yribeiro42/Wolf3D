/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:03:56 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/27 19:31:30 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		process_pointer(t_parser *p, va_list **args)
{
	p->length = LL;
	p->htag = 1;
	return (process_hex(p, args));
}
