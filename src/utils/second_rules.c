/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:15:15 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/08 22:27:07 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrorot(t_stack *ska, t_stack *skb)
{
	rorot(ska, 'r');
	rorot(skb, 'r');
	write(1, "rrr\n", 4);
}

void	sswap(t_stack *ska, t_stack *skb)
{
	swap(ska, 's');
	swap(skb, 's');
	write(1, "ss\n", 3);
}

void	rrot(t_stack *ska, t_stack *skb)
{
	rot(ska, 'r');
	rot(skb, 'r');
	write(1, "rr\n", 3);
}
