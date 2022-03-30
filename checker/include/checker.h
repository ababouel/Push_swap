/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:26:32 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/30 04:19:19 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

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

char    **injectstr(char **str);
size_t	ft_strlen(const char *s);
int		ft_strchr(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
void	checknu(char **data);
void	checkmaxd(long *lnu, char **data);
long	*dtol(char **data);
char	*ft_strdup(const char *s);
void	injectnode(t_stack *ska, char **str);
void	ft_freestack(t_stack *sk);
void	ft_freememx(void **data);
int		ft_strcmp(const char *s1, const char *s2);
int		pushb(t_stack *stka, t_stack *stkb);
int		pusha(t_stack *stka, t_stack *stkb);
int		swap(t_stack *stack);
int		rorot(t_stack *stack);
int		rot(t_stack *stack);
void	sswap(t_stack *ska, t_stack *skb);
void	rrorot(t_stack *ska, t_stack *skb);
void	rrot(t_stack *ska, t_stack *skb);
void	init_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
int		ft_lenstr(char **data);
int		isdouble(long *dint, int size);
int		isint(long *dint, int size);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		ins_next_node(t_stack *stack, t_node *node, int data);
long	ft_atol(const char *str);
t_node	*nodex(t_stack *stack, int size);
#endif
