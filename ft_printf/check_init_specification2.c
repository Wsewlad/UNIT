/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init_specification2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:54:10 by vfil              #+#    #+#             */
/*   Updated: 2018/01/15 17:54:16 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_init_modifiers(char *format, int *step, t_spec_elem *spec)
{
	format += *step;
	while (!(is_specifier(*format)))
	{
		if (!(spec->smod))
			spec->smod = ft_strnew(0);
		ft_chrjoin_free(&spec->smod, *format);
		format++;
		(*step)++;
	}
}

