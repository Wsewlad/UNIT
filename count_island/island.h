/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   island.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:16:53 by exam              #+#    #+#             */
/*   Updated: 2017/11/21 13:50:06 by exam             ###   ########.fr       */
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
char			**ft_split(int fd);
char			*ft_read(int fd);
void			ft_strncpy(char *dst, char *src, int n);
t_count			ft_count_len(char *str);
char			**ft_check(char **arr);
char			u_r_d(char **arr, int i, int j, int *d);
char            u_r_d_l(char **arr, int i, int j, int *d);

# define BUF_SIZE 10240

#endif
