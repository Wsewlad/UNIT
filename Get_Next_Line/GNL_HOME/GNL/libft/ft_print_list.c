/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:38:52 by vfil              #+#    #+#             */
/*   Updated: 2017/11/08 15:18:12 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list *head)
{
	t_list *current;

	current = head;
	while (current != NULL)
	{
		ft_putstr(current->content);
		ft_putchar('\n');
		current = current->next;
	}
}
