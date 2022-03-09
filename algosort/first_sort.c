/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:37:01 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/09 18:32:47 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_threenode(t_stack *stack, char c)
{
	t_node	*temph;
	t_node	*tempt;
	int		next;

	if (stack == NULL)
		return (-1);
	next = 0;
	temph = stack->head;
	tempt = stack->tail;
	next = stack->head->next->data;
	if (next > tempt->data
			&& next < temph->data
			&& temph->data > tempt->data)
	{
		swap(stack, c);
		rorot(stack, c);
	}
	else if (next > tempt->data
			&& next > temph->data
			&& temph->data < tempt->data)
	{
		swap(stack, c);
		rot(stack, c);
	}
	else if (next < tempt->data
			&& next < temph->data
			&& temph->data > tempt->data)
		rot(stack, c);
	else if (next > tempt->data
			&& next > temph->data
			&& temph->data > tempt->data)
		rorot(stack, c);
	else if (next < tempt->data
			&& next < temph->data
			&& temph->data < tempt->data)
		swap(stack, c);
	return (0);
}
