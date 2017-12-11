/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:41:04 by vfil              #+#    #+#             */
/*   Updated: 2017/12/10 20:24:41 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		fd[argc - 1]; //for Test 1
//	int		fd[1]; //for Test 2
//	int		fd; //for Test 3
	int		i;
	int 	j;

/*   Test 1 for printing all files alternately  */
	if (argc < 2)
		return (1);
	i = 1;
	j = 0;
	while (i < argc)
		fd[j++] = open(argv[i++], O_RDONLY);
/* __________________________________________ */

/*   Test 2 for printing from the standard output or from a redirection */
/*	if (!argc || !argv)
		return (1);
	fd[0] = 0;
	argc = 2;*/
/* ____________________________________________________________________ */

/*  Test 1 (2) for printing all files alternately  */
	j = 1;
	while (j && j != -1)
	{
		i = 0;
		while (i < argc - 1)
		{
			if ((j = get_next_line(fd[i], &line)))
			{
				printf("%s\nGNL returned %i\n", line, j);
				ft_strdel(&line);
			}
			else
				printf("GNL returned %i\n", j);
			i++;
		}
	}
/* _____________________________________________ */

/* Test 3 for printing all files one after another */
/*	if (argc < 2)
		return (1);
	i = 1;
	while (argv[i])
	{
		if ((fd = open(argv[i], O_RDONLY)))
		{
			j = 1;
			while (j && j != -1)
			{
				if ((j = get_next_line(fd, &line)) && j != -1)
				{
					ft_putstr(line);
					ft_putchar('\n');
				}
				else
				{
					ft_putstr("GNL returned ");
					ft_putnbr(j);
					ft_putchar('\n');
				}
			}
		}
		i++;
	}*/
/* ____________________________________________ */

	return (0);
}
