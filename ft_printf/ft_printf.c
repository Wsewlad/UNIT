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

void	prntf_parse()
{

}

void	*ft_strjoin_del(char *s1, char *s2)
{
	char	*new;
	int		i;

	new = NULL;
	i = 0;
	if (s1 && s2)
	{
		if ((new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		{
			while (*s1)
			{
				new[i++] = *s1;
				s1++;
			}
			while (*s2)
			{
				new[i++] = *s2;
				s2++;
			}
			new[i] = '\0';
		}
	}
	ft_strdel(&s1);
	s1 = new;
}

void	ft_chrjoin(char *s1, char s2)
{
	char	*new;
	int		i;

	new = NULL;
	i = 0;
	if (s1 && s2)
	{
		if ((new = ft_strnew(ft_strlen(s1) + 2)))
		{
			while (*s1)
			{
				new[i++] = *s1;
				s1++;
			}
			new[i++] = s2;
			new[i] = '\0';
		}
	}
	ft_strdel(&s1);
	s1 = new;
}

void	ft_printf(const char *restrict format, ...)
{
	va_list ap;
	t_types	type;
	char	*res;
	char	conv[14] = "sSpdDioOuUxXcC";

	res = ft_strnew(0);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 's' && (type.s = va_arg(ap, char *)))
				ft_strjoin_del(res, type.s);
			else if (*format == 'd' && (type.d = va_arg(ap, int)))
				ft_strjoin_del(ft_itoa(type.d));
			else if (*format == 'c' && (type.c = (char)va_arg(ap, int)))
				ft_chrjoin(type.c);
			format++;
		}
		if (*format)
		{
			ft_chrjoin(res, *format);
			format++;
		}
	}
	va_end(ap);
	ft_putstr(res);
}

int	main(void)
{
	ft_printf("Hello %d %s %d %c", 10, "World!", 25, 'p');
	return (0);
}