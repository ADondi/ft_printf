/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 13:19:59 by adondera          #+#    #+#             */
/*   Updated: 2017/12/11 16:42:52 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char		*new_str;
	char const	*p;
	int			end_space;
	int			len;

	len = 0;
	end_space = 0;
	len = 0;
	if (s == NULL)
		return (NULL);
	p = s;
	while (*p == ' ' || *p == '\n' || *p == '\t')
		p++;
	if (!(len = ft_strlen(p)))
		return (ft_strsub(s, 0, len));
	p = p + len - 1;
	while (*p == ' ' || *p == '\n' || *p == '\t')
	{
		end_space++;
		p--;
	}
	len -= end_space;
	p -= (len - 1);
	new_str = ft_strsub(p, 0, len);
	return (new_str);
}
