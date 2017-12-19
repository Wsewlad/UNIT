/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:47:50 by exam              #+#    #+#             */
/*   Updated: 2017/12/05 12:44:55 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	INFIN_H
# define INFIN_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_var
{
	int			len1;
	int			len2;
	int			min;
	int			max;
	int			rem;
	int			i;
}				t_var;

#endif
