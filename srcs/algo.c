/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:26:43 by qurobert          #+#    #+#             */
/*   Updated: 2021/05/07 13:47:08 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo(t_list **num_a, t_list **num_b, t_tab *tab)
{
	int	loop;

	loop = 1;
	while (!ft_is_sort(num_a))
	{
		ft_check(num_a, num_b, tab);
		ft_push_med_to_b(num_a, num_b, tab, loop);
		ft_check(num_a, num_b, tab);
		if (!loop)
			ft_sort_stack(num_a, tab, num_b);
		ft_check(num_a, num_b, tab);
		ft_push_med_to_a(num_a, num_b, tab);
		ft_check(num_a, num_b, tab);
		ft_calc_new_tab(*num_a, tab);
		loop = 0;
	}
}

void	ft_algo_three(t_list **num_a)
{
	int		x;
	int		y;
	int		z;

	while (!(ft_is_sort(num_a)))
	{
		x = (int)(*num_a)->content;
		y = (int)(*num_a)->next->content;
		z = (int)(*num_a)->next->next->content;
		if (x > y && x > z)
			ft_rotate_stack(num_a, 'a');
		else if (x > y)
			ft_swap_stack(num_a, 'a');
		else if (y > z)
			ft_rev_rotate_stack(num_a, 'a');
	}
}

void	ft_algo_five(t_list **num_a, t_list **num_b, t_tab *tab)
{
	int	i;

	i = tab->nb - 3;
	while (i)
	{
		while (!ft_is_first_sort(*num_a))
		{
			if (ft_min_position(*num_a) < 4)
				ft_rotate_stack(num_a, 'a');
			else if (ft_min_position(*num_a) > 3)
				ft_rev_rotate_stack(num_a, 'a');
		}
		if (!ft_is_sort(num_a))
			ft_push_stack(num_a, num_b, 'b');
		i--;
	}
	if (!ft_is_sort(num_a))
		ft_algo_three(num_a);
	while (*num_b)
		ft_push_stack(num_b, num_a, 'a');
}

void	ft_resolve_algo(t_tab *tab, t_list **num_a, t_list **num_b)
{
	if (tab->nb < 2)
		return ;
	if (tab->debug)
		ft_print_list(*num_a, *num_b);
	if (tab->nb <= 3)
		ft_algo_three(num_a);
	else if (tab->nb <= 5)
		ft_algo_five(num_a, num_b, tab);
	else
		ft_algo(num_a, num_b, tab);
	if (tab->debug)
		ft_print_list(*num_a, *num_b);
}
