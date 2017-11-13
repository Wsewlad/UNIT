/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:51:50 by vfil              #+#    #+#             */
/*   Updated: 2017/10/25 18:09:48 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_sqrt(int nb)
{
	int i;
	int end;

	i = 0;
	end = nb / 3 + 1;
	while (i <= end)
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
    return	(0);
}

int		main(void)
{
	int bn;

	scanf("%i", &bn);
	printf("%i\n", ft_sqrt(bn));
	return (0);
}
