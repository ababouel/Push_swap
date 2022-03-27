/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:14:53 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/27 20:12:44 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	numberdex(int dex, t_node *head)
{
	t_node	*temp;
	int		index;

	temp = head;
	index = 0;
	while (index < dex)
	{
		temp = temp->next;
		index++;
	}
	return (temp->index);
}

void	parts(t_stack *ska, t_stack *skb, int indrb, int indpb)
{
	if (ska->size > 0)
		pushb(ska, skb);
	if (skb->size > 1 && skb->head->index < indrb)
	{
		if (ska->head != 0x0
			&& ska->head->index > indpb
			&& ska->size > 1)
			rrot(ska, skb);
		else
			rot(skb, 'b');
	}
}

void	condition(t_stack *ska, t_stack *skb, int indpb, int indrb)
{
	if (skb->size > 1
		&& skb->head->index < indrb
		&& ska->head->index > indpb
		&& ska->size > 1)
		rrot(ska, skb);
	else
		rot(ska, 'a');
}

void	chanks(t_stack *ska, t_stack *skb, int indpb, int indrb)
{
	int	lnum;
	int	holdf;
	int	index;

	index = 0;
	while (index < indpb && ska->size > 0)
	{
		holdf = hold_first(ska->head, indpb);
		if (holdf == -1)
			return ;
		lnum = numberdex(holdf, ska->head);
		while (ska->head->index != lnum)
		{
			if ((ska->size / 2) > holdf)
				condition(ska, skb, indpb, indrb);
			else
				rorot(ska, 'a');
		}
		parts(ska, skb, indrb, indpb);
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
