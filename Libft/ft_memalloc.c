/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:07:38 by vfil              #+#    #+#             */
/*   Updated: 2017/11/03 15:45:40 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	new = NULL;
	new = malloc(size);
	if (new != NULL)
		ft_bzero(new, size);
	return (new);
}
