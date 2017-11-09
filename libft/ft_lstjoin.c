/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:29:07 by cblesche          #+#    #+#             */
/*   Updated: 2016/11/28 18:58:03 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstjoin(t_list **lst1, t_list *lst2)
{
	t_list *current;

	if (!lst1 || !lst2)
		return ;
	current = *lst1;
	if (!current)
	{
		*lst1 = lst2;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = lst2;
}
