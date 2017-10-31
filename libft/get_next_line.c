/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:24:29 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/17 15:15:19 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*get_next_fd(int fd, t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(head, tmp);
	return (tmp);
}

static char			*get_next_free(char *content, char *buffer)
{
	char *tmp;

	tmp = content;
	content = ft_strjoin(content, buffer);
	free(tmp);
	return (content);
}

static char			*get_last_free(char *content, int ret)
{
	char *tmp;

	tmp = content;
	content = ft_strdup(content + ret);
	free(tmp);
	return (content);
}

int					get_next_line(int fd, char **line)
{
	t_list	static	*list;
	t_list			*head;
	char			buffer[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL || read(fd, buffer, 0) < 0)
		return (-1);
	head = list;
	list = get_next_fd(fd, &head);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		list->content = get_next_free(list->content, buffer);
		if (ft_strchr(buffer, EOL))
			break ;
	}
	ret = 0;
	while (((char *)list->content)[ret] != EOL && ((char *)list->content)[ret])
		ret++;
	*line = ft_strndup(list->content, ret);
	if (((char *)list->content)[ret] == EOL)
		ret++;
	list->content = get_last_free(list->content, ret);
	list = head;
	return (ret ? 1 : 0);
}
