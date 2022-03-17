/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stools.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:46:42 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/17 17:38:02 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	getindex(t_stack *stack, int number)
{
	int		index;
	t_node	*temp;

	index = 0;
	temp =  stack->head;
	while (temp->data != number)
	{
		temp = temp->next;
		index++;
	}
	return (index);
}

int	getindexes(t_stack *stack, int number)
{
	int		index;
	t_node	*temp;

	index = 0;
	temp = stack->head;
	while (temp->index != number)
	{
		temp = temp->next;
		index++;
	}
	return (index);
}

int	biggestnum(t_node *head)
{
	int		max;
	t_node	*temp;

	max = 0;
	temp = head;
	while (temp != NULL)
	{
		if (max < temp->index)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}
