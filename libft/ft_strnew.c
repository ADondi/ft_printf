/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 11:36:16 by adondera          #+#    #+#             */
/*   Updated: 2018/01/12 16:29:05 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem_str;

	mem_str = (char*)malloc(size * sizeof(char) + 1);
	if (mem_str == NULL)
		return (NULL);
	ft_bzero(mem_str, size + 1);
	return (mem_str);
}
