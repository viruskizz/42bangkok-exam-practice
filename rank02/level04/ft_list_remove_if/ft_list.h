/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:10:59 by tsomsa            #+#    #+#             */
/*   Updated: 2022/07/15 08:08:57 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int(*cmp)());

#endif

