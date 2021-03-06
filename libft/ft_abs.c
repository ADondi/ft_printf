/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:39:23 by adondera          #+#    #+#             */
/*   Updated: 2017/12/12 16:03:59 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ptrdiff_t	ft_abs(ptrdiff_t n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}
