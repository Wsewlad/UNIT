/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:04:19 by exam              #+#    #+#             */
/*   Updated: 2017/11/28 10:32:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int n1;
	int	n2;
	int i;

	if (argc == 3)
	{
		n1 = atoi(argv[1]);
		n2 = atoi(argv[2]);
		i = n1 > n2 ? n1 / 2 : n2 / 2;
		while (i > 0)
		{
			if (n1 % i == 0 && n2 % i == 0)
			{
				printf("%i\n", i);
				return (0);
			}
			i--;
		}
	}
	printf("\n");
	return (0);
}
