/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 11:48:15 by adondera          #+#    #+#             */
/*   Updated: 2017/12/11 16:25:36 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		size;
	int		index;
	char	*new_str;

	index = 0;
	size = 0;
	if (s)
	{
		size = ft_strlen(s);
		if (!(new_str = ft_strnew(size * sizeof(char))))
			return (NULL);
		while (index < size)
		{
			*new_str = f(*s);
			s++;
			new_str++;
			index++;
		}
		*new_str = '\0';
		new_str = new_str - size;
		return (new_str);
	}
	return (NULL);
}
