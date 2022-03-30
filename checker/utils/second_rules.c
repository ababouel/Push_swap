/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:15:15 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/30 02:05:54 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	rrorot(t_stack *ska, t_stack *skb)
{
	rorot(ska);
	rorot(skb);
}

void	sswap(t_stack *ska, t_stack *skb)
{
	swap(ska);
	swap(skb);
}

void	rrot(t_stack *ska, t_stack *skb)
{
	rot(ska);
	rot(skb);
}
