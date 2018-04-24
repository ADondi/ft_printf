/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fancy_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:24:14 by adondera          #+#    #+#             */
/*   Updated: 2018/02/24 15:24:21 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_charnum1(t_s64 n)
{
	int		i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*handle_min_max(void)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * 21);
	if (p == NULL)
		exit(1);
	ft_strcpy(p, "-9223372036854775808");
	return (p);
}

char		*fancy_itoa(t_s64 n)
{
	int			i;
	char		*len;

	if (n == (-9223372036854775807 - 1))
		return (handle_min_max());
	i = ft_charnum1(n);
	if (!(len = (char *)malloc(sizeof(char) * (i + 1))))
		exit(1);
	if (n < 0)
	{
		len[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		return (ft_strcpy(len, "0"));
	len[i] = '\0';
	while (n > 0)
	{
		len[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (len);
}

int			num_length(t_u64 n, int base)
{
	int		i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char		pick_letter(int n, int switch01)
{
	if (n == 10)
		return ((switch01 == 1) ? 'A' : 'a');
	else if (n == 11)
		return ((switch01 == 1) ? 'B' : 'b');
	else if (n == 12)
		return ((switch01 == 1) ? 'C' : 'c');
	else if (n == 13)
		return ((switch01 == 1) ? 'D' : 'd');
	else if (n == 14)
		return ((switch01 == 1) ? 'E' : 'e');
	else
		return ((switch01 == 1) ? 'F' : 'f');
}
