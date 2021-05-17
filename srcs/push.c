/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:05:48 by qurobert          #+#    #+#             */
/*   Updated: 2021/05/07 15:17:18 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_into_b(int nb, t_list **num_a, t_list **num_b, t_tab *tab)
{
	while (ft_position(*num_a, nb) != 1)
	{
		if (ft_position(*num_a, nb) <= (tab->nb / 2) + 1)
			ft_check_rotate(num_a, num_b, 'a');
		else
			ft_check_rev_rotate(num_a, num_b, 'a');
		if (tab->debug)
			ft_print_list(*num_a, *num_b);
	}
	ft_push_stack(num_a, num_b, 'b');
	if (tab->debug)
		ft_print_list(*num_a, *num_b);
}

void	ft_push_into_a(t_tab *tab, t_list **num_a, t_list **num_b)
{
	int	size;

	size = ft_lstsize(*num_b);
	while (*num_b && !ft_is_first_sort(*num_b))
	{
		if (ft_min_position(*num_b) <= (size / 2) + 1)
			ft_rotate_stack(num_b, 'b');
		else
			ft_rev_rotate_stack(num_b, 'b');
		if (tab->debug)
			ft_print_list(*num_a, *num_b);
	}
	ft_push_stack(num_b, num_a, 'a');
	if (tab->debug)
		ft_print_list(*num_a, *num_b);
}

void	ft_push_med_to_b(t_list **num_a, t_list **num_b, t_tab *tab, int bool)
{
	t_list	*current;

	current = *num_a;
	while (current)
	{
		if (!bool && (int)current->content == tab->first)
			return ;
		if ((int)current->content <= tab->med)
		{
			ft_push_into_b((int)current->content, num_a, num_b, tab);
			current = *num_a;
		}
		else
			current = current->next;
	}
}

void	ft_push_med_to_a(t_list **num_a, t_list **num_b, t_tab *tab)
{
	t_list	*current;

	current = *num_b;
	while (current)
	{
		if ((int)current->content == ft_min(*num_b))
		{
			ft_push_into_a(tab, num_a, num_b);
			ft_check_rotate(num_a, num_b, 'a');
			if (tab->debug)
				ft_print_list(*num_a, *num_b);
			current = *num_b;
		}
		else
			current = current->next;
	}
}
