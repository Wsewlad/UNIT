/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:04:58 by exam              #+#    #+#             */
/*   Updated: 2017/12/05 10:37:51 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*head;
	t_list	*fixed;
	int		buf;

	head = lst;
	fixed = lst;
	while (head->next)
	{
		lst = fixed;
		while (lst->next)
		{
			if ((*cmp)(lst->data, lst->next->data) == 0)
			{
				buf = lst->data;
				lst->data = lst->next->data;
				lst->next->data = buf;
			}
			lst = lst->next;
		}
		head = head->next;
	}
	return (fixed);
}
