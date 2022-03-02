/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:42:27 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/02 20:02:38 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"




void	print(int nb)
{
	printf("= %d =\n",nb);
}

void	ft_lstiter(t_stack *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst->data);
		lst = lst->next;
	}
}

int	main()
{
	t_stack *ska = NULL;
	t_stack *skb = NULL;
	t_stack	*temp = NULL;
	t_stack *n1 = NULL;
	t_stack *n2 = NULL;
	t_stack *n3 = NULL;
	t_stack *n4 = NULL;
	t_stack *n5 = NULL;
	t_stack *n6 = NULL;

	n1 = ft_lstnew(4);
	n2 = ft_lstnew(3);
	n3 = ft_lstnew(10);
	n4 = ft_lstnew(11);
	n5 = ft_lstnew(9);
	n6 = ft_lstnew(2);
	ft_add_back(&ska,n1);
	ft_add_back(&ska,n2);
	ft_add_back(&ska,n3);
	ft_add_back(&ska,n4);
	ft_add_back(&ska,n5);
	ft_add_back(&ska,n6);

	printf("<====================data======================>\n");
	printf("<===stack_a===>\n");
	ft_lstiter(ska,print);
	printf("<===stack_b===>\n");
	ft_lstiter(skb,print);
//  modif pa
	
	printf("<====================data======================>\n");
	printf("<===stack_a===>\n");
	ft_lstiter(ska,print);
	printf("<===stack_b===>\n");
	ft_lstiter(skb,print);
// modif pb

	printf("<====================data======================>\n");
	printf("<===stack_a===>\n");
	ft_lstiter(ska,print);
	printf("<===stack_b===>\n");
	ft_lstiter(skb,print);
}
