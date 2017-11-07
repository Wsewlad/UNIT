/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:16:09 by vfil              #+#    #+#             */
/*   Updated: 2017/11/03 17:01:48 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i] == needle[j] && needle[j] && i < len)
		{
			i++;
			j++;
		}
		if (!needle[j])
			return ((char*)&haystack[i - j]);
		else if (j > 0)
			i--;
		i++;
	}
	return (NULL);
}
