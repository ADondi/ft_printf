/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:24:01 by adondera          #+#    #+#             */
/*   Updated: 2017/12/12 17:45:52 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*p;
	size_t	len_1;
	size_t	len_2;
	size_t	i;

	i = 0;
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	p = s1 + len_1;
	while (i < len_2)
	{
		*p++ = *s2++;
		i++;
	}
	*p = '\0';
	return (s1);
}
