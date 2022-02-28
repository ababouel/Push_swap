/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:42:27 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/28 18:09:44 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_stack {
	int				data;
	struct s_stack	*next;
}	t_stack;



void	print(t_stack *stack)
{
	printf(" %d\n",stack->data);
}

void	ft_lstiter(t_stack *lst, void (*f)(t_stack *))
{
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}

void	ft_swap(t_stack *lst)
{
	t_stack *temp;
	int		tim;
	
	if (lst != NULL)
	{
		temp = lst->next;
		tim = lst->data;
		lst->data = temp->data;
		temp->data = tim;
	}
}
void	ft_ss(t_stack *lsta, t_stack *lstb)
{
	ft_swap(lsta);
	ft_swap(lstb);
}


void	ft_lstadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*temp;

	if (*alst == NULL)
		*alst = new;
	else
	{
		temp = *alst;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}

t_stack	*ft_lstnew(int data)
{
	t_stack	*lst;

	lst = malloc(sizeof(t_stack));
	if (!lst)
		return (0);
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_front(t_stack **alsta, t_stack **alstb)
{
	t_stack	*temp;

	temp = NULL;
	if (*alsta)
	{
		temp = *alsta;
		*alsta = (*alsta)->next;
		if (!*alstb)
			*alstb = temp;
		else 
		{
			temp->next = *alstb;
			*alstb = temp;
			(*alstb)->next = NULL;
		}
	}
}

int	main()
{
	t_stack *stack_a;
	t_stack	*stack_b;
	t_stack *node1;
	t_stack *node6;
	t_stack *node2;
	t_stack *node3;
	t_stack *node4;
	t_stack *node5;

	stack_a = NULL;
	stack_b = NULL;
	node1 = ft_lstnew(5);
	node2 = ft_lstnew(10);
	node3 = ft_lstnew(-10);
	node4 = ft_lstnew(8);
	node5 = ft_lstnew(18);
	node6 = ft_lstnew(-18);

	ft_lstadd_back(&stack_a, node1);
	ft_lstadd_back(&stack_a, node2);
	ft_lstadd_back(&stack_a, node3);
	ft_lstadd_back(&stack_a, node4);
	ft_lstadd_back(&stack_a, node5);
	ft_lstadd_back(&stack_a, node6);

	ft_lstiter(stack_a,print);
	printf("=====data=====\n");
	ft_swap(stack_a);
	ft_lstiter(stack_a,print);
	printf("=====data=====\n");
	ft_lstadd_front(&stack_a, &stack_b);
	ft_lstadd_front(&stack_a, &stack_b);
	ft_lstiter(stack_b,print);
	printf("=====data=====\n");
}
