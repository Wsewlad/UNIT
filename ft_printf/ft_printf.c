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

int		is_specifier(char c)
{
	char	*formats;

	formats = "sSpdDioOuUxXcC";
	while (*formats)
	{
		if (c == *formats)
			return (1);
		formats++;
	}
	return (0);
}

int		prntf_parse(char **res, char *format, va_list ap)
{
	t_conversions	spec;
	int				step;

	step = 0;
	while (!(is_specifier(*(format - 1))))
	{
		check_init_flags();
		check_init_fwidth();
		check_init_precision();
		check_init_modifiers();
		/*
		if (*format == 's' && (spec.s = va_arg(ap, char *)))
			*res = ft_strjoin(*res, spec.s);
		else if (*format == 'd' && (spec.d = va_arg(ap, int)))
			*res = ft_strjoin(*res, ft_itoa(spec.d));
		else if (*format == 'c' && (spec.c = (char)va_arg(ap, int)))
			*res = ft_chrjoin(*res, spec.c);*/
		format += step;
		step++;
	}
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
			res = ft_chrjoin(res, *format);
			format++;
		}
	}
	va_end(ap);
	ft_putstr(res);
}

int		main(void)
{
	ft_printf("ft_printf %dd %s %d %c\n", 10, "World!", 25, 'p');
	printf("printf %d %s %d %c\n", 10, "World!", 25, 'p');
	return (0);
}
