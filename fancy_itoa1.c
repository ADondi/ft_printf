/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fancy_itoa1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:24:30 by adondera          #+#    #+#             */
/*   Updated: 2018/02/24 15:24:34 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*fancy_unsigned_itoa(t_u64 n, int base, int switch01)
{
	int			i;
	int			tmp;
	char		*len;

	i = num_length(n, base);
	if (!(len = (char *)malloc(sizeof(char) * (i + 1))))
		exit(1);
	if (n == 0)
		return (ft_strcpy(len, "0"));
	len[i] = '\0';
	while (n > 0)
	{
		tmp = n % base;
		if (tmp > 9)
			len[i - 1] = pick_letter(tmp, switch01);
		else
			len[i - 1] = tmp + '0';
		n = n / base;
		i--;
	}
	return (len);
}
