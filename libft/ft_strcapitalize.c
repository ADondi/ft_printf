/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:40:57 by adondera          #+#    #+#             */
/*   Updated: 2018/01/12 15:42:39 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_letter(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
		(c >= 48 && c <= 57))
		return (1);
	return (0);
}

char		*ft_strcapitalize(char *s)
{
	char	*res;
	int		new_word;

	res = s;
	new_word = 0;
	if (s == NULL)
		return (NULL);
	while (*res)
	{
		if (ft_is_letter(*res) == 0)
			new_word = 0;
		else if (ft_is_letter(*res) == 1 && new_word == 0)
		{
			new_word = 1;
			if (*res >= 'a' && *res <= 'z')
				*res = *res - 32;
		}
		else
		{
			if (*res >= 'A' && *res <= 'Z')
				*res = *res + 32;
		}
		res++;
	}
	return (s);
}
