/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:58:40 by vfil              #+#    #+#             */
/*   Updated: 2017/12/11 17:03:17 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	read_file(const int fd, t_list *lst)
{
	char	buf[BUFF_SIZE + 1];
	char	*buf2;
	int		ret;
	while ((ret = read(fd, buf, BUFF_SIZE)) && ret != -1)
	{
		buf[ret] = '\0';
	//	printf("buf = %s\n", buf);
		buf2 = ft_strjoin(lst->content, buf);
	//	printf("buf2 = %s\n", buf2);
		ft_memdel(&lst->content);
		lst->content = ft_strdup(buf2);
//		printf("lst->cont = %s\n", lst->content);
		ft_strdel(&buf2);
		if (ft_strchr(buf, '\n') || ret != BUFF_SIZE)
			return (ret);
	}
	return (ret);
}

/*
 * Функція divide ділить зчитаний рядок з файлу. Якщо рядок містить '\n',
 * то все, що йому передує віддається в зміну line, а все, що після нього -
 * в контент поточного листа. Функція повертає 1, якщо весь контент з файлу
 * зчитано й передано, інакше, повертає 0;
 */

static int	divide(char **line, t_list *lst)
{
	char	*ln;
	char	*buf;
	buf = 0;
	ln = ft_strchr((char*)lst->content, '\n');
	if (ln)
	{
		*line = ft_strsub(lst->content, 0, ln - (char*)lst->content);
		buf = ft_strdup(ln + 1);
		if (buf)
		{
			ft_memdel(&lst->content);
			lst->content = ft_strdup(buf);		
			if (lst->content)
				ft_strdel(&buf);
		}
//	printf("lst->cont div = %s#\n", lst->content);
//	printf("line div = %s#\n", *line);
		return (0);
	}
	*line = ft_strdup(lst->content);
//	printf("line2 div = %s#\n", *line);
	ft_memdel(&lst->content);
	if (**line)
		return (0);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*lst;
	int				ret;

	ret = 1;
	if (fd < 0 || !line)
		return (-1);
	if (!head)
		head = ft_lstnew("", fd);
	lst = head;
	while (lst && lst->content_size != (size_t)fd)
		lst = lst->next;
	if (!lst && (lst = ft_lstnew("", fd)))
		ft_lstadd(&head, lst);
	if (lst->content && !ft_strchr(lst->content, '\n'))
		ret = read_file(fd, lst);
	if (ret < 0)
		return (-1);
	if (lst->content)
	{
		if (!(divide(line, lst)))
			return (1);
	}
	return (0);
}
