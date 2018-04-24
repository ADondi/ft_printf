/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:43:05 by adondera          #+#    #+#             */
/*   Updated: 2018/01/12 15:43:29 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(char *s)
{
	char *res;

	res = s;
	if (s == NULL)
		return (NULL);
	while (*res)
	{
		if (*res >= 'A' && *res <= 'Z')
			*res = ft_tolower((int)*res);
		res++;
	}
	return (s);
}
