/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 10:33:28 by exam              #+#    #+#             */
/*   Updated: 2017/10/24 11:40:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;
	int j;
	
	i = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			while (argv[1][i] != argv[2][j])
			{
				if (argv[1][i] != '\0' && argv[2][j] == '\0')
				{
					write(1, "\n", 1);
					return (0);
				}
				j++;
			}
			i++;
		}
		write(1, argv[1], ft_strlen(argv[1]));
	}
	write(1, "\n", 1);
	return (0);
}
