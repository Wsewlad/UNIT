/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:41:04 by vfil              #+#    #+#             */
/*   Updated: 2017/12/04 19:55:37 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;
	int 	j;

	if (argc < 2)
		return (1);
	i = 1;
	while (argv[i])
	{
		if ((fd = open(argv[i], O_RDONLY)))
		{
			j = 1;
			while (j && j != -1)
			{
				if ((j = get_next_line(fd, &line)))
				{
					ft_putstr(line);
					ft_putchar('\n');
				}
				else
					ft_putnbr(j);
			}
		}
		i++;
	}
	return (0);
}
