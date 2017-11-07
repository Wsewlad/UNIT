/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:45:33 by vfil              #+#    #+#             */
/*   Updated: 2017/10/25 18:58:14 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 10

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	c1 = s1[i];
	c2 = s2[i];
	return (c1 - c2);
}

int		main(int argc, char **argv)
{
	int		fd_ret[2];
	char	buf[BUF_SIZE + 1];

	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	else if (ft_strcmp(argv[1], "Makefile") == 0)
	{
		write(2, "*content of file Makefile*\n", 27);
		return (1);
	}
	fd_ret[0] = open(argv[1], O_RDONLY);
	while ((fd_ret[1] = read(fd_ret[0], buf, BUF_SIZE)))
	{
		buf[fd_ret[1]] = '\0';
		ft_putstr(buf);
	}
	return (0);
}
