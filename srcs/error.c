/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:53:40 by qurobert          #+#    #+#             */
/*   Updated: 2021/05/10 13:21:06 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_tab *tab, t_list **begin, int bool)
{
	if (begin)
		ft_lstclear(begin, ft_del);
	if (bool)
	{
		if (tab->p)
		{
			free(tab->p);
			tab->p = NULL;
		}
		if (tab->tabl)
		{
			free(tab->tabl);
			tab->tabl = NULL;
		}
	}
}

void	ft_free_tab(char **strs)
{
	int	a;

	a = -1;
	while (strs[++a] != NULL)
		free(strs[a]);
	free(strs);
}

void	ft_del(void *to_del)
{
	to_del = NULL;
}

void	ft_error(t_list **to_free, int bool, int msg)
{
	if (bool)
		ft_lstclear(to_free, ft_del);
	if (msg)
		ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
