/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:26:31 by adondera          #+#    #+#             */
/*   Updated: 2018/02/24 15:26:35 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			precision_len(char *s, t_flags *f)
{
	int		len;

	len = f->fprecision - ft_strlen(s);
	if (len > 0)
		return (f->fprecision);
	else
		return (ft_strlen(s));
}

void		print_padd(int num, char c)
{
	int		i;

	i = 0;
	while (i < num)
	{
		ft_putchar(c);
		i++;
	}
}

void		handle_precision(char *s, t_flags *f)
{
	int		len;

	len = f->fprecision - ft_strlen(s);
	if (len > 0)
		print_padd(len, '0');
	ft_putstr(s);
}

int			handle_width(char *s, t_flags *f, char *prefix)
{
	int		len;

	len = f->fwidth - precision_len(s, f) - ft_strlen(prefix);
	if (len > 0)
	{
		if (f->fminus)
		{
			ft_putstr(prefix);
			handle_precision(s, f);
			print_padd(len, ' ');
		}
		else
			handle_width2(s, prefix, len, f);
		return (f->fwidth);
	}
	ft_putstr(prefix);
	handle_precision(s, f);
	return (precision_len(s, f) + ft_strlen(prefix));
}

void		handle_width2(char *s, char *prefix, int len, t_flags *f)
{
	if (f->fzero)
	{
		ft_putstr(prefix);
		print_padd(len, '0');
		handle_precision(s, f);
	}
	else
	{
		print_padd(len, ' ');
		ft_putstr(prefix);
		handle_precision(s, f);
	}
}
