/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:19:49 by exam              #+#    #+#             */
/*   Updated: 2017/11/21 13:49:47 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "island.h"

char	u_r_d(char **arr, int i, int j, int *d)
{
	char res;

	res = *d + '0';
	if (arr[i - 1][j] != '.' && arr[i - 1][j] != 'X')
		res = arr[i - 1][j];
	else if (arr[i][j + 1] != '.' && arr[i][j + 1] != 'X')
		res = arr[i][j + 1];
	else if (arr[i + 1][j] != '.' && arr[i + 1][j] != 'X')
		res = arr[i + 1][j];
	if (res == *d + '0')
		(*d)++;
	return (res);
}

char    u_r_d_l(char **arr, int i, int j, int *d)
{
	char res;

	res = *d + '0';
	if (arr[i - 1][j] != '.' && arr[i - 1][j] != 'X')
		res = arr[i - 1][j];
	else if (arr[i][j + 1] != '.' && arr[i][j + 1] != 'X')
		res = arr[i][j + 1];
	else if (arr[i + 1][j] != '.' && arr[i + 1][j] != 'X')
		res = arr[i + 1][j];
	else if (arr[i][j - 1] != '.' && arr[i][j - 1] != 'X')
		res = arr[i][j - 1];
	if (res == *d + '0')
		(*d)++;
	return (res);
}
