/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:05:45 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/26 16:17:15 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	lowestnumexp(t_node *head)
{
	int		min;
	t_node	*temp;

	min = 2147483647;
	temp = head;
	while (temp != NULL)
	{
		if (min > temp->data && temp->check == 0)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

int	hold_first(t_node *head, int proxi)
{
	t_node	*temp;
	int		index;

	temp = head;
	index = 0;
	while (temp != NULL)
	{
		if (temp->index < proxi)
			return (index);
		temp = temp->next;
		index++;
	}
	return (-1);
}

int	hold_second(t_node *head, int proxi)
{
	t_node	*temp;
	int		index;

	temp = head;
	index = 0;
	while (temp != NULL)
	{
		if (temp->index < proxi)
			index = temp->index;
		temp = temp->next;
	}
	return (index);
}

int	lmove(int holdf, int holds, t_stack *ska)
{
	int	numbf;
	int	numbs;

	numbf = 0;
	numbs = 0;
	if (holdf > (ska->size / 2))
		numbf = ska->size - holdf;
	else
		numbf = holdf - 1;
	if (holds > (ska->size / 2))
		numbs = ska->size - holds;
	else
		numbs = holds - 1;
	if (numbf < numbs)
		return (holdf);
	else
		return (holds);
}

void	indexthenode(t_stack *ska)
{
	int		index;
	int		num;
	int		size;
	t_node	*temp;
	t_node	*temp2;

	index = 0;
	temp = ska->head;
	size = 0;
	temp2 = NULL;
	while (temp != NULL)
	{
		num = lowestnumexp(ska->head);
		size = getindex(ska, num);
		temp2 = nodex(ska, size);
		temp2->check = 1;
		temp2->index = index;
		temp = temp->next;
		index++;
	}
}
