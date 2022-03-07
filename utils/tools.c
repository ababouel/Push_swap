/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:11:51 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/07 18:34:36 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->size = 0;
	stack->head = NULL;
	stack->index = 0;
}

int	ins_next_node(t_stack *stack, t_node *node, int data)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (-1);
	new_node->data = data;
	if (stack->size == 0)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		stack->head = new_node;
	}
	else
	{
		new_node->next = node->next;
		node->next = new_node;
		new_node->prev = node;
		head->prev = new_node;
	}
	stack->size++;
	return (0);
}

int	ins_node(t_stack *stack, t_node *node)
{

}

int	pusha(t_stack *stka, t_stack *stkb)
{
	t_stack *temp;
	t_stack *tmev;

	if (stcka->size)
		return (-1);
	temp = head;
	tmev = head->prev;
	head = head->next;
	head->prev = tmev;

}
