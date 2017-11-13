/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_prime_sum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:19:06 by vfil              #+#    #+#             */
/*   Updated: 2017/11/10 12:36:16 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_add_prime_sum(int end)
{
	int	i;
	int j;
	int	is_prime;
	int sum;

	i = 2;
	sum = 0;
	if (!end)
		return (end);
	while (i <= end)
	{
		is_prime = 1;
		j = 2;
		while (j <= i / 2)
		{
			if (i % j == 0)
				is_prime = 0;
			j++;
		}
		if (is_prime == 1)
			sum += i;
		i++;
	}
	return (sum);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_putnbr(ft_add_prime_sum(ft_atoi(argv[1])));
		ft_putchar('\n');
	return (0);
}
