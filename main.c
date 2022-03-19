/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:55:43 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/19 20:24:09 by ababouel         ###   ########.fr       */
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

void	print(t_stack *ska)
{
	t_node *temp;

	temp = ska->head;
	while (temp != NULL)
	{
		printf("-- %d --/-- %d --\n", temp->data, temp->index);
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*ska;
	t_stack *skb;
	t_node	*tempa;
	t_node	*tempb;
	int		indpb;
	int		indrb;

	if(ac > 1)
	{
		indpb = 5;
		indrb = 3;
		ska = malloc(sizeof(t_stack));
		skb = malloc(sizeof(t_stack));
		init_stack(ska);
		init_stack(skb);
		injectdata(ska,av);
		if (is_sorted(ska) == 1){
			indexthenode(ska);
			if (ska->size == 2)
				sorttwnode(ska, 'a');
			else if (ska->size == 3)
				sort_threenode(ska, 'a');
			else if(ska->size <= 10)
				sorting_ten(ska, skb);
			else if(ska->size > 10 && ska->size <= 100)
			{
				while(ska->size > 0)
				{
					chanks(ska, skb, indpb, indrb);
					indpb += 5;
					indrb += 5;
					printf("indepb=>%d\n",indpb);
					printf("inderb=>%d\n",indrb);
				}
				pushabeta(ska,skb);
			}
			else if(ska->size > 100 && ska->size <= 500)
			{
			}
		}
		/*printf("stack_a\n");
		print(ska);
		printf("stack_b\n");
		print(skb);*/
	}
}
