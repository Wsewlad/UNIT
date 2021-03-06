/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:58:40 by vfil              #+#    #+#             */
/*   Updated: 2017/12/04 19:29:32 by vfil             ###   ########.fr       */
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

int			get_next_line(const int fd, char **line)
{
	static char	*rem;
	int			ret;
	int			end;

	ret = 0;
	if (!rem)
		rem = ft_memalloc(0);
	if (!(ft_strchr(rem, '\n')))
		ret = read_file(fd, &rem);
	if (!fd || !line || ret == -1)
		return (-1);
	end = divide(line, &rem);
	return (end ? 0 : 1);
}
