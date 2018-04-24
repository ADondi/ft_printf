/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:25:30 by adondera          #+#    #+#             */
/*   Updated: 2018/02/24 15:25:33 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_before_percent(char *format, va_list *lst)
{
	int		citite;

	citite = 0;
	if (format == NULL)
		return (0);
	while (format[0] != '\0')
	{
		if (format[0] == '%' && format[1] == '\0')
			return (citite);
		if (format[0] == '%')
		{
			format++;
			citite = citite + main_handler(&format, lst, citite);
			continue ;
		}
		ft_putchar(format[0]);
		format++;
		citite++;
	}
	return (citite);
}

int			main_handler(char **format, va_list *lst, int num)
{
	int			citite;
	t_flags		flags;

	init_flags(&flags);
	citite = 0;
	analyse_flags(format, &flags);
	analyse_width(format, lst, &flags);
	analyse_precision(format, lst, &flags);
	analyse_length(format, &flags);
	citite = specificator(format, lst, num, &flags);
	return (citite);
}

void		init_flags(t_flags *f)
{
	f->fdiez = 0;
	f->fzero = 0;
	f->fminus = 0;
	f->fplus = 0;
	f->fspace = 0;
	f->fwidth = 0;
	f->fdot = 0;
	f->fprecision = 0;
	f->fhh = 0;
	f->fh = 0;
	f->fl = 0;
	f->fll = 0;
	f->fj = 0;
	f->fz = 0;
	f->fstar = 0;
}

void		analyse_flags(char **format, t_flags *f)
{
	int		parsing;

	parsing = 1;
	while (parsing)
	{
		if (**format == '-')
			f->fminus = 1;
		else if (**format == '+')
			f->fplus = 1;
		else if (**format == ' ')
			f->fspace = 1;
		else if (**format == '#')
			f->fdiez = 1;
		else if (**format == '0')
			f->fzero = 1;
		else
			parsing = 0;
		if (parsing != 0)
			(*format)++;
	}
}
