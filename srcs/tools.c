/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:31:42 by qurobert          #+#    #+#             */
/*   Updated: 2021/05/10 13:00:28 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_list *begin)
{
	float	min;

	min = 0.5;
	while (begin)
	{
		if (min == 0.5 || (int)begin->content < min)
			min = (int)begin->content;
		begin = begin->next;
	}
	return ((int)min);
}

int	ft_next(t_list *num_a, t_tab *tab)
{
	int	i;

	i = 0;
	while (num_a && tab->tabl && \
	tab->tabl[i] != (int)ft_lstlast(num_a)->content)
		i++;
	if (i == tab->nb - 1)
		return (0);
	i = i + 1;
	if ((int)num_a->content == tab->tabl[i])
		return (1);
	return (0);
}

void	ft_copy_tab(t_tab *tab)
{
	int	i;

	i = -1;
	tab->tabl = malloc(sizeof(int) * tab->nb);
	if (!tab->tabl)
		ft_error(NULL, 0, 0);
	while (++i < tab->nb)
		tab->tabl[i] = tab->p[i];
}

void	ft_check_special(char *str, int index, int number, t_list **num_a)
{
	if (str[index] != '\0')
		ft_error(num_a, 1, 1);
	if (number == 0 && (str[index - 1] == '+' || str[index - 1] == '-'))
		ft_error(num_a, 1, 1);
}

int	ft_position(t_list *begin, int nb)
{
	int	pos;

	pos = 1;
	while (begin)
	{
		if ((int)begin->content == nb)
			return (pos);
		pos++;
		begin = begin->next;
	}
	return (-1);
}
