/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:42:46 by vfil              #+#    #+#             */
/*   Updated: 2018/01/12 17:42:50 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		prntf_parse(char **res, char *format, va_list ap)
{
	t_conversions	cl;
	t_spec_elem		spec;
	int				step;

	step = 0;
	step = check_init_specification(format, &spec);
	printf("minus: %d plus: %d zero: %d hash: %d space: %d fwidth: %d precision: %d smod: %s", spec.flags.minus, spec.flags.plus, spec.flags.zero,
		   spec.flags.hash, spec.flags.space, spec.fwidth, spec.precision, spec.smod);
	/*while (!(is_specifier(*(format - 1))))
	{*/
		//step = check_init_specification();
		/*
		if (*format == 's' && (cl.s = va_arg(ap, char *)))
			*res = ft_strjoin(*res, cl.s);
		else if (*format == 'd' && (cl.d = va_arg(ap, int)))
			*res = ft_strjoin(*res, ft_itoa(l.d));
		else if (*format == 'c' && (cl.c = (char)va_arg(ap, int)))
			*res = ft_chrjoin(*res, cl.c);*/
		/*format += step;
		step++;
	}*/
	ft_strdel(&spec.smod);
	return (step);
}

void	ft_printf(const char *restrict format, ...)
{
	va_list ap;
	char	*res;
	int		step;

	step = 0;
	res = ft_strnew(0);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			step = prntf_parse(&res, (char*)format, ap);
			format += step;
		}
		if (*format)
		{
			ft_chrjoin_free(&res, *format);
			format++;
		}
	}
	va_end(ap);
	//system("leaks a.out");
	ft_putstr(res);
	ft_strdel(&res);
}

int		main(void)
{
	ft_printf("ft_printf %-+ #500.70lld\n", 10);
	//printf("printf %d %s %d %c\n", 10, "World!", 25, 'p');

	return (0);
}