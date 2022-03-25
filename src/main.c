/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:55:43 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/24 18:49:01 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	injectdata(t_stack *ska, char **str)
{
	int		index;
	t_node	*temp;

	index = 0;
	temp = NULL;
	while (str[index])
	{
		temp = ska->tail;
		ins_next_node(ska, temp, ft_atoi(str[index]));
		//printf("str=>%s\n",str[index]);
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
	char	**data;
	int		*lnu;
	int		indpb;
	int		indrb;
	int		index;
	int		middle;

	if(ac > 1)
	{
		data = injectstr(av);
		checknu(data);
		lnu = dtoi(data);
		checkmaxd(lnu, data);
		ska = malloc(sizeof(t_stack));
		skb = malloc(sizeof(t_stack));
		init_stack(ska);
		init_stack(skb);
		injectdata(ska, data);
		if (is_sorted(ska) == 1){
			indexthenode(ska);
			if (ska->size == 2)
				sorttwnode(ska, 'a');
			else if (ska->size == 3)
				sort_threenode(ska, 'a');
			else if(ska->size <= 10)
				sorting_ten(ska, skb);
			else if(ska->size <= 100)
			{
				indpb = ska->size / 5;
				indrb = indpb / 2;
				index = 0;
				middle = ska->size / 5;
				while (ska->size > 0 && index < 5)
				{
					chanks(ska, skb, indpb, indrb);
					indpb += middle;
					indrb += middle;
					index++;
				}
				if(ska->size > 1)
					sorting_tenx(ska, skb);	
				pushabeta(ska,skb);
			}
			else if(ska->size <= 500)
			{
				indpb = ska->size / 9;
				indrb = indpb / 2;
				index = 0;
				middle = ska->size / 9;
				while (ska->size > 0 && index < 9)
				{
					chanks(ska, skb, indpb, indrb);
					indpb += middle;
					indrb += middle;
					index++;
				}
				sorting_tenx(ska, skb);
				pushabeta(ska,skb);
			}
		}
	}
}
