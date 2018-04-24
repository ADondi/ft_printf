/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:25:39 by adondera          #+#    #+#             */
/*   Updated: 2018/02/24 15:25:41 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		analyse_width(char **format, va_list *lst, t_flags *f)
{
	int		parsing;

	parsing = 1;
	while (parsing)
	{
		if (**format == '*')
		{
			f->fwidth = va_arg(*lst, int);
			if (f->fwidth < 0)
			{
				f->fminus = 1;
				f->fwidth = f->fwidth * -1;
			}
			(*format)++;
		}
		else if (ft_isdigit(**format))
			f->fwidth = naked_atoi(format);
		else
			parsing = 0;
	}
}

int			naked_atoi(char **str)
{
	int		nr;

	nr = 0;
	while ('0' <= **str && **str <= '9')
	{
		nr = nr * 10 + (**str - '0');
		(*str)++;
	}
	return (nr);
}

void		analyse_precision(char **format, va_list *lst, t_flags *f)
{
	if (**format == '.')
	{
		f->fdot = 1;
		(*format)++;
		if (**format == '*')
		{
			f->fprecision = va_arg(*lst, int);
			(*format)++;
		}
		else if (ft_isdigit(**format))
			f->fprecision = naked_atoi(format);
	}
}

void		analyse_length(char **format, t_flags *f)
{
	if ((*format)[0] == 'h' && (*format)[1] == 'h')
		f->fhh = 1;
	else if ((*format)[0] == 'l' && (*format)[1] == 'l')
		f->fll = 1;
	else if ((*format)[0] == 'h')
		f->fh = 1;
	else if (*format[0] == 'l')
		f->fl = 1;
	else if ((*format)[0] == 'j')
		f->fj = 1;
	else if ((*format)[0] == 'z')
		f->fz = 1;
	if (f->fhh || f->fll)
		(*format) = *format + 2;
	else if (f->fh || f->fl || f->fj || f->fz)
		(*format)++;
}

int			specificator(char **format, va_list *lst, int num, t_flags *f)
{
	if ((*format)[0] == 'd' || (*format)[0] == 'i')
	{
		(*format)++;
		return (int_handle(lst, f));
	}
	else if ((*format)[0] == 'u')
	{
		(*format)++;
		return (unsigned_handle(lst, f));
	}
	else if ((*format)[0] == 'o')
	{
		(*format)++;
		return (octal_handle(lst, f));
	}
	else if ((*format)[0] == 'x')
	{
		(*format)++;
		return (hex_handle(lst, 0, f));
	}
	return (specificator2(format, lst, num, f));
}
