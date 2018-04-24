/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:59:58 by adondera          #+#    #+#             */
/*   Updated: 2017/12/11 16:37:13 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *str, char separator)
{
	int	word_count;
	int	i;

	word_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == separator)
			i++;
		if (str[i] != separator && str[i] != '\0')
			word_count++;
		while (str[i] != separator && str[i] != '\0')
			i++;
	}
	return (word_count);
}

static char		*ft_malloc_word(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char*)malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**table;
	int		word_count;
	int		i;

	word_count = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	word_count = ft_count_words(s, c);
	if (!(table = (char**)malloc(sizeof(char *) * (word_count + 1))))
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			table[i] = ft_malloc_word(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	table[i] = NULL;
	return (table);
}
