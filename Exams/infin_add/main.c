/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:49:32 by exam              #+#    #+#             */
/*   Updated: 2017/12/05 13:14:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin.h"
#include <stdio.h>


int	ft_strlen(char *str)
{
	char *strt;

	strt = str;
	while (*str)
		str++;
	return ((int)(str - strt));
}

char	*ft_strdup(char *str, int len)
{
	char	*res;
	int		i;

	i = 0;
	res = (char*)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	main(int argc, char **argv)
{
	char	*buf;
	char	*max_s;
	char	*min_s;
	t_var	v;

	if (argc != 3)
		return (1);
	v.len1 = ft_strlen(argv[1]);
	v.len2 = ft_strlen(argv[2]);
	v.min = (v.len1 > v.len2 ? v.len2 : v.len1) - 1;
	v.max = (v.len1 + v.len2) - (v.min + 2);
	min_s = ft_strdup(v.len1 > v.len2 ? argv[2] : argv[1],
			v.len1 > v.len2 ? v.len2 : v.len1);
	max_s = ft_strdup(v.len1 > v.len2 ? argv[1] : argv[2],
			v.len1 > v.len2 ? v.len1 : v.len2);
	printf("min_s = %s, len = %i\n", min_s, v.min);
	printf("max_s = %s, len = %i\n", max_s, v.max);
	buf = (char*)malloc(sizeof(char) * (v.len1 + v.len2 + 1));
	v.i = 0;
	v.rem = 0;
	while (v.max >= 0)
	{
		if (v.min >= 0)
		{
			if (v.rem == 0)
			{
				v.rem = ((max_s[v.max] + '0') + (min_s[v.min] + 0)) - '0';
				buf[v.i] = v.rem % 10 + '0';
				v.rem /= 10;
			}
			else
			{
				v.rem += ((max_s[v.max] + '0') + (min_s[v.min] + '0')) - '0';
				buf[v.i] = v.rem % 10 + '0';
				v.rem /= 10;
			}
			v.max--;
			v.min--;
			v.i++;
		}
		else
		{
			if (v.rem == 0)
				buf[v.i] = max_s[v.max] + '0';
			else
			{
				v.rem += max_s[v.max] - '0';
				buf[v.i] = v.rem % 10 + '0';
				v.rem /= 10;
			}
			v.max--;
			v.i++;
		}
	}
	buf[v.i] = '\0';
	printf("rev buf: %s\n", buf);
	return (0);
}
