/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:25:27 by vfil              #+#    #+#             */
/*   Updated: 2017/10/25 18:24:46 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_helper(int nb, int min, int max)
{
	int	mid;

	mid = 0;
	if (max < min)
		return (0);
	if ((mid * mid) == nb)
		return (mid);
	else
		mid = (min + max) / 2;
	if ((mid * mid) < nb)
		return (ft_sqrt_helper(nb, mid + 1, max));
	if ((mid * mid) > nb)
		return (ft_sqrt_helper(nb, min, mid - 1));
	return (mid);
}

int	ft_sqrt(int nb)
{
	return (ft_sqrt_helper(nb, 0, nb));
}
