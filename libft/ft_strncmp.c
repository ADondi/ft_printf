/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:32:33 by adondera          #+#    #+#             */
/*   Updated: 2017/12/10 15:36:11 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*s1 == *s2 && *s1 != 0 && *s2 != 0 && i < n - 1)
	{
		s1++;
		s2++;
		i++;
	}
	if (*s1 == 0 && *s2 != '\0')
		return (-1) * (int)(unsigned char)(*s2);
	if (*s1 != '\0' && *s2 == 0)
		return (1) * (int)(unsigned char)(*s1);
	if (*s1 == *s2)
		return (0);
	return (int)(unsigned char)(*s1) - (int)(unsigned char)(*s2);
}
