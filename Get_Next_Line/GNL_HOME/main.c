/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:41:04 by vfil              #+#    #+#             */
/*   Updated: 2017/12/13 18:50:21 by vfil             ###   ########.fr       */
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
				printf("%s\nreturn (%i)\n", line, j);
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

/*
	char *line;
	int fd;
	int fd2;
	int fd3;
	int	diff_file_size;

    system("mkdir -p sandbox");
	system("openssl rand -base64 $((30 * 1000 * 3/4)) | tr -d '\n' | tr -d '\r' > sandbox/one_big_fat_line.txt");
	system("echo '\n' >> sandbox/one_big_fat_line.txt");

	fd = open("sandbox/one_big_fat_line.txt", O_RDONLY);
	fd2 = open("sandbox/one_big_fat_line.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

	while (get_next_line(fd, &line) == 1)
	{
	    write(fd2, line, strlen(line));
		write(fd2, "\n", 1);
	}
	if (line)
		write(fd2, line, strlen(line));
	close(fd);
	close(fd2);

	system("diff sandbox/one_big_fat_line.txt sandbox/one_big_fat_line.txt.mine > sandbox/one_big_fat_line.diff");
	fd3 = open("sandbox/one_big_fat_line.diff", O_RDONLY);
	diff_file_size = read(fd3, NULL, 10);
	close(fd3);
*/
	return (0);
}
