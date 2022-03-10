/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:37:01 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/10 16:36:57 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	faction(t_stack *stack, char c)
{
	swap(stack, c);
	rorot(stack, c);
}

static void	saction(t_stack *stack, char c)
{
	swap(stack, c);
	rot(stack, c);
}

void	sorttwnode(t_stack *stack, char c)
{
	if (stack->head->data > stack->head->next->data)
		swap(stack, c);
}

int	sort_threenode(t_stack *stack, char c)
{
	int	temph;
	int	tempt;
	int	next;

	if (stack == NULL)
		return (-1);
	next = 0;
	temph = stack->head->data;
	tempt = stack->tail->data;
	next = stack->head->next->data;
	if (next > tempt && next < temph && temph > tempt)
		faction(stack, c);
	else if (next > tempt && next > temph && temph < tempt)
		saction(stack, c);
	else if (next < tempt && next < temph && temph > tempt)
		rot(stack, c);
	else if (next > tempt && next > temph && temph > tempt)
		rorot(stack, c);
	else if (next < tempt && next < temph && temph < tempt)
		swap(stack, c);
	return (0);
}
