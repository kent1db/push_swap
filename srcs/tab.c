/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:42:11 by qurobert          #+#    #+#             */
/*   Updated: 2021/05/06 14:11:50 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calc_med(t_tab *tab, int nb, int *t)
{
	int	div;

	div = 5;
	if (tab->nb <= 150)
		div = 3;
	if (nb < div)
		tab->med = t[0];
	else if (nb % 2 == 0)
		tab->med = t[(nb / div) - 1];
	else
		tab->med = t[nb / div];
}

void	ft_calc_new_tab(t_list *begin, t_tab *tab)
{
	int		nb;
	t_list	*temp;
	t_list	*temp2;

	temp = begin;
	temp2 = begin;
	nb = 0;
	tab->start = tab->p[0];
	free(tab->p);
	while (temp && (int)temp->content != tab->first)
	{
		nb++;
		temp = temp->next;
	}
	tab->p = malloc(sizeof(int) * (nb + 1));
	if (!(tab->p))
		ft_error(NULL, 0, 0);
	nb = 0;
	while (begin && (int)begin->content != tab->first)
	{
		tab->p[nb++] = (int)begin->content;
		begin = begin->next;
	}
	ft_sort_int_tab(tab->p, nb);
	ft_calc_med(tab, nb, tab->p);
}

void	ft_list_to_tab(t_list *begin, t_tab *tab)
{
	int	i;

	i = 0;
	tab->p = malloc(sizeof(int) * (tab->nb));
	if (!(tab->p))
		ft_error(NULL, 0, 0);
	while (begin)
	{
		tab->p[i++] = (int)begin->content;
		begin = begin->next;
	}
	ft_sort_int_tab(tab->p, tab->nb);
	ft_copy_tab(tab);
	tab->first = tab->p[0];
	tab->end = tab->p[i - 1];
	ft_calc_med(tab, tab->nb, tab->p);
}

int	ft_give_index_tab(t_tab *tab, int nb)
{
	int	i;

	i = 0;
	while (i != tab->nb)
	{
		if (tab->p[i] == nb)
			return (i);
	}
	return (-1);
}
