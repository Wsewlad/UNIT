/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:30:01 by exam              #+#    #+#             */
/*   Updated: 2017/11/10 17:01:59 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list t_list;

struct		s_list
{
	char	c;
	t_list	*next;
};

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

t_list	*ft_lstadd(t_list **head, char c)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	new->c = c;
	new->next = *head;
	*head = new;

	return (*head);
}

void	ft_print_list(t_list *list)
{
	char	c;

	while (list)
	{
		c = list->c;
		write(1, &c, 1);
		list = list->next;
	}
}

int	main(int argc, char **argv)
{
	char	c;
	int		i;
	int		j;
	int		k;
	t_list	*list;
	int		is_ok;

	list = NULL;
	if (argc == 2)
		ft_putstr(argv[1]);
	if (argc > 1 && argc != 2)
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			c = argv[1][i];
			is_ok = 1;
			j = 2;
			while (argv[j] != '\0')
			{
				k = 0;
				while (argv[j][k] != c || argv[j][k] != '\0')
					k++;
				if (argv[j][k] != c)
				{
					j = argc - 1;
					is_ok = 0;
				}
				j++;
			}
			if (is_ok)
				list = ft_lstadd(&list, c);
			i++;
		}
		if (is_ok)
			ft_print_list(list);
	}
	ft_putstr("\n");
	return (0);
}
