/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adondera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:38:42 by adondera          #+#    #+#             */
/*   Updated: 2018/01/12 16:43:56 by adondera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*i;
	t_list	*new;
	t_list	*temp;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new || !lst)
		return (NULL);
	new = f(lst);
	lst = lst->next;
	temp = new;
	while (lst != NULL)
	{
		i = lst->next;
		temp->next = f(lst);
		temp = temp->next;
		if (temp == NULL)
			return (NULL);
		lst = i;
	}
	return (new);
}
