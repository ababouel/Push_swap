/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmaxd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:52:01 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/28 15:48:39 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	checkmaxd(long *lnu, char **data)
{
	int	size;

	size = ft_lenstr(data);
	if (isdouble(lnu, size) == -1)
	{
		ft_freememx((void **) data);
		free(lnu);
		write(2, "Error\n", 6);
		exit(1);
	}
	if (isint((long *)lnu, size) == -1)
	{
		ft_freememx((void **) data);
		free(lnu);
		write(2, "Error\n", 6);
		exit(1);
	}
	free(lnu);
}
