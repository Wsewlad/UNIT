/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:13:16 by exam              #+#    #+#             */
/*   Updated: 2017/11/21 13:52:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "island.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	**arr;
	int		i;

	if (argc != 2 || ((fd = open(argv[1], O_RDONLY)) == -1) ||
			!(arr = ft_split(fd)))
	{
		ft_putchar('\n');
		return (1);
	}
	arr = ft_check(arr);
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
			if (var.i == 0 && var.j == 0 && arr[var.i][var.j] == 'X')
				arr[var.i][var.j] = var.d + '0';
			if (var.i != 0 && var.j == 0 && arr[var.i][var.j] == 'X')
				arr[var.i][var.j] = u_r_d(arr, var.i, var.j, &var.d);
			if (var.i != 0 && var.j != 0 &&
					arr[var.i][var.j] == 'X' && arr[var.i][var.j + 1] != '\0')
				arr[var.i][var.j] = u_r_d_l(arr, var.i, var.j, &var.d);
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
