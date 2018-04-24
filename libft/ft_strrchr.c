/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:37:09 by adondera          #+#    #+#             */
/*   Updated: 2017/12/12 12:38:28 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;
	const char	*last_pos;

	p = s;
	last_pos = NULL;
	if ((char)c == '\0')
		return ((char *)p + ft_strlen(p));
	while (*p)
	{
		if (*p == (char)c)
			last_pos = p;
		p++;
	}
	return ((char *)last_pos);
}
