/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:50:48 by araiva            #+#    #+#             */
/*   Updated: 2022/05/16 21:50:50 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int ft_list_size(t_list *begin_list);
t_list	*ft_lstnew(void *data);
void	ft_lstadd_back(t_list *list, t_list *nlist);

int main(int argc, char *argv[])
{
	t_list *list;
	t_list *tmp;
	int i;

	if (argc < 2)
		return (0);
	i = 0;
	list = ft_lstnew((void *) argv[i++]);
	while (i < argc)
	{
		tmp = ft_lstnew((void *) argv[i++]);
		ft_lstadd_back(list, tmp);
		i++;
	}
	printf("argc[%d] = lstsize[%d]\n", --argc, ft_list_size(list));
	while (list->next)
	{
		printf("%s\n", (char *) list->data);
		list = list->next;
		if (!list->next)
			printf("%s\n", (char *) list->data);
	}
	return (0);
}

t_list	*ft_lstnew(void *data)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back(t_list *list, t_list *nlist)
{
	t_list *tmp;

	tmp = list;
	if (!list)
		list = nlist;
	else
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = nlist;	
	}
}