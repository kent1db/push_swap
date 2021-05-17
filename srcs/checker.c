/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:16:36 by qurobert          #+#    #+#             */
/*   Updated: 2021/05/10 13:48:31 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_stack(t_list **lnum_a, t_list **lnum_b)
{
	float	last_number;
	t_list	*num_a;
	t_list	*num_b;

	last_number = 0.5;
	num_a = *lnum_a;
	num_b = *lnum_b;
	if (num_b)
	{
		ft_printf("KO\n");
		return ;
	}
	while (num_a)
	{
		if (last_number == 0.5 || (int)last_number < (int)(num_a)->content)
			last_number = (int)(num_a)->content;
		else if ((int)last_number > (int)(num_a)->content)
		{
			ft_printf("KO\n");
			return ;
		}
		num_a = (num_a)->next;
	}
	ft_printf("OK\n");
}

void	ft_no_inst(char *line, t_list **num_a, t_list **num_b)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	if (num_b)
		ft_lstclear(num_b, ft_del);
	ft_error(num_a, 1, 1);
}

void	ft_check_instruction(char *line, t_list **num_a, t_list **num_b)
{
	if (!ft_strcmp(line, "sa"))
		ft_swap_stack(num_a, 0);
	else if (!ft_strcmp(line, "sb"))
		ft_swap_stack(num_b, 0);
	else if (!ft_strcmp(line, "ss"))
		ft_sswap_stack(num_a, num_b, 0);
	else if (!ft_strcmp(line, "pa"))
		ft_push_stack(num_b, num_a, 0);
	else if (!ft_strcmp(line, "pb"))
		ft_push_stack(num_a, num_b, 0);
	else if (!ft_strcmp(line, "ra"))
		ft_rotate_stack(num_a, 0);
	else if (!ft_strcmp(line, "rb"))
		ft_rotate_stack(num_b, 0);
	else if (!ft_strcmp(line, "rr"))
		ft_rrotate_stack(num_a, num_b, 0);
	else if (!ft_strcmp(line, "rra"))
		ft_rev_rotate_stack(num_a, 0);
	else if (!ft_strcmp(line, "rrb"))
		ft_rev_rotate_stack(num_b, 0);
	else if (!ft_strcmp(line, "rrr"))
		ft_rrev_rotate_stack(num_a, num_b, 0);
	else
		ft_no_inst(line, num_a, num_b);
}

void	ft_read_standart_input(t_list **num_a, t_list **num_b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		ft_check_instruction(line, num_a, num_b);
		free(line);
		line = NULL;
	}
	ft_check_stack(num_a, num_b);
	if (line)
	{
		free(line);
		line = NULL;
	}
	if (num_b)
		ft_free(NULL, num_b, 0);
}
