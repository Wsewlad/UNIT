/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:25:27 by vfil              #+#    #+#             */
/*   Updated: 2017/10/25 19:30:03 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
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
	return (0);
}
