/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:46:50 by exam              #+#    #+#             */
/*   Updated: 2017/10/24 12:41:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_alpha(char c)
{
	int i;

	i = 0;
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		i = 1;
	return (i);
}

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	int	i;
	int j;

	i = 0;
	if (argc > 1)
		while (argv[i++] != '\0')
		{
			j = -1;
			while (argv[i][++j] != '\0')
			{
				if (is_alpha(argv[i][j]))
				{
					if (j == 0 || argv[i][j - 1] == ' ' ||
							argv[i][j - 1] == '\t')
						argv[i][j] = to_upper(argv[i][j]);
					else
						argv[i][j] = to_lower(argv[i][j]);
				}
			}
			write(1, argv[i], ft_strlen(argv[i]));
			write(1, "\n", 1);
		}
	else
		write(1, "\n", 1);
	return (0);
}
