/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:01:54 by adondera          #+#    #+#             */
/*   Updated: 2017/12/11 22:29:35 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str_cpy;
	size_t	i;

	i = 0;
	str_cpy = ft_strnew(n * sizeof(char));
	if (str_cpy == NULL)
		return (NULL);
	while (i < n)
	{
		str_cpy[i] = s1[i];
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}
