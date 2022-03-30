/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mcheckd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:39:54 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/29 16:46:37 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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

long	*dtol(char **data)
{
	int		len;
	long	*lnu;

	len = ft_lenstr(data);
	lnu = malloc(sizeof(long) * len);
	len = 0;
	while (data[len])
	{
		lnu[len] = ft_atol(data[len]);
		len++;
	}
	return (lnu);
}

int	isdouble(long *dint, int size)
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
	return (1);
}

int	isint(long *dint, int size)
{
	int		len;
	long	max_int;
	long	min_int;

	len = 0;
	min_int = -2147483648;
	max_int = 2147483647;
	while (len < size)
	{
		if (dint[len] < min_int
			|| dint[len] > max_int)
			return (-1);
		len++;
	}
	return (1);
}
