/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:14:02 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/27 20:42:07 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*ret;
	char	*cp;
	int		i;

	if (!s1 || !s2 || !(ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	cp = ret;
	i = 0;
	while (s1[i])
		*ret++ = s1[i++];
	i = 0;
	while (s2[i])
		*ret++ = s2[i++];
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (cp);
}
