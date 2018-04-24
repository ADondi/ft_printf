/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:25:13 by adondera          #+#    #+#             */
/*   Updated: 2018/02/24 15:25:18 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <wchar.h>
# include <inttypes.h>

typedef struct					s_flags
{
	int							fdiez;
	int							fzero;
	int							fminus;
	int							fplus;
	int							fspace;
	int							fwidth;
	int							fdot;
	int							fprecision;
	int							fhh;
	int							fh;
	int							fl;
	int							fll;
	int							fj;
	int							fz;
	int							fstar;
}								t_flags;

typedef	unsigned long long int	t_u64;
typedef	long long int			t_s64;

int								ft_printf(const char *format, ...);
int								print_before_percent(char *format, va_list \
								*lst);
void							init_flags(t_flags *f);
int								main_handler(char **format, va_list *lst, \
								int num);
void							analyse_flags(char **format, t_flags *f);
void							analyse_width(char **format, va_list *lst,\
								t_flags *f);
void							analyse_precision(char **format, va_list \
								*lst, t_flags *f);
void							analyse_length(char **format, t_flags *f);
int								naked_atoi(char **str);
int								specificator(char **format, va_list *lst, \
								int num, t_flags *f);
int								specificator2(char **format, va_list *lst, \
								int num, t_flags *f);
int								specificator3(char **format, va_list *lst, \
								int num, t_flags *f);
int								specificator4(char **format, va_list *lst, \
								int num, t_flags *f);
int								int_handle(va_list *lst, t_flags *f);
t_s64							handle_length(va_list *lst, t_flags *f);
char							*handle_min_max(void);
char							*fancy_itoa(t_s64 n);
int								precision_len(char *s, t_flags *f);
void							print_padd(int num, char c);
void							handle_precision(char *s, t_flags *f);
int								handle_width(char *s, t_flags *f, char *prefix);
void							handle_width2(char *s, char *prefix, int len, \
								t_flags *f);
t_u64							handle_unsigned_length(va_list *lst, \
								t_flags *f);
char							pick_letter(int n, int switch01);
char							*fancy_unsigned_itoa(t_u64 n, int base, int \
								switch01);
int								num_length(t_u64 n, int base);
int								unsigned_handle(va_list *lst, t_flags *f);
int								octal_handle(va_list *lst, t_flags *f);
int								hex_handle(va_list *lst, int switch01, \
								t_flags *f);
int								percent_handle(t_flags *f);
int								char_handle(va_list *lst, t_flags *f);
int								adress_handle(va_list *lst, t_flags *f);
int								string_handle(va_list *lst, t_flags *f);
int								n_handle(va_list *lst, t_flags *f, int num);
void							ft_putwide(wchar_t c);
int								ft_charlen(wchar_t c);
int								widechar_handle(va_list *lst, t_flags *f);
int								wide_strlen(wchar_t *wstr);
int								ft_putwidestr(wchar_t *wstr, int how_much);
int								widestr_precision(wchar_t *wstr, t_flags *f);
int								widestr_width(wchar_t *wstr, t_flags *f);
int								widestr_handle(va_list *lst, t_flags *f);
int								wide_precision_len(wchar_t *wstr, t_flags *f);
int								ft_widestrlen(wchar_t *wstr);
int								char_width(unsigned char c, t_flags *f);
int								undefined_handle(va_list *lst, t_flags *f, \
								char c);
int								ft_charnumm1(t_s64 n);
#endif
