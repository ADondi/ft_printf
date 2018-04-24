/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:26:08 by adondera          #+#    #+#             */
/*   Updated: 2018/02/24 15:26:11 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			string_handle(va_list *lst, t_flags *f)
{
	int		ret;
	char	*s;
	int		len;
	int		null;

	null = 0;
	if (f->fl)
		return (widestr_handle(lst, f));
	s = va_arg(*lst, char *);
	if (s == NULL)
	{
		s = "(null)";
		null = 1;
	}
	if (!(s = ft_strdup(s)))
		exit(1);
	len = f->fprecision - ft_strlen(s);
	if (len < 0 && f->fdot)
		s[f->fprecision] = '\0';
	f->fdot = 0;
	f->fprecision = 0;
	ret = handle_width(s, f, "");
	if (null == 0)
		free(s);
	return (ret);
}

int			adress_handle(va_list *lst, t_flags *f)
{
	t_u64	bucket;
	int		ret;
	void	*p;
	char	*s;

	p = va_arg(*lst, void *);
	if (p == NULL && f->fdot && f->fprecision == 0)
		return (handle_width("", f, "0x"));
	bucket = (t_u64)p;
	s = fancy_unsigned_itoa(bucket, 16, 0);
	ret = handle_width(s, f, "0x");
	free(s);
	return (ret);
}

int			char_handle(va_list *lst, t_flags *f)
{
	int				ret;
	char			c;

	if (f->fl)
		return (widechar_handle(lst, f));
	c = (char)va_arg(*lst, int);
	f->fprecision = 0;
	f->fdot = 0;
	ret = char_width(c, f);
	return (ret);
}

int			percent_handle(t_flags *f)
{
	int		ret;

	f->fprecision = 0;
	f->fdot = 0;
	ret = handle_width("%", f, "");
	return (ret);
}

int			int_handle(va_list *lst, t_flags *f)
{
	t_s64	bucket;
	int		ret;
	char	*s;

	bucket = handle_length(lst, f);
	if (bucket == 0 && f->fdot && f->fprecision == 0)
		return (handle_width("", f, ""));
	s = fancy_itoa(bucket);
	if (f->fprecision > 0)
		f->fzero = 0;
	if (bucket < 0)
		ret = handle_width(s + 1, f, "-");
	else if (f->fplus)
		ret = handle_width(s, f, "+");
	else if (f->fspace)
		ret = handle_width(s, f, " ");
	else
		ret = handle_width(s, f, "");
	free(s);
	return (ret);
}
