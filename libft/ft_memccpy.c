/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:15:44 by adondera          #+#    #+#             */
/*   Updated: 2017/12/11 22:25:18 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = dst;
	while (i < n)
	{
		p[i] = *((unsigned char *)src + i);
		if (*((unsigned char *)src + i) == (unsigned char)c)
			return ((char *)dst + i + 1);
		i++;
	}
	return (NULL);
}
