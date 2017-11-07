/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:19:20 by vfil              #+#    #+#             */
/*   Updated: 2017/11/06 12:20:27 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t res;

	i = 0;
	j = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	if (dst[i] == '\0')
		res = i + ft_strlen(src);
	else
		res = dstsize + ft_strlen(src);
	i = ft_strlen(dst);
	while (src[j] && dstsize > 0)
	{
		if (i < (dstsize - 1))
			dst[i] = src[j];
		else
			dst[i] = '\0';
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
