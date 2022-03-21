/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:32:42 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/21 17:49:41 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				index;

	index = 0;
	if (dst == NULL && src == NULL )
		return (NULL);
	while (index < n)
	{
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*data;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == 0 || s2 == 0)
		return (0);
	data = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (data != 0)
	{
		ft_memcpy(data, s1, ft_strlen(s1));
		ft_memcpy(data + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	}
	free(s1);
	return (data);
}
