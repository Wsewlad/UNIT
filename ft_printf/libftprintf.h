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

# include "Libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef union		u_conversions
{
	unsigned char	c;
	int				d;
	char			*s;
}					t_conversions;

typedef struct		s_flags
{
	int				minus;
	int				plus;
	int				zero;
	int				hash;
	int				space;
}					t_flags;

typedef struct		s_spec_elem
{
	t_flags			flags;
	int				fwidth;
	int				precision;
	char			smod[3];
	char 			cletter;
}					t_spec_elem;

void				ft_printf(const char *restrict format, ...);
int					prntf_parse(char **res, char *format, va_list ap);
int					check_init_specification(char *format, t_spec_elem *spec);
void				init_spec2zero(t_spec_elem *spec);
void				check_init_flags(char *format, int *step, t_spec_elem *spec);
void				check_init_fwidth(char *format, int *step, t_spec_elem *spec);
void				check_init_precision(char *format, int *step, t_spec_elem *spec);
void				check_init_modifiers(char *format, int *step, t_spec_elem *spec);
void				check_init_specifier(char *format, int *step, t_spec_elem *spec);
int					is_specifier(char c);
int					is_flag(char c);
int					is_modifier(char c);

//////	for testing	//////
void 				p(t_spec_elem *spec);

#endif
