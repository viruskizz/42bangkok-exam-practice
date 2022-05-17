/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:44:19 by araiva            #+#    #+#             */
/*   Updated: 2022/05/16 21:44:20 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*tmp;
	int		len;

	if (!begin_list)
		return (0);
	tmp = begin_list;
	len = 0;
	while (tmp->next)
	{
		len++;
		tmp = tmp->next;
		if (!tmp->next)
			len++;
	}
	return (len);
}
