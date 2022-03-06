/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:53:05 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/06 16:05:05 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack **stack,char c)
{
	int	temp;

	temp = 0;
	if (*stack)
	{
		temp = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = temp;
		if (c == 'a')
			write(1, "sa\n", 3);
		else if (c == 'b')
			write(1,"sb\n",3);
	}
}

void	rot(t_stack **stack,char c)
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
		if (c == 'a')
			write(1, "ra\n", 3);
		else if (c == 'b')
			write(1,"rb\n",3);
	}
}

void	rotrot(t_stack **stack,char c)
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
		if (c == 'a')
			write(1, "rra\n", 4);
		else if (c == 'b')
			write(1,"rrb\n",4);
	}
}

void	push_a(t_stack **ska, t_stack **skb)
{
	t_stack	*temp;

	temp = NULL;
	if (*ska)
	{
		temp = *ska;
		*ska = (*ska)->next;
		ft_lstadd_front(skb, temp);
	}
}

void	push_b(t_stack **ska, t_stack **skb)
{
	t_stack	*temp;

	temp = NULL;
	if (*skb)
	{
		temp = *skb;
		*skb = (*skb)->next;
		ft_lstadd_front(ska, temp);
	}
}
