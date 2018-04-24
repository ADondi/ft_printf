/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:39:33 by adondera          #+#    #+#             */
/*   Updated: 2018/01/12 15:44:19 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char	*p_big;
	const char	*p_little;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0')
	{
		p_big = big;
		p_little = little;
		while (*p_little != '\0' && *p_big == *p_little)
		{
			p_big++;
			p_little++;
		}
		if (*p_little == '\0')
			return ((char *)big);
		big++;
	}
	return (NULL);
}
