/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:58:40 by vfil              #+#    #+#             */
/*   Updated: 2017/12/10 17:26:39 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	read_file(const int fd, char **rem)
{
	char	buf[BUFF_SIZE + 1];
	char	*buf2;
	int		ret;

	buf2 = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) && ret != -1)
	{
		buf[ret] = '\0';
		buf2 = ft_strjoin(*rem, buf);
		if (ft_strlen(*rem) > 0)
			ft_strdel(rem);
		*rem = ft_strdup(buf2);
		if (buf2)
			ft_strdel(&buf2);
		if (ft_strchr(buf, '\n') || ret != BUFF_SIZE)
			return (ret);
	}
	return (ret);
}

static int	divide(char **line, char **rem)
{
	char	*nl;
	char	*buf;

	buf = 0;
	nl = ft_strchr(*rem, '\n');
	if (nl)
	{
		*line = ft_strsub(*rem, 0, nl - *rem);
		if (nl + 1)
			buf = ft_strdup(nl + 1);
		ft_strdel(rem);
		*rem = buf;
		return (0);
	}
	*line = ft_strdup(*rem);
	if (ft_strlen(*rem) > 0)
		ft_strdel(rem);
	*rem = "";
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*lst;
	int				ret;
	int				end;

	ret = 1;
	end = 0;
//	system ("leaks a.out");
	if (fd < 0 || !line)
		return (-1);
	if (!head)
		head = ft_lstnew("", fd);
	lst = head;
	while (lst && lst->content_size != (size_t)fd)
		lst = lst->next;
	if (!lst && (lst = ft_lstnew("", fd)))
		ft_lstadd(&head, lst);
	if (lst && !(ft_strchr(lst->content, '\n')))
		ret = read_file(fd, (char**)&lst->content);
	printf("ret = %i\n", ret);
	if (ret < 0)
		return (-1);
	if (lst)
		end = divide(line, (char**)&lst->content);
	return ((/*!ret && */end) ? 0 : 1);
}
