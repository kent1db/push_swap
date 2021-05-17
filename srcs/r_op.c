/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:37:41 by qurobert          #+#    #+#             */
/*   Updated: 2021/04/26 08:52:36 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sswap_stack(t_list **begin_a, t_list **begin_b, int bool)
{
	ft_swap_stack(begin_a, 0);
	ft_swap_stack(begin_b, 0);
	if (bool)
		ft_printf("ss\n");
}

void	ft_rrotate_stack(t_list **begin_a, t_list **begin_b, int bool)
{
	ft_rotate_stack(begin_a, 0);
	ft_rotate_stack(begin_b, 0);
	if (bool)
		ft_printf("rr\n");
}

void	ft_rrev_rotate_stack(t_list **begin_a, t_list **begin_b, int bool)
{
	ft_rev_rotate_stack(begin_a, 0);
	ft_rev_rotate_stack(begin_b, 0);
	if (bool)
		ft_printf("rrr\n");
}
