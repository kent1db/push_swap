/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:03:16 by qurobert          #+#    #+#             */
/*   Updated: 2021/05/10 12:58:26 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_swap(t_list **num_a, t_list **num_b, char stack)
{
	if (stack == 'a')
	{
		if (*num_b && (*num_b)->next && \
		(int)(*num_b)->content > (int)(*num_b)->next->content)
			ft_sswap_stack(num_a, num_b, 1);
		else
			ft_swap_stack(num_a, stack);
	}
	else
	{
		if (*num_a && (*num_a)->next && \
		(int)(*num_a)->content > (int)(*num_a)->next->content)
			ft_sswap_stack(num_a, num_b, 1);
		else
			ft_swap_stack(num_b, stack);
	}
}

void	ft_check_rev_rotate(t_list **num_a, t_list **num_b, char stack)
{
	if (stack == 'a')
	{
		if (*num_b && \
		(int)(*num_b)->content > (int)ft_lstlast(*num_b)->content)
			ft_rrev_rotate_stack(num_a, num_b, 1);
		else
			ft_rotate_stack(num_a, stack);
	}
	else
	{
		if (*num_a && \
		(int)(*num_a)->content > (int)ft_lstlast(*num_a)->content)
			ft_rrev_rotate_stack(num_a, num_b, 1);
		else
			ft_rotate_stack(num_b, stack);
	}
}

void	ft_check_rotate(t_list **num_a, t_list **num_b, char stack)
{
	if (stack == 'a')
	{
		if (*num_b && (*num_b)->next && \
		(int)(*num_b)->content > (int)(*num_b)->next->content)
			ft_rrotate_stack(num_a, num_b, 1);
		else
			ft_rotate_stack(num_a, stack);
	}
	else
	{
		if (*num_a && (*num_a)->next && \
		(int)(*num_a)->content > (int)(*num_a)->next->content)
			ft_rrotate_stack(num_a, num_b, 1);
		else
			ft_rotate_stack(num_b, stack);
	}
}

void	ft_sort_stack(t_list **begin, t_tab *tab, t_list **other)
{
	while (!ft_is_last(*begin, tab))
	{
		ft_rev_rotate_stack(begin, 'a');
		if (tab->debug)
			ft_print_list(*begin, *other);
	}
}

void	ft_check(t_list **num_a, t_list **num_b, t_tab *tab)
{
	if (*num_a && (*num_a)->next && (int)(*num_a)->content != tab->first &&\
	(int)(*num_a)->next->content != tab->first && \
	(int)(*num_a)->content > (int)(*num_a)->next->content)
	{
		ft_check_swap(num_a, num_b, 'a');
		if (tab->debug)
			ft_print_list(*num_a, *num_b);
	}
	while (*num_a && ft_next(*num_a, tab) && !ft_is_sort(num_a))
	{
		ft_check_rotate(num_a, num_b, 'a');
		if (tab->debug)
			ft_print_list(*num_a, *num_b);
	}
}
