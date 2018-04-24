/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:43:26 by adondera          #+#    #+#             */
/*   Updated: 2017/12/11 22:27:13 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*p_dst;
	char	*p_src;

	i = 0;
	p_dst = dst;
	p_src = (char *)src;
	while (i < len)
	{
		p_dst[i] = p_src[i];
		i++;
	}
	return (dst);
}
