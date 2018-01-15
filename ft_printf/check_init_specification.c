/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init_specification.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:45:32 by vfil              #+#    #+#             */
/*   Updated: 2018/01/15 12:45:36 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		check_init_specification(char *format, t_spec_elem *spec)
{
	int	step;

	step = 0;
	init_spec2zero(spec);
	check_init_flags(format, &step, spec);
	check_init_fwidth(format, &step, spec);
	check_init_precision(format, &step, spec);
	check_init_modifiers(format, &step, spec);
	return (step);
}

void 	init_spec2zero(t_spec_elem *spec)
{
	spec->flags.minus = 0;
	spec->flags.plus = 0;
	spec->flags.zero = 0;
	spec->flags.hash = 0;
	spec->flags.space = 0;
	spec->fwidth = 0;
	spec->precision = -1;
	spec->smod = NULL;
}

void	check_init_flags(char *format, int *step, t_spec_elem *spec)
{
	format += *step;
	while (is_flag(*format))
	{
		if (*format == '-')
			spec->flags.minus = 1;
		if (*format == '+')
			spec->flags.plus = 1;
		if (*format == '0')
			spec->flags.zero = 1;
		if (*format == '#')
			spec->flags.hash = 1;
		if (*format == ' ')
			spec->flags.space = 1;
		format++;
		(*step)++;
	}
}

void	check_init_fwidth(char *format, int *step, t_spec_elem *spec)
{
	format += *step;
	spec->fwidth = ft_atoi(format);
	if (spec->fwidth)
	{
		while (*format >= '0' && *format <= '9')
		{
			format++;
			(*step)++;
		}
	}
}

void	check_init_precision(char *format, int *step, t_spec_elem *spec)
{
	format += *step;
	if (*format == '.')
	{
		format++;
		(*step)++;
		spec->precision = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
		{
			format++;
			(*step)++;
		}
	}
}
