/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:43:08 by vfil              #+#    #+#             */
/*   Updated: 2018/01/12 17:43:10 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	foo(char *fmt, ...)
{
   va_list ap;
   int d;
   char c, *s;

   va_start(ap, fmt);
   while (*fmt)
       switch (*fmt++) {
       case 's':              /* string */
           s = va_arg(ap, char *);
           printf("string %s\n", s);
           break;
       case 'd':              /* int */
           d = va_arg(ap, int);
           printf("int %d\n", d);
           break;
       case 'c':              /* char */
           /* need a cast here since va_arg only
              takes fully promoted types */
           c = (char) va_arg(ap, int);
           printf("char %c\n", c);
           break;
    }
    va_end(ap);
}

int	main(void)
{
	foo("ssc", "Hello!", "10", 'a');
	return (0);
}
