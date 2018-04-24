/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:43:24 by adondera          #+#    #+#             */
/*   Updated: 2017/12/12 20:31:03 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *str)
{
	int			i;
	long long	sign;
	long long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' ||
			str[i] == '\b' || str[i] == '\f' || str[i] == '\v' ||
			str[i] == '\a' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb < 0 && (sign == 1))
			return (-1);
		else if (nb < 0 && (sign == -1))
			return (0);
		i++;
	}
	return (nb * sign);
}
