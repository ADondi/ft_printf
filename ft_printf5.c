/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:26:21 by adondera          #+#    #+#             */
/*   Updated: 2018/02/24 15:26:25 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			unsigned_handle(va_list *lst, t_flags *f)
{
	t_u64	bucket;
	int		ret;
	char	*s;

	bucket = handle_unsigned_length(lst, f);
	if (bucket == 0 && f->fdot && f->fprecision == 0)
		return (0);
	if (f->fdot)
		f->fzero = 0;
	s = fancy_unsigned_itoa(bucket, 10, 0);
	ret = handle_width(s, f, "");
	free(s);
	return (ret);
}

int			octal_handle(va_list *lst, t_flags *f)
{
	t_u64	bucket;
	int		ret;
	char	*s;

	bucket = handle_unsigned_length(lst, f);
	if (bucket == 0 && f->fdot && f->fprecision == 0 && !f->fdiez)
		return (handle_width("", f, ""));
	s = fancy_unsigned_itoa(bucket, 8, 0);
	if (f->fdot && f->fprecision > 0)
	{
		f->fdiez = 0;
		f->fzero = 0;
	}
	if (f->fdiez && bucket != 0)
		ret = handle_width(s, f, "0");
	else
		ret = handle_width(s, f, "");
	free(s);
	return (ret);
}

int			hex_handle(va_list *lst, int switch01, t_flags *f)
{
	t_u64	bucket;
	int		ret;
	char	*s;

	bucket = handle_unsigned_length(lst, f);
	if (bucket == 0 && f->fdot && f->fprecision == 0)
		return (handle_width("", f, ""));
	s = fancy_unsigned_itoa(bucket, 16, switch01);
	if (f->fdot && f->fprecision > 0)
		f->fzero = 0;
	if (f->fdiez && bucket != 0)
		ret = handle_width(s, f, (switch01 == 0) ? "0x" : "0X");
	else
		ret = handle_width(s, f, "");
	free(s);
	return (ret);
}

t_u64		handle_unsigned_length(va_list *lst, t_flags *f)
{
	t_u64		nr;

	if (f->fl)
		nr = (unsigned long int)va_arg(*lst, unsigned long int);
	else if (f->fhh)
		nr = (unsigned char)va_arg(*lst, unsigned int);
	else if (f->fh)
		nr = (unsigned short int)va_arg(*lst, unsigned int);
	else if (f->fll)
		nr = (t_u64)va_arg(*lst, unsigned long long int);
	else if (f->fj)
		nr = (uintmax_t)va_arg(*lst, uintmax_t);
	else if (f->fz)
		nr = (size_t)va_arg(*lst, size_t);
	else
		nr = (unsigned int)va_arg(*lst, unsigned int);
	return (nr);
}

t_s64		handle_length(va_list *lst, t_flags *f)
{
	t_s64		nr;

	if (f->fl)
		nr = (long int)va_arg(*lst, long int);
	else if (f->fhh)
		nr = (char)va_arg(*lst, int);
	else if (f->fh)
		nr = (short int)va_arg(*lst, int);
	else if (f->fll)
		nr = (t_s64)va_arg(*lst, long long int);
	else if (f->fj)
		nr = (intmax_t)va_arg(*lst, intmax_t);
	else if (f->fz)
		nr = (size_t)va_arg(*lst, size_t);
	else
		nr = (int)va_arg(*lst, int);
	return (nr);
}
