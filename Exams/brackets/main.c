/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:45:39 by exam              #+#    #+#             */
/*   Updated: 2017/12/05 11:37:44 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		ft_strlen(char *str)
{
	char	*strt;

	strt = str;
	while (*str)
		str++;
	return ((int)(str - strt));
}

int		check_brackets(char *str)
{
	int		len;
	int		i;
	t_bts	br;

	br.a = "([{";
	br.b = ")]}";
	len = ft_strlen(str);
	i = 0;
	while (i < 3)
	{
		if (str[0] == br.a[i] && str[len - 1] == br.b[i])
			return (1);
		if ((str[0] == br.a[i] && str[len - 1] != br.b[i]) ||
				(str[0] != br.a[i] && str[len - 1] == br.b[i]))
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (check_brackets(argv[i]) == 1)
				ft_putstr("OK");
			else
				ft_putstr("Error");
			ft_putstr("\n");
			i++;
		}
	}
	else
		ft_putstr("\n");
	return (0);
}
