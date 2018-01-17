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

t_conv g_conversion[] = {
		{'s', &convert_str},
		{'S', &convert_str},
		{'p', &test},
		{'d', &convert_int},
		{'D', &convert_int},
		{'i', &convert_int},
		{'o', &test},
		{'O', &test},
		{'u', &test},
		{'U', &test},
		{'x', &test},
		{'X', &test},
		{'c', &convert_chr},
		{'C', &convert_chr}
};

int		prntf_parse(char **res, char *format, va_list ap)
{
	//t_conversions	cl;
	t_spec_elem		spec;
	int				step;
	int 			i;
	//char 			*buf;

	step = check_init_specification(format, &spec);
	i = 0;
	while (i < 14)
	{
		if (g_conversion[i].letter == spec.cletter)
			g_conversion[i].make(res, spec.smod, ap);
		i++;
	}
	/*if (spec.cletter == 's' && (cl.s = va_arg(ap, char *)))
		ft_strjoin_free(res, cl.s);
	else if (spec.cletter == 'd' && (cl.d = va_arg(ap, int)))
	{
		ft_strjoin_free(res,buf = ft_itoa(cl.d));
		ft_strdel(&buf);
	}
	else if (spec.cletter == 'c' && (cl.c = (char)va_arg(ap, int)))
		ft_chrjoin_free(res, cl.c);*/
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
	ft_putstr(res);
	ft_strdel(&res);
}

