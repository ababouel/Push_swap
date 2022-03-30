/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:08:13 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/29 18:55:51 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node {
	int				data;
	int				index;
	int				check;
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
void	ft_freestack(t_stack *sk);
t_node	*nodex(t_stack *stack, int size);
int		is_sorted(t_stack *stack);
int		lowestnum(t_node *head);
int		sort_threenode(t_stack *stack, char c);
void	sorttwnode(t_stack *stack, char c);
int		getindex(t_stack *stack, int number);
void	sorting_ten(t_stack *ska, t_stack *skb);
void	indexthenode(t_stack *ska);
void	chanks(t_stack *ska, t_stack *skb, int indpb, int indrb);
int		getindexes(t_stack *stack, int number);
int		biggestnum(t_node *head);
void	pushabeta(t_stack *ska, t_stack *skb);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_atoi(const char *str);
void	checknu(char **data);
void	ft_freememx(void **data);
int		*dtoi(char **data);
void	checkmaxd(long *lnu, char **data);
char	**injectstr(char **str);
void	sorting_tenx(t_stack *ska, t_stack *skb);
int		lowestnumexp(t_node *head);
int		hold_first(t_node *head, int proxi);
int		hold_second(t_node *head, int proxi);
int		lmove(int holdf, int holds, t_stack *ska);
long	ft_atol(const char *str);
long	*dtol(char **data);
int		isdouble(long *dint, int size);
int		isint(long *dint, int size);
int		ft_lenstr(char **data);
void	injectnode(t_stack *ska, char **str);
int		numberdex(int dex, t_node *head);
size_t	ft_strlen(const char *s);

#endif
