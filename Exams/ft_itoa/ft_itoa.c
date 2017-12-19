/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:25:09 by exam              #+#    #+#             */
/*   Updated: 2017/11/10 15:12:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*filit(long int ln, long int i, int len, int is_neg)
{
	char	*res;

	res = (char*)malloc(sizeof(char) * (len + is_neg + 1));
	if (is_neg == 1)
		*res++ = '-';
	while (i > 0)
	{
		*res = ln / i + '0';
		ln %= i;
		i /= 10;
		res++;
	}
	*res = '\0';
	return (res - (len + is_neg + 1));
}

char	*ft_itoa(int nbr)
{
	long int	i;
	long int	ln;
	int			is_neg;
	int			len;

	ln = nbr;
	i = 1;
	is_neg = 0;
	len = 0;
	if (ln < 0)
		is_neg = 1;
	ln = is_neg ? -ln : ln;
	while (ln / i > 9)
	{
		i *= 10;
		len++;
	}
	return (filit(ln, i, len, is_neg));
}
