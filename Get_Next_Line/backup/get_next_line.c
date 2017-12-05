/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:58:40 by vfil              #+#    #+#             */
/*   Updated: 2017/12/05 17:08:20 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	read_file(const int fd, char **rem)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	while ((ret = read(fd, buf, BUFF_SIZE)) && ret != -1)
	{
		if (ret != 0)
		{
			buf[ret] = '\0';
			*rem = ft_strjoin(*rem, buf);
			if (ft_strchr(buf, '\n'))
				return (1);
		}
	}
	return (ret == -1 ? -1 : 0);
}

static int	divide(char **line, char **rem)
{
	char	*nl;
	
	nl = ft_strchr(*rem, '\n');
	if (nl)
	{
		*line = ft_strsub(*rem, 0, nl - *rem);
		*rem = ft_strsub(*rem, nl - *rem + 1, BUFF_SIZE);
		return (0);
	}
	else
	{
		*line = *rem;
		return (1);
	}
}

t_list		check_list(t_list *lst, int fd)
{
	while (lst->next != NULL)
	{
		if (lst->content_size == (size_t)fd)
			return (*lst);
		lst = lst->next;
	}
	lst->next = ft_lstnew("", 0);
	lst->next->content_size = fd;
	return (*lst->next);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	lst;
	t_list			buf;
	int				ret;
	int				end;

	ret = 0;
	end = 0;
	if (!lst.content)
		lst = *ft_lstnew("", 0);
	buf = check_list(&lst, fd);
	if (!(ft_strchr(buf.content, '\n')))
		ret = read_file(fd, (char**)&buf.content);
	if (!fd || !line || ret == -1)
		return (-1);
	end = divide(line, (char**)&buf.content);
	return (end ? 0 : 1);
}
