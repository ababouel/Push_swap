/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:54:11 by ababouel          #+#    #+#             */
/*   Updated: 2022/03/29 18:57:16 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;
    size_t  n;

	index = 0;
    n = ft_strlen(s1);
	if (n == 0)
		return (0);
	while (s1[index] && s2[index] && s1[index] == s2[index] && index < n - 1)
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
