/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:08:00 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/30 04:25:49 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

char	*ft_strdup(const char *s)
{
	char	*data;
	int		index;

	data = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!data)
		return (0);
	index = 0;
	while (s[index])
	{
		data[index] = s[index];
		index++;
	}
	data[index] = '\0';
	return (data);
}
