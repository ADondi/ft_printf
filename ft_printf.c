/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:24:56 by adondera          #+#    #+#             */
/*   Updated: 2018/02/24 15:24:59 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		lst;
	int			printat;

	va_start(lst, format);
	printat = print_before_percent((char *)format, &lst);
	va_end(lst);
	return (printat);
}

int			main(void)
{
	ft_printf("en_US.UTF-8");
	return (0);
}
