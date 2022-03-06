/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:42:27 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/06 19:46:01 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	print(int nb)
{
	printf("= %d =\n",nb);
}

void	ft_lstiter(t_stack *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst->data);
		lst = lst->next;
	}
}

void	sorting(t_stack **stack, char c)
{
		
		if ((*stack)->data > (*stack)->next->data 
				&& (*stack)->next->data < (*stack)->next->next->data 
				&& (*stack)->data < (*stack)->next->next->data)
			swap(stack, c);
		else if ((*stack)->data > (*stack)->next->data
				&& (*stack)->next->data > (*stack)->next->next->data
				&& (*stack)->data < (*stack)->next->next->data)
		{
			rotrot(stack, c);
			swap(stack, c);
		}
		else if ((*stack)->data > (*stack)->next->data
				&& (*stack)->next->data < (*stack)->next->next->data
				&& (*stack)->data > (*stack)->next->next->data)
			rot(stack, c);
		else if ((*stack)->data < (*stack)->next->data
				&& (*stack)->next->data > (*stack)->next->next->data
				&& (*stack)->data < (*stack)->next->next->data)
		{
			swap(stack, c);
			rot(stack, c);
		}
		else if ((*stack)->data < (*stack)->next->data
				&& (*stack)->next->data > (*stack)->next->next->data
				&& (*stack)->data > (*stack)->next->next->data)
			rotrot(stack, c);
}

void	ft_insertnode(t_stack **skt, int data)
{
	t_stack	*node;

	node = NULL;
	node = ft_lstnew(data);
	ft_add_back(skt, node);
}

void	parsing(t_stack **ska, char **str)
{
	int	x;

	x = 1;
	while(str[x])
	{
		ft_insertnode(ska, atoi(str[x]));
		x++;
	}
}

int	main(int ac, char** av)
{
	t_stack *ska = NULL;
	t_stack *skb = NULL;
	int		x;
	int		y;

	if (ac > 1)
	{
		parsing(&ska, av);
		printf("<====================data======================>\n");
		printf("<===stack_a===>\n");
		ft_lstiter(ska,print);
		printf("<===stack_b===>\n");
		ft_lstiter(skb,print);
		sorting(&ska,'a');
		printf("<====================data======================>\n");
		printf("<===stack_a===>\n");
		ft_lstiter(ska,print);
		printf("<===stack_b===>\n");
		ft_lstiter(skb,print);
	}
}
