/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 12:00:05 by adondera          #+#    #+#             */
/*   Updated: 2017/12/11 16:27:53 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	i;

	i = 0;
	if (s)
	{
		new_str = ft_strnew(len * sizeof(char));
		if (new_str == NULL)
			return (NULL);
		while (i < len)
		{
			*new_str = s[start];
			start++;
			i++;
			new_str++;
		}
		*new_str = '\0';
		new_str -= len;
		return (new_str);
	}
	return (NULL);
}
