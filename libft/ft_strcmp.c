/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:23:54 by adondera          #+#    #+#             */
/*   Updated: 2017/12/10 15:24:14 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != 0 && *s2 != 0)
	{
		s1++;
		s2++;
	}
	if (*s1 == 0 && *s2 != 0)
		return (-1) * (int)(unsigned char)(*s2);
	if (*s1 != 0 && *s2 == 0)
		return (1) * (int)(unsigned char)(*s1);
	if (*s1 == 0 && *s2 == 0)
		return (0);
	return (int)(unsigned char)(*s1) - (int)(unsigned char)(*s2);
}
