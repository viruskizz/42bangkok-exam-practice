/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:15:03 by araiva            #+#    #+#             */
/*   Updated: 2022/05/18 19:15:04 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

static void		lst_add_back(t_list *lst, t_list *new);
static t_list	*lst_new(int data);
static t_list	*lst_clone(t_list *lst);
static void		lst_swap(t_list *lst1, t_list *lst2);

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*slist;
	t_list	*ilist;
	t_list	*jlist;

	slist = lst_clone(lst);
	ilist = slist;
	while (ilist->next)
	{
		jlist = ilist->next;
		while (jlist->next)
		{
			if (!cmp(ilist->data, jlist->data))
				lst_swap(ilist, jlist);
			jlist = jlist->next;
		}
		if (!jlist->next)
		{
			if (!cmp(ilist->data, jlist->data))
				lst_swap(ilist, jlist);
		}
		ilist = ilist->next;
	}
	return (slist);
}

static void	lst_swap(t_list *lst1, t_list *lst2)
{
	int	tmp;

	tmp = lst1->data;
	lst1->data = lst2->data;
	lst2->data = tmp;
}

static void	lst_add_back(t_list *lst, t_list *new)
{
	t_list	*tmp;

	if (!lst)
		lst = new;
	else
	{
		tmp = lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static t_list	*lst_new(int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->data = data;
	new->next = NULL;
	return (new);
}

static t_list	*lst_clone(t_list *lst)
{
	t_list	*tmp;
	t_list	*new;
	t_list	*node;

	tmp = lst;
	new = lst_new(tmp->data);
	tmp = tmp->next;
	while (tmp->next)
	{
		node = lst_new(tmp->data);
		lst_add_back(new, node);
		tmp = tmp->next;
		if (!tmp->next)
		{
			node = lst_new(tmp->data);
			lst_add_back(new, node);
		}
	}
	return (new);
}
