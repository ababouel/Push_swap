/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mcheck.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:49:49 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/26 20:08:07 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	condata(char **data, int i, int y)
{
	if (data[y][i] != '0' && data[y][i] != '9'
			&& data[y][i] != '8' && data[y][i] != '7'
			&& data[y][i] != '6' && data[y][i] != '5'
			&& data[y][i] != '4' && data[y][i] != '3'
			&& data[y][i] != '2' && data[y][i] != '1'
			&& data[y][i] != '-' && data[y][i] != '+')
		return (-1);
	if ((data[y][i] == '-' && data[y][i + 1] == '-')
			|| (data[y][i] == '+' && data[y][i + 1] == '+')
			|| (data[y][i] == '-' && data[y][i + 1] == '\0')
			|| (data[y][i] == '+' && data[y][i + 1] == '\0'))
		return (-1);
	return (1);
}

int	isnum(char **data)
{
	int	i;
	int	y;

	y = 0;
	while (data[y])
	{
		i = 0;
		while (data[y][i])
		{
			if (condata(data, i, y) == -1)
				return (-1);
			i++;
		}
		y++;
	}
	return (1);
}

void	checknu(char **data)
{
	if (isnum(data) == -1)
	{
		ft_freememx((void **)data);
		write(1, "Error\n", 6);
		exit(1);
	}
}

char	**injectstr(char **str)
{
	int		index;
	char	*alldata;
	char	**data;

	index = 1;
	alldata = NULL;
	while (str[index])
	{
		alldata = ft_strjoin(alldata, str[index]);
		alldata = ft_strjoin(alldata, " ");
		index++;
	}
	data = ft_split(alldata, ' ');
	return (data);
}

void	injectnode(t_stack *ska, char **str)
{
	int		index;
	t_node	*temp;

	index = 0;
	temp = NULL;
	while (str[index])
	{
		temp = ska->tail;
		ins_next_node(ska, temp, ft_atoi(str[index]));
		index++;
	}
}
