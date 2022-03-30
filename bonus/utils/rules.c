/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:26:50 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/30 05:10:15 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	pushb(t_stack *stka, t_stack *stkb)
{
	t_node	*temp;

	temp = NULL;
	if (stka->size == 0)
		return (-1);
	temp = stka->head;
	stka->head = stka->head->next;
	if (stka->size == 1)
		stka->tail = NULL;
	if (stkb->size == 0)
	{
		temp->next = NULL;
		stkb->tail = temp;
		stkb->head = temp;
	}
	else
	{
		temp->next = stkb->head;
		stkb->head = temp;
	}
	stkb->size++;
	stka->size--;
	return (0);
}

int	pusha(t_stack *stka, t_stack *stkb)
{
	t_node	*temp;

	temp = NULL;
	if (stkb->size == 0)
		return (-1);
	temp = stkb->head;
	stkb->head = stkb->head->next;
	if (stkb->size == 1)
		stkb->tail = NULL;
	if (stka->size == 0)
	{
		temp->next = NULL;
		stka->tail = temp;
		stka->head = temp;
	}
	else
	{
		temp->next = stka->head;
		stka->head = temp;
	}
	stkb->size--;
	stka->size++;
	return (0);
}

int	swap(t_stack *stack)
{
	int	temp;

	temp = 0;
	if (stack->size < 2)
		return (-1);
	temp = stack->head->data;
	stack->head->data = stack->head->next->data;
	stack->head->next->data = temp;
	temp = stack->head->index;
	stack->head->index = stack->head->next->index;
	stack->head->next->index = temp;
	return (0);
}

int	rorot(t_stack *stack)
{
	t_node	*prevtemp;
	t_node	*temp;

	if (stack->size == 0)
		return (-1);
	if (stack->size > 1)
	{
		prevtemp = nodex(stack, (stack->size - 2));
		prevtemp->next = NULL;
		temp = stack->tail;
		temp->next = stack->head;
		stack->head = temp;
		stack->tail = prevtemp;
	}
	return (0);
}

int	rot(t_stack *stack)
{
	t_node	*temp;
	t_node	*lstemp;

	if (stack->size == 0)
		return (-1);
	if (stack->size > 1)
	{
		temp = stack->head;
		lstemp = stack->tail;
		stack->head = stack->head->next;
		temp->next = NULL;
		lstemp->next = temp;
		stack->tail = temp;
	}
	return (0);
}
