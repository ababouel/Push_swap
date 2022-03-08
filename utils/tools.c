/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:11:51 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/08 20:59:51 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
