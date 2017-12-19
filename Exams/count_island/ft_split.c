/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:31:04 by exam              #+#    #+#             */
/*   Updated: 2017/12/17 18:37:49 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "island.h"

char		*ft_read(char *fname)
{
	int		ret;
	int		fd;
	int		bf_size;
	char	c;
	char	*res;
	char	*buf;

	res = NULL;
	bf_size = 0;
	if ((fd = open(fname, O_RDONLY)) == -1)
		return (0);
	while ((ret = read(fd, &c, 1)))
		bf_size++;
	buf = (char*)malloc(sizeof(char) * (bf_size + 1));
	close(fd);
	fd = open(fname, O_RDONLY);
	if ((ret = read(fd, buf, bf_size)))
		buf[ret] = '\0';
	if (ret && (res = (char*)malloc(sizeof(char) * (ret + 1))))
		ft_strncpy(res, buf, ret);
	free(buf);
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

char		**ft_split(char *fname)
{
	t_var	var;
	t_count cal;
	char	*str;
	char	**res;

	if (!(str = ft_read(fname)))
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
	free(str);
	return (res);
}
