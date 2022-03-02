/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:50:12 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/02 19:52:28 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
	}
	return (temp);
}

t_stack	*ft_lstnew(int data)
{
	t_stack	*lst;

	lst = malloc(sizeof(t_stack));
	if (!lst)
		return (0);
	lst->data = data;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	t_stack	*temp;
	int		size;

	temp = lst;
	size = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

void	ft_add_back(t_stack **alst, t_stack *new)
{
	t_stack	*temp;
	int		size;

	if (*alst == NULL)
		*alst = new;
	else
	{
		temp = *alst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}
