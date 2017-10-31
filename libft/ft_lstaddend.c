/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:19:35 by yribeiro          #+#    #+#             */
/*   Updated: 2016/11/28 19:38:01 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *node)
{
	t_list	*new_list;

	if (!alst)
		return ;
	new_list = *alst;
	if (!new_list)
	{
		ft_lstadd(alst, node);
		return ;
	}
	while (new_list->next)
		new_list = new_list->next;
	new_list->next = node;
	node->next = NULL;
}
