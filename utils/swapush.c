/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:42:27 by ababouel          #+#    #+#             */
/*   Updated: 2022/02/26 00:12:43 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_stack {
	int				data;
	struct s_stack	*next;
}	t_stack;



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


void	swap(int *arr, int len)
{
	int	a;

	a = arr[len - 1];
	arr[len - 1] = arr[len - 2];
	arr[len - 2] = a;
}

void	push_a(int *arra, int *arrb, int lena, int lenb)
{
	arrb[lenb - 1] = arra[lena - 1];

}

void	printstack(int *arra, int len)
{
	int	x;

	x = 0;
	while(x < len)
		printf("%d\n",arra[x++]);
	printf("====finish stack====\n");
}

int	main()
{
	int stack_a[5] = {110, 5, 6, 7, 3};
	int	stack_b[5] = {0};
	printstack(stack_a,5);
	swap(stack_a, 5);
	printstack(stack_a,5);
	swap(stack_a, 5);
	printstack(stack_a,5);
	swap(stack_a, 5);
	printstack(stack_a,5);
	push_a(stack_a, stack_b, 5, 5);
	printstack(stack_a,5);
	printstack(stack_b,5);
}
