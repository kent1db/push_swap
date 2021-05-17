/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:08:58 by qurobert          #+#    #+#             */
/*   Updated: 2021/05/07 13:41:06 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sort(t_list **num_a)
{
	float	last_number;
	t_list	*current;

	current = *num_a;
	last_number = 0.5;
	while (current)
	{
		if (last_number == 0.5 || (int)last_number < (int)current->content)
		{
			last_number = (int)current->content;
			current = current->next;
		}
		else
			return (0);
	}
	return (1);
}

int	ft_is_first_sort(t_list *num_a)
{
	int		x;
	t_list	*current;

	x = (int)num_a->content;
	current = num_a->next;
	while (current)
	{
		if ((int)current->content < x)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_min_position(t_list *current)
{
	int		min;
	float	pos;
	int		i;

	i = 0;
	min = 0;
	pos = 0.5;
	while (current)
	{
		i++;
		if (pos == 0.5 || (int)current->content < min)
		{
			pos = i;
			min = (int)current->content;
		}
		current = current->next;
	}
	return (pos);
}

int	ft_is_last(t_list *begin, t_tab *tab)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = begin;
	while (begin && tab && (int)begin->content != tab->first)
		begin = begin->next;
	while (begin)
	{
		if ((int)begin->content != tab->tabl[i])
			return (0);
		begin = begin->next;
		i++;
	}
	return (1);
}

int	ft_last_num(t_list *begin_a, t_list *begin_b, t_tab *tab)
{
	int	count;

	count = 0;
	if (begin_b != NULL)
		return (0);
	while (begin_a && (int)begin_a->content != tab->start)
	{
		count++;
		begin_a = begin_a->next;
	}
	if (count == 3)
		return (1);
	else
		return (0);
}
