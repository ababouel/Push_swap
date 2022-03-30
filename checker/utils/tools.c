/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:11:51 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/30 04:34:33 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	init_stack(t_stack *stack)
{
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
}

int	ins_next_node(t_stack *stack, t_node *node, int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (-1);
	new_node->data = data;
	new_node->index = 0;
	new_node->check = 0;
	if (node == NULL)
	{
		if (stack->size == 0)
			stack->tail = new_node;
		new_node->next = stack->head;
		stack->head = new_node;
	}
	else
	{
		if (node->next == NULL)
			stack->tail = new_node;
		new_node->next = node->next;
		node->next = new_node;
	}
	stack->size++;
	return (0);
}

t_node	*nodex(t_stack *stack, int size)
{
	t_node	*temp;
	int		index;

	if (stack->head == NULL)
		return (0);
	temp = stack->head;
	index = 0;
	while (index++ < size)
		temp = temp->next;
	return (temp);
}

int	lowestnum(t_node *head)
{
	int		min;
	t_node	*temp;

	min = 2147483647;
	temp = head;
	while (temp != NULL)
	{
		if (min > temp->data)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

int	is_sorted(t_stack *stack)
{
	t_node	*temp;

	if (stack->head == NULL)
		return (1);
	temp = NULL;
	temp = stack->head;
	while (temp != NULL)
	{
		if (temp->next == NULL)
			return (0);
		if (temp->data > temp->next->data)
			return (1);
		temp = temp->next;
	}
	return (0);
}
