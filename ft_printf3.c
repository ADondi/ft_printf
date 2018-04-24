/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:25:49 by adondera          #+#    #+#             */
/*   Updated: 2018/02/24 15:25:53 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			specificator2(char **format, va_list *lst, int num, t_flags *f)
{
	if ((*format)[0] == 'X')
	{
		(*format)++;
		return (hex_handle(lst, 1, f));
	}
	else if ((*format)[0] == '%')
	{
		(*format)++;
		return (percent_handle(f));
	}
	else if ((*format)[0] == 'c')
	{
		(*format)++;
		return (char_handle(lst, f));
	}
	else if ((*format)[0] == 'p')
	{
		(*format)++;
		return (adress_handle(lst, f));
	}
	return (specificator3(format, lst, num, f));
}

int			specificator3(char **format, va_list *lst, int num, t_flags *f)
{
	if ((*format)[0] == 's')
	{
		(*format)++;
		return (string_handle(lst, f));
	}
	else if ((*format)[0] == 'D')
	{
		(*format)++;
		f->fl = 1;
		return (int_handle(lst, f));
	}
	else if ((*format)[0] == 'O')
	{
		(*format)++;
		f->fl = 1;
		return (octal_handle(lst, f));
	}
	else if ((*format)[0] == 'U')
	{
		(*format)++;
		f->fl = 1;
		return (unsigned_handle(lst, f));
	}
	return (specificator4(format, lst, num, f));
}

int			specificator4(char **format, va_list *lst, int num, t_flags *f)
{
	if ((*format)[0] == 'n')
	{
		(*format)++;
		return (n_handle(lst, f, num));
	}
	else if ((*format)[0] == 'C')
	{
		(*format)++;
		return (widechar_handle(lst, f));
	}
	else if ((*format)[0] == 'S')
	{
		(*format)++;
		return (widestr_handle(lst, f));
	}
	else
	{
		(*format)++;
		return (undefined_handle(lst, f, *((*format) - 1)));
	}
}

int			undefined_handle(va_list *lst, t_flags *f, char c)
{
	int			ret;

	ret = char_width(c, f);
	return (ret);
}

int			n_handle(va_list *lst, t_flags *f, int num)
{
	t_s64		*p;

	if (f->fhh)
		p = (t_s64 *)va_arg(*lst, char *);
	else if (f->fh)
		p = (t_s64 *)va_arg(*lst, short int *);
	else if (f->fl)
		p = (t_s64 *)va_arg(*lst, long int *);
	else if (f->fll)
		p = va_arg(*lst, long long int *);
	else if (f->fj)
		p = (t_s64 *)va_arg(*lst, intmax_t *);
	else if (f->fz)
		p = (t_s64 *)va_arg(*lst, size_t *);
	else
		p = (t_s64 *)va_arg(*lst, int *);
	*p = num;
	return (0);
}
