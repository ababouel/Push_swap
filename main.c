/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:55:43 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/08 20:59:54 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	injectdata(t_stack *ska, char **str)
{
	int		index;
	t_node	*temp;

	index = 1;
	temp = NULL;
	while (str[index])
	{
		temp = ska->tail;
		ins_next_node(ska,temp,atoi(str[index]));
		index++;
	}
}

//#################printing###################//

void	print(t_stack *ska)
{
	t_node *temp;

	temp = ska->head;
	while (temp != NULL)
	{
		printf("-- %d --\n", temp->data);
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*ska;
	t_stack *skb;
	t_node	*tempa;
	t_node	*tempb;

	if(ac > 1)
	{
		ska = malloc(sizeof(t_stack));
		skb = malloc(sizeof(t_stack));
		init_stack(ska);
		init_stack(skb);
		injectdata(ska,av);
		printf("#################printing###################\n");
		printf("stack_a\n");
		print(ska);
		printf("stack_b\n");
		print(skb);
		
		pusha(ska,skb);
		pusha(ska,skb);
		pusha(ska,skb);
		printf("stack_a\n");
		print(ska);
		printf("stack_b\n");
		print(skb);
		rorot(ska, 'a');
		rorot(ska, 'a');
		rorot(ska, 'a');
		printf("stack_a\n");
		print(ska);
		printf("stack_b\n");
		print(skb);

	}
}
