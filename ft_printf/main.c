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

int		main(void)
{
    ft_printf("ft_printf %# 0100.5h-l50.hh+llhjjzzlld %d %s %c %p lol\n", 10, 5,
              "Hello, WORLD!", 'y', "sos");
    //system("leaks a.out");
    //printf("printf %5.10.+-ld %s %d %c\n", 10, "World!", 25, 'p');

    return (0);
}
