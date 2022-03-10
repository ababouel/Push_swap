/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stools.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:46:42 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/10 17:09:25 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	getindex(t_stack *stack, int	number)
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
