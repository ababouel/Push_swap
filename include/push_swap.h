/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:38:50 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/06 15:58:19 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_stack {
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int data);
int		ft_lstsize(t_stack *lst);
void	ft_add_back(t_stack **alst, t_stack *new);
void 	swap(t_stack **stack,char c);
void	rot(t_stack **stack,char c);
void	rotrot(t_stack **stack,char c);
void	push_a(t_stack **ska, t_stack **skb);
void	push_b(t_stack **ska, t_stack **skb);
void	ft_lstadd_front(t_stack **alst, t_stack *new);

#endif
