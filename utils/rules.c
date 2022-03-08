/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:26:50 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/08 22:28:38 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pusha(t_stack *stka, t_stack *stkb)
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
	write(1, "pa\n", 3);
	return (0);
}

int	pushb(t_stack *stka, t_stack *stkb)
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
	write(1, "pb\n", 3);
	return (0);
}

int	swap(t_stack *stack, char c)
{
	int	temp;

	temp = 0;
	if (stack->size < 2)
		return (-1);
	temp = stack->head->data;
	stack->head->data = stack->head->next->data;
	stack->head->next->data = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	return (0);
}

int	rorot(t_stack *stack, char c)
{
	t_node	*prevtemp;
	t_node	*temp;

	if (stack->size == 0)
		return (-1);
	prevtemp = nodex(stack, (stack->size - 2));
	prevtemp->next = NULL;
	temp = stack->tail;
	temp->next = stack->head;
	stack->head = temp;
	stack->tail = prevtemp;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	return (0);
}

int	rot(t_stack *stack, char c)
{
	t_node	*temp;
	t_node	*lstemp;

	if (stack->size == 0)
		return (-1);
	temp = stack->head;
	lstemp = stack->tail;
	stack->head = stack->head->next;
	temp->next = NULL;
	lstemp->next = temp;
	stack->tail = temp;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	return (0);
}
