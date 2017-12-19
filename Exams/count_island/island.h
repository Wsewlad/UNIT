/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   island.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:16:53 by exam              #+#    #+#             */
/*   Updated: 2017/12/17 18:41:29 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISLAND_H
# define ISLAND_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_count
{
	int			count;
	int			len;
}				t_count;

typedef struct	s_var
{
	int			i;
	int			j;
	int			k;
	int			d;
}				t_var;

void			ft_putchar(char c);
void			ft_putstr(char *str);
char			**ft_split();
char			*ft_read(char *fname);
void			ft_strncpy(char *dst, char *src, int n);
t_count			ft_count_len(char *str);
char			**ft_check(char **arr);
char			check_neighbour(char **arr, int i, int j, int *d);

#endif
