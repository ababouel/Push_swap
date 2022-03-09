/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:08:13 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/09 17:21:23 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node {
	int				data;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

void	init_stack(t_stack *stack);
int		ins_next_node(t_stack *stack, t_node *node, int data);
void	ins_rem_node(t_stack *stack, t_node *node, int data);
int		pusha(t_stack *stka, t_stack *stkb);
int		pushb(t_stack *stka, t_stack *stkb);
int		swap(t_stack *stack, char c);
int		rorot(t_stack *stack, char c);
int		rot(t_stack *stack, char c);
void	rrorot(t_stack *ska, t_stack *skb);
void	sswap(t_stack *ska, t_stack *skb);
void	rrot(t_stack *ska, t_stack *skb);
t_node	*nodex(t_stack *stack, int size);
int		is_sorted(t_stack *stack);
int		lowestnum(t_node *head);
int		sort_threenode(t_stack *stack, char c);

#endif
