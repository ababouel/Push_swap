/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mcheckd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:39:54 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/23 18:55:11 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_lenstr(char **data)
{
	int	index;

	index = 0;
	while (data[index])
		index++;
	return (index);
}

int	*dtoi(char **data)
{
	int	len;
	int	*lnu;

	len = ft_lenstr(data);
	lnu = malloc(sizeof(int) * len);
	len = 0;
	while (data[len])
	{
		lnu[len] = ft_atoi(data[len]);
		len++;
	}
	return (lnu);
}

int	isdouble(int *dint, int size)
{
	int	len;
	int	len2;

	len = 0;
	len2 = 0;
	while (len < size)
	{
		len2 = len + 1;
		while (len2 < size)
		{
			if (dint[len2] == dint[len])
				return (-1);
			len2++;
		}
		len++;
	}
	len = 0;
	while (len < size)
	{
		if (dint[len] < -2147483648 && dint[len] > 2147483647)
			return (-1);
		len++;
	}
	return (1);
}

void	checkmaxd(int *lnu, char **data)
{
	int	size;

	size = ft_lenstr(data);
	if (isdouble(lnu, size) == -1)
	{
		ft_freememx((void **) data);
		free(lnu);
		write(1, "Error\n", 6);
		exit(1);
	}
	free(lnu);
}
