/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:50:45 by adondera          #+#    #+#             */
/*   Updated: 2017/12/12 17:41:11 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*p_dst;
	char	*p_src;
	size_t	i;

	p_dst = (char *)dst;
	p_src = (char *)src;
	i = 0;
	if (p_src > p_dst)
	{
		while (i < len)
		{
			p_dst[i] = p_src[i];
			i++;
		}
	}
	else
	{
		len--;
		while ((int)(len) >= 0)
		{
			p_dst[len] = p_src[len];
			len--;
		}
	}
	return (dst);
}
