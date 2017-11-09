/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblesche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:55:10 by cblesche          #+#    #+#             */
/*   Updated: 2017/02/03 14:47:04 by cblesche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*get_file(const int fd, t_file **lst)
{
	t_file	*file;

	file = *lst;
	while (file)
	{
		if (file->fd == fd)
			return (file);
		file = file->next;
	}
	if (!(file = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	ft_bzero(file->buff, BUFF_SIZE);
	file->fd = fd;
	file->pos = 0;
	file->ret = -1;
	file->next = *lst;
	*lst = file;
	return (file);
}

void	delete_file(t_file **lst, t_file *file)
{
	t_file	*current;

	if (*lst == file)
	{
		free(file);
		*lst = NULL;
		return ;
	}
	current = *lst;
	while (current)
	{
		if (current->next == file)
		{
			current->next = file->next;
			free(file);
			return ;
		}
		current = current->next;
	}
}

int		fill_line(char **line, t_file *file)
{
	size_t	size;
	char	*end;
	char	*buff;
	char	*sub;

	buff = file->buff + file->pos;
	if (!(end = ft_strchr(buff, '\n')))
		end = file->buff + file->ret;
	size = (size_t)(end - buff);
	if (!(sub = ft_strsub(buff, 0, size)))
		return (0);
	ft_stradd(line, sub);
	if (!*line)
		return (0);
	ft_strdel(&sub);
	file->pos += size;
	if (*end)
		file->pos++;
	return (*end == '\n' ? 1 : 0);
}

int		fill_buffer(t_file *file)
{
	file->pos = 0;
	file->ret = read(file->fd, file->buff, BUFF_SIZE);
	if (file->ret == -1)
		return (file->ret);
	file->buff[file->ret] = 0;
	return (file->ret);
}

int		get_next_line(const int fd, char **line)
{
	static t_file	*lst = NULL;
	t_file			*file;

	if (fd < 0 || !line || !(*line = ft_strnew(1)) ||
		!(file = get_file(fd, &lst)))
		return (-1);
	while (file->buff[file->pos] || fill_buffer(file) > 0)
	{
		if (fill_line(line, file))
			return (1);
		if (!*line)
		{
			delete_file(&lst, file);
			return (-1);
		}
	}
	if (**line)
		return (1);
	ft_strdel(line);
	delete_file(&lst, file);
	return (file->ret);
}
