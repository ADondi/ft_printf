/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 12:00:49 by adondera          #+#    #+#             */
/*   Updated: 2018/02/24 14:17:33 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*ptr;

	i = 0;
	len = 0;
	if (!s1 || !s2)
		return (NULL);
	ptr = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[len++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		ptr[len++] = s2[i++];
	}
	ptr[len] = '\0';
	return (ptr);
}
