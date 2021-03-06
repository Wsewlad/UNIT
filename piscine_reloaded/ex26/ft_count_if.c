/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 13:23:22 by vfil              #+#    #+#             */
/*   Updated: 2017/10/25 13:30:15 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	counter;
	int i;

	i = 0;
	counter = 0;
	while (tab[i] != '\0')
	{
		if (f(tab[i]) == 1)
			counter++;
		i++;
	}
	return (counter);
}
