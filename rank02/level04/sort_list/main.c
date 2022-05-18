/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:48:57 by araiva            #+#    #+#             */
/*   Updated: 2022/05/17 18:48:59 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

t_list	*lst_new(int data);
t_list	lst_add_back(t_list *lst, t_list *new);
void	print_list(t_list *lst);
int		ascending(int a, int b);
t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

int main(int argc, char *argv[])
{
	int nbs[] = {7, 5, 10, 4, 2};
	int i = 0;
	int size = 5;
	t_list *lst = lst_new(nbs[i++]);
	while (i < size)
	{
		t_list *tmp = lst_new(nbs[i++]);
		lst_add_back(lst, tmp);
	}
	print_list(lst);
	t_list *slst = sort_list(lst, ascending);
	printf("SORTED\n");
	print_list(slst);
	return (0);
}

int ascending(int a, int b)
{
	return (a <= b);
}

t_list    *lst_new(int data)
{
	t_list *lst;
	
	lst = malloc(sizeof(t_list));
	if (!lst)
		return NULL;
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

t_list lst_add_back(t_list *lst, t_list *new)
{
	if (!lst)
		lst = new;
	else
	{
		t_list *tmp;
		tmp = lst;
		while(tmp->next)
			tmp = tmp->next;
	   tmp->next = new; 
	}
}

void    print_list(t_list *lst)
{
	t_list *tmp = lst;
	while (tmp->next)
	{
		printf("%d, ", tmp->data);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->data);
}