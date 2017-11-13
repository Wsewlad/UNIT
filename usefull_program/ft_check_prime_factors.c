/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_prime_factors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:48:11 by vfil              #+#    #+#             */
/*   Updated: 2017/11/10 13:43:28 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_prime_factors(int num)
{
	int i;
	int j;
	int is_prime;

	if (num)
	{
		i = 2;
		while (i < num)
		{
			if (num % i == 0)
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
				{
					ft_putnbr(i);
					ft_putchar('\n');
				}
			}
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		ft_check_prime_factors(ft_atoi(argv[1]));
	return (0);
}
