/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:26:42 by adondera          #+#    #+#             */
/*   Updated: 2018/02/24 15:26:45 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			char_width(unsigned char c, t_flags *f)
{
	int		ret;

	ret = 1;
	if (f->fwidth > 1)
	{
		ret = f->fwidth;
		if (f->fminus)
		{
			ft_putchar(c);
			while (--f->fwidth != 0)
				ft_putchar(' ');
		}
		else
		{
			while (--f->fwidth != 0)
				ft_putchar((f->fzero) ? '0' : ' ');
			ft_putchar(c);
		}
	}
	else
		ft_putchar(c);
	return (ret);
}
