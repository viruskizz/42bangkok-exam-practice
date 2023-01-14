/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:15:28 by tsomsa            #+#    #+#             */
/*   Updated: 2022/07/15 08:39:56 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*lst_new(void *content);
void	lst_addback(t_list *lst,  t_list *new);
int	cmp(int a, int b);

int	main()
{
	int	i = 0;
	int	size = 5;
	int	arr[] = {1, 2, 3, 4, 5};
	t_list		*lst;
	
	lst = lst_new(&arr[i++]);	
	while (i < size)
	{
		t_list	*tmp = lst_new(&arr[i++]);
		lst_addback(lst, tmp);
	}
	printf("%d\n", (*(int *)lst->data));
	printf("%d\n", (*(int *)lst->next->data));
	printf("%d\n", (*(int *)lst->next->next->data));
	return (0);
}

t_list	*lst_new(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	lst->next = NULL;
	lst->data = content;
	return (lst);
}

void	lst_addback(t_list *lst,  t_list *new)
{
	if (!lst)
		lst = new;
	else
	{
		t_list *tmp;
		tmp = lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;	
	}
}

int	cmp(int a, int b)
{
	return (a - b);
}
