/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:39:45 by adondera          #+#    #+#             */
/*   Updated: 2017/12/12 17:47:38 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*p;
	size_t	len_1;
	size_t	i;

	i = 0;
	len_1 = ft_strlen(s1);
	p = s1 + len_1;
	if (n > ft_strlen(s2))
		n = ft_strlen(s2);
	while (i < n)
	{
		*p++ = *s2++;
		i++;
	}
	*p = '\0';
	return (s1);
}
