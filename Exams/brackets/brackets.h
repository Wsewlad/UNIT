/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:43:13 by exam              #+#    #+#             */
/*   Updated: 2017/12/05 11:31:02 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRACKETS_H
# define BRACKETS_H

# include <unistd.h>

typedef struct	s_bts
{
	char		*a;
	char		*b;
}				t_bts;

void			ft_putstr(char	*str);
int				ft_strlen(char *str);
int				check_brackets(char *str);

#endif
