/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 11:52:15 by adondera          #+#    #+#             */
/*   Updated: 2017/12/11 16:26:47 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	index;
	char			*new_str;

	index = 0;
	size = 0;
	if (s)
	{
		size = ft_strlen(s);
		new_str = ft_strnew(size * sizeof(char));
		if (new_str == NULL)
			return (NULL);
		while (index < size)
		{
			*new_str = f(index, *s);
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
