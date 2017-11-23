/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:31:04 by exam              #+#    #+#             */
/*   Updated: 2017/11/21 13:17:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "island.h"

char		*ft_read(int fd)
{
	int		ret;
	char	buf[BUF_SIZE];
	char	*res;

	res = NULL;
	if ((ret = read(fd, buf, BUF_SIZE)))
		buf[ret] = '\0';
	if (ret && (res = (char*)malloc(sizeof(char) * (ret + 1))))
		ft_strncpy(res, buf, ret);
	return (res);
}

void		ft_strncpy(char *dst, char *src, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

t_count		ft_count_len(char *str)
{
	t_count res;
	t_var	var;

	var.i = 0;
	res.count = 0;
	res.len = 0;
	while (str[var.i] != '\0')
	{
		if (str[var.i] == '\n' && res.count == 0)
			res.len = var.i;
		if (str[var.i] == '\n')
			res.count++;
		var.i++;
	}
	return (res);
}

char		**ft_split(int fd)
{
	t_var	var;
	t_count cal;
	char	*str;
	char	**res;

	if (!(str = ft_read(fd)))
		return (NULL);
	cal = ft_count_len(str);
	var.i = 0;
	var.j = 0;
	if (cal.count > 0)
		res = (char**)malloc(sizeof(char*) * (cal.count + 1));
	while (var.i < cal.count)
	{
		res[var.i] = (char*)malloc(sizeof(char) * (cal.len));
		var.k = 0;
		while (str[var.j] != '\0' && str[var.j] != '\n')
			res[var.i][var.k++] = str[var.j++];
		res[var.i][var.k] = '\0';
		var.j++;
		var.i++;
	}
	res[var.i] = 0;
	return (res);
}
