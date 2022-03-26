/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:55:43 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/26 20:08:37 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*ska;
	t_stack *skb;
	char	**data;
	int		indpb;
	int		indrb;
	int		index;
	int		middle;

	if(ac > 1)
	{
		data = injectstr(av);
		checknu(data);
		checkmaxd(dtol(data), data);
		ska = malloc(sizeof(t_stack));
		skb = malloc(sizeof(t_stack));
		init_stack(ska);
		init_stack(skb);
		injectnode(ska, data);
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
				if (ska->size > 1)
					sorting_tenx(ska, skb);
				pushabeta(ska,skb);
			}
		}
	}
}
