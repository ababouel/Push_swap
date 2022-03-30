/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:16:37 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/29 15:36:40 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_freememx(void **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
}

void	ft_freestack(t_stack *sk)
{
	t_node	*node;

	while (sk->head != NULL)
	{
		node = sk->head;
		sk->head = sk->head->next;
		free(node);
	}
	free(sk);
}
