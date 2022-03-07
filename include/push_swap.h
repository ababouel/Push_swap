/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:08:13 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/07 17:08:16 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node {
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef	struct	s_stack {
	int		size;
	t_node	*head;
	int		index;
}	t_stack;

void	init_stack(t_stack *stack);
void	ins_next_node(t_stack *stack, t_node *node, int data);
void	ins_rem_node(t_stack *stack, t_node *node, int data);

#endif
