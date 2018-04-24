/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:04:22 by adondera          #+#    #+#             */
/*   Updated: 2017/12/12 12:31:48 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*p;

	p = s;
	if ((char)c == '\0')
		return ((char *)p + ft_strlen(p));
	while (*p)
	{
		if (*p == (char)c)
			return ((char *)p);
		p++;
	}
	return (NULL);
}
