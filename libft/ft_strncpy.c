/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:55:06 by adondera          #+#    #+#             */
/*   Updated: 2017/12/11 22:24:26 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	char	*res;

	i = -1;
	res = dst;
	while (++i < len)
	{
		if (*src)
			*dst++ = *src++;
		else
			*dst++ = 0;
	}
	return (res);
}
