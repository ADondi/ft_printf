/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:01:54 by adondera          #+#    #+#             */
/*   Updated: 2017/12/11 22:29:35 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str_cpy;
	size_t	len;

	len = ft_strlen(s1);
	str_cpy = ft_strnew(len * sizeof(char));
	if (str_cpy == NULL)
		return (NULL);
	while (*s1)
	{
		*str_cpy = *s1;
		s1++;
		str_cpy++;
	}
	*str_cpy = '\0';
	str_cpy -= len;
	return (str_cpy);
}
