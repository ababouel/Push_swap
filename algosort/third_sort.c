/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:14:53 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/16 23:07:46 by ababouel         ###   ########.fr       */
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

int	lowestnu(t_node *head, int proxi)
{
	t_node	*temp;
	int		result;

	temp = head;
	while (temp != NULL)
	{
		if (temp->index < proxi)
			return (temp->index);
		temp = temp->next;
	}
	return (-1);
}

void	indexthenode(t_stack *ska)
{
	int index;
	int	num;
	int size;
	t_node *temp;
	t_node *temp2;

	index = 0;
	temp = ska->head;
	size = 0;
	temp2 = NULL;
	while (temp != NULL)
	{
		num = lowestnumexp(ska->head);
		size = getindex(ska, num);
		temp2 = nodex(ska,size);
		temp2->check = 1;
		temp2->index = index;
		temp = temp->next;
		index++;
	}
}

void	pushbbeta(t_stack *ska, t_stack *skb,int proxi)
{
	int	index;
	int	lnum;
	int	middle;

	index = 0;
	lnum = 0;
	middle = 0;
	printf("data\n");
	while (ska->size > 80)
	{
		lnum = lowestnu(ska->head, proxi);
		if (lnum == -1)
			return ;
		index = getindexes(ska, lnum);
		middle = ska->size / 2;
		while (ska->head->index != lnum)
		{
			if (middle > index)
			{
				if (skb->size == 1)
					rot(ska, 'a');
				else
					rrot(ska, skb);
			}
			else
			{
				if (skb->size == 1)
					rorot(ska, 'a');
				else
					rrorot(ska, skb);
			}
		}
		pushb(ska,skb);
	}
}
