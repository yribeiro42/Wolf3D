/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:29:07 by cblesche          #+#    #+#             */
/*   Updated: 2016/11/28 18:58:03 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *node)
{
	t_list *current;

	if (!alst || !node)
		return ;
	current = *alst;
	if (!current)
	{
		ft_lstadd(alst, node);
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = node;
	node->next = NULL;
}
