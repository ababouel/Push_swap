/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:14:53 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/16 19:06:33 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	lowestnumexp(t_node *head)
{
	int		min;
	t_node	*temp;

	min = 2147483647;
	temp = head;
	while (temp != NULL)
	{
		if (min > temp->data && temp->check == 0)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

void	indexthenode(t_stack *ska)
{
	int index;
	int	num;
	int size;
	t_node *temp;
	t_node *temp2;

	index = 0;
	temp = ska->head;
	size = 0;
	temp2 = NULL;
	while (temp != NULL)
	{
		num = lowestnumexp(ska->head);
		size = getindex(ska, num);
		temp2 = nodex(ska,size);
		temp2->check = 1;
		temp2->index = index;
		temp = temp->next;
		index++;
	}
}
