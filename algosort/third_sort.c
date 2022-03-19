/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:14:53 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/19 23:02:24 by ababouel         ###   ########.fr       */
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
	int 	index;

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
	int		result;

	temp = head;
	result = 0;
	while (temp != NULL)
	{
		if(temp->index < proxi)
			result++;
		temp = temp->next;
	}
	return (result);
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

int	lmove(int holdf, int holds, t_stack *ska)
{
	int numbf;
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

int	numberdex(int dex, t_node *head)
{
	t_node	*temp;
	int		index;
	
	temp = head;
	index = 0;
	while(index < dex)
	{
		temp = temp->next;
		index++;
	}
	return (temp->index);
}

void	chanks(t_stack *ska, t_stack *skb, int indpb, int indrb)
{
	int	lnum;
	int	holdf;
	int	holds;
	int	keynum;
	int index;

	keynum = 0;
	index = 0;
	while (index < indpb)
	{
		holdf = hold_first(ska->head, indpb);
		if (holdf == -1)
			return ;
		holds = hold_second(ska->head, indpb);
		//keynum = lmove(holdf, holds, ska);
		lnum = numberdex(holdf, ska->head);
		while (ska->head->index != lnum)
		{
			if ((ska->size / 2) > holdf)
				rot(ska, 'a');
			else 
				rorot(ska, 'a');
		}
		pushb(ska, skb);
		if (skb->size >= 1 && skb->head->index < indrb)
		{
			if (ska->head->index > indpb)
				rrot(ska, skb);
			else
				rot(skb, 'b');
		}
		//printf("data\n");
		//printf("datahhf\n");
		index++;
	}
}

void	pushabeta(t_stack *ska, t_stack *skb)
{
	int	index;
	int	bnum;
	int	proxi;

	index = 0;
	bnum = 0;
	proxi = 0;
	while (skb->size > 0)
	{
		bnum = biggestnum(skb->head);
		index = getindexes(skb, bnum);
		proxi = skb->size / 2;
		while (skb->head->index != bnum)
		{
			if (proxi > index)
				rot(skb, 'b');
			else
				rorot(skb, 'b');
		}
		pusha(ska, skb);
	}
}
