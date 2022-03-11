/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:00:13 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/11 18:42:47 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sorting_ten(t_stack *ska, t_stack *skb)
{
	int	index;
	int	lnum;
	int	proxi;

	index = 0;
	lnum = 0;
	proxi = 0;
	while (ska->size > 3)
	{
		lnum = lowestnum(ska->head);
		index = getindex(ska, lnum);
		proxi = ska->size / 2;
		while (ska->head->data != lnum)
		{
			if (proxi > index)
				rot(ska, 'a');
			else
				rorot(ska, 'a');
		}
		pushb(ska, skb);
	}
	sort_threenode(ska, 'a');
	while (skb->size > 0)
		pusha(ska, skb);
}
