/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:55:43 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/17 18:10:17 by ababouel         ###   ########.fr       */
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
	int		init;
	int		proxi;
	int		proxit;

	if(ac > 1)
	{
		init = 0;
		proxi = 0;
		proxit = 0;
		ska = malloc(sizeof(t_stack));
		skb = malloc(sizeof(t_stack));
		init_stack(ska);
		init_stack(skb);
		injectdata(ska,av);
		if (is_sorted(ska) == 1){
			if (ska->size == 2)
				sorttwnode(ska, 'a');
			else if (ska->size == 3)
				sort_threenode(ska, 'a');
			else if(ska->size <= 10)
				sorting_ten(ska, skb);
			else if(ska->size > 10 && ska->size <= 100)
			{
				proxi = ska->size / 5;
				proxit = ska->size / 5;
				indexthenode(ska);
				while (ska->size > 0)
				{
					pushbbeta(ska, skb, proxi, init);
					init = proxi;
					proxi += proxit;
				}
				pushabeta(ska, skb);
			}
			else if(ska->size > 100 && ska->size <= 500)
			{
				proxi = ska->size / 11;
				proxit = ska->size / 11;
				indexthenode(ska);
				while (ska->size > 0)
				{
					pushbbeta(ska, skb, proxi, init);
					init = proxi;
					proxi += proxit;
				}
				pushabeta(ska, skb);
			}
		}
		/*printf("stack_a\n");
		print(ska);
		printf("stack_b\n");
		print(skb);*/
	}
}
