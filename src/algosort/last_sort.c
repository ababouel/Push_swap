/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:18:34 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/26 23:34:37 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	chanklast(t_stack *ska, t_stack *skb, int indpb, int indrb)
{
	int	lnum;
	int	holdf;
	int	sindex;
	int	holds;
	int	keynum;
	int	index;

	index = 0;
	sindex = 0;

	while (index < indpb && ska->size > 0)
	{
		holdf = hold_first(ska->head, indpb);
		if(holdf == -1)
			return ;
		sindex = hold_second(ska->head, indpb);
		if(sindex == -1)
			return ;
		holds = getindexes(ska, sindex);
		keynum = lmove(holdf, holds, ska);
		lnum = numberdex(keynum, ska->head);
		while (ska->head->index != lnum)
		{
			if ((ska->size / 2) > keynum)
			{
				if (skb->size > 1
					&& skb->head->index < indrb
					&& ska->head->index > indpb
					&& ska->size > 1)
					rrot(ska, skb);
				else
					rot(ska, 'a');
			}
			else
				rorot(ska, 'a');
		}
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
		index++;
	}
}
