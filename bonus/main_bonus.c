/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:05:38 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/30 16:14:39 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

void	error(t_stack *ska, t_stack *skb)
{
	write(2, "Error\n", 6);
	ft_freestack(ska);
	ft_freestack(skb);
	exit(6);
}

void	instruction(t_stack *ska, t_stack *skb, char *line)
{
	if (ft_strcmp(line, "pb\n") == 0)
		pushb(ska, skb);
	else if (ft_strcmp(line, "pa\n") == 0)
		pusha(ska, skb);
	else if (ft_strcmp(line, "rb\n") == 0)
		rot(skb);
	else if (ft_strcmp(line, "ra\n") == 0)
		rot(ska);
	else if (ft_strcmp(line, "rra\n") == 0)
		rorot(ska);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rorot(skb);
	else if (ft_strcmp(line, "rr\n") == 0)
		rrot(ska, skb);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrorot(ska, skb);
	else if (ft_strcmp(line, "sa\n") == 0)
		swap(ska);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap(skb);
	else if (ft_strcmp(line, "ss\n") == 0)
		sswap(ska, skb);
	else
		error(ska, skb);
}

void	init(t_stack *ska, t_stack *skb)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		instruction(ska, skb, line);
		line = get_next_line(0);
	}
	if (is_sorted(ska) == 0 && skb->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
		init(ska, skb);
		ft_freestack(ska);
		ft_freestack(skb);
	}
	return (0);
}
