/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unbase.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:04:17 by adondera          #+#    #+#             */
/*   Updated: 2017/12/12 18:30:25 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_unbase(unsigned long long n, unsigned int base)
{
	char				*str;
	int					len;
	unsigned long long	value;
	const char			base_str[16] = "0123456789ABCDEF";

	value = n;
	len = 1;
	while (value >= base)
	{
		len++;
		value = value / base;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (0 < len--)
	{
		str[len] = base_str[n % base];
		n = n / base;
	}
	return (str);
}
