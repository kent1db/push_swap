/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:47:07 by qurobert          #+#    #+#             */
/*   Updated: 2021/05/05 14:37:14 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_loop(t_list **lst, void *(*f)(void *), void (*del)(void *),
		t_list **current)
{
	while (*lst != NULL)
	{
		(*current)->next = ft_lstnew((*f)((*lst)->content));
		if (!((*current)->next))
		{
			ft_lstclear(lst, del);
			return (0);
		}
		*current = (*current)->next;
		*lst = (*lst)->next;
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*begin;

	if (lst != NULL && f != NULL)
	{
		begin = ft_lstnew((*f)(lst->content));
		if (!(begin))
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		current = begin;
		lst = lst->next;
	}
	if (!(ft_loop(&lst, f, del, &current)))
		return (NULL);
	current->next = NULL;
	return (begin);
}
