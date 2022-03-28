/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:55:43 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/27 19:39:08 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	chankspart(t_stack *ska, t_stack *skb, int div)
{
	int	indpb;
	int	indrb;
	int	index;
	int	middle;

	indpb = ska->size / div;
	indrb = indpb / 2;
	index = 0;
	middle = ska->size / div;
	while (ska->size > 0 && index < div)
	{
		chanks(ska, skb, indpb, indrb);
		indpb += middle;
		indrb += middle;
		index++;
	}
	if (ska->size > 1)
		sorting_tenx(ska, skb);
	pushabeta(ska, skb);
}

void	init(t_stack *ska, t_stack *skb)
{
	indexthenode(ska);
	if (ska->size == 2)
		sorttwnode(ska, 'a');
	else if (ska->size == 3)
		sort_threenode(ska, 'a');
	else if (ska->size <= 10)
		sorting_ten(ska, skb);
	else if (ska->size <= 100)
		chankspart(ska, skb, 5);
	else if (ska->size <= 500)
		chankspart(ska, skb, 9);
}

int	main(int ac, char **av)
{
	t_stack	*ska;
	t_stack	*skb;
	char	**data;

	if (ac > 1)
	{
		data = injectstr(av);
		checknu(data);
		checkmaxd(dtol(data), data);
		ska = malloc(sizeof(t_stack));
		skb = malloc(sizeof(t_stack));
		init_stack(ska);
		init_stack(skb);
		injectnode(ska, data);
		if (is_sorted(ska) == 1)
			init(ska, skb);
	}
	while (1){}
	return (0);
}
