/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:53:05 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/02 19:55:39 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack **stack)
{
	int	temp;

	temp = 0;
	if (*stack)
	{
		temp = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = temp;
	}
}

void	rot(t_stack **stack)
{
	t_stack	*tfrst;
	t_stack	*tlast;

	tfrst = NULL;
	tlast = NULL;
	if (*stack)
	{
		tfrst = *stack;
		tlast = ft_lstlast(*stack);
		*stack = tfrst->next;
		(*stack)->prev = NULL;
		tlast->next = tfrst;
		tfrst->prev = tlast;
		tfrst->next = NULL;
	}
}

void	rotrot(t_stack **stack)
{
	t_stack	*tfrst;
	t_stack	*tlast;

	tfrst = NULL;
	tlast = NULL;
	if (*stack)
	{
		tfrst = ft_lstlast(*stack);
		tlast = tfrst->prev;
		tlast->next = NULL;
		tfrst->prev = NULL;
		tfrst->next = *stack;
		*stack = tfrst;
	}
}
