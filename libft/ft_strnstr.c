/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:47:14 by adondera          #+#    #+#             */
/*   Updated: 2017/12/12 15:50:44 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	index2;

	if (!*little)
		return ((char *)big);
	index2 = 0;
	while (big[index2])
	{
		index = 0;
		while (big[index2 + index] == little[index] && index2 + index < len)
			if (!little[++index])
				return ((char *)(big + index2));
		index2++;
	}
	return (0);
}
