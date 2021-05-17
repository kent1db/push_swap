/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:09:59 by qurobert          #+#    #+#             */
/*   Updated: 2021/05/05 13:18:32 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_stack(t_list **begin, char stack)
{
	void	*temp;

	if (!*begin || !(*begin)->next)
		return ;
	temp = (*begin)->content;
	(*begin)->content = (*begin)->next->content;
	(*begin)->next->content = temp;
	if (stack == 'a' || stack == 'b')
		ft_printf("s%c\n", stack);
}

void	ft_push_stack(t_list **begin_from, t_list **begin_to, char stack)
{
	t_list	*temp_from;

	if (!*begin_from)
		return ;
	temp_from = *begin_from;
	*begin_from = (*begin_from)->next;
	temp_from->next = *begin_to;
	*begin_to = temp_from;
	if (stack == 'a' || stack == 'b')
		ft_printf("p%c\n", stack);
}

void	ft_rotate_stack(t_list **begin, char stack)
{
	t_list	*temp;

	if (!*begin || !(*begin)->next)
		return ;
	temp = *begin;
	*begin = (*begin)->next;
	(ft_lstlast(*begin))->next = temp;
	temp->next = NULL;
	if (stack == 'a' || stack == 'b')
		ft_printf("r%c\n", stack);
}

void	ft_rev_rotate_stack(t_list **begin, char stack)
{
	t_list	*temp;
	t_list	*current;

	if (!*begin || !(*begin)->next)
		return ;
	temp = *begin;
	current = *begin;
	*begin = ft_lstlast(*begin);
	while ((current->next)->next)
		current = current->next;
	current->next = NULL;
	(*begin)->next = temp;
	if (stack == 'a' || stack == 'b')
		ft_printf("rr%c\n", stack);
}
