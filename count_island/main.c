/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:13:16 by exam              #+#    #+#             */
/*   Updated: 2017/12/17 19:08:19 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "island.h"

int		main(int argc, char **argv)
{
	char	**arr;
	int		i;

	if (argc != 2 || !(arr = ft_split(argv[1])))
	{
		ft_putchar('\n');
		return (1);
	}
//	arr = ft_check(arr);
	i = 0;
	while (arr[i])
	{
		ft_putstr(arr[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}

char	**ft_check(char **arr)
{
	t_var	var;

	var.i = 0;
	var.d = 0;
	while (arr[var.i] != 0)
	{
		var.j = 0;
		while (arr[var.i][var.j] != '\0')
		{
			
			var.j++;
		}
		var.i++;
	}
	return (arr);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
