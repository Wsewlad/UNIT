/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:04:52 by exam              #+#    #+#             */
/*   Updated: 2017/11/10 14:21:34 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	long int	res;
	long int	len;
	long int	i;

	i = 1;
	res = 0;
	len = 0;
	if (argc > 1 && argv[1])
		res = argc - 1;
	while (res / i > 9)
		i *= 10;
	while (i > 0)
	{
		ft_putchar((res / i) + '0');
		res %= i;
		i /= 10;
	}
	ft_putchar('\n');
	return (0);
}
