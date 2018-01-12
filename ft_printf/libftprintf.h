/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:08:22 by vfil              #+#    #+#             */
/*   Updated: 2018/01/12 13:50:30 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

void	ft_printf(const char *restrict format, ...);

typedef union		u_types
{
	unsigned char	c;
	int				d;
	char			*s;
}					t_types;

#endif
