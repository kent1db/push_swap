/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:33:51 by qurobert          #+#    #+#             */
/*   Updated: 2021/05/07 17:59:30 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_green(t_list *begin, int *last_number)
{
	if (!begin)
		ft_printf("|\t\t|");
	else
	{
		if (ft_count_int((int)begin->content) > 7)
		{
			*last_number = (int)begin->content;
			ft_printf("|   %s%d%s\t|", BGRN, (int)begin->content, RESET);
		}
		else
		{
			*last_number = (int)begin->content;
			ft_printf("|\t%s%d%s\t|", BGRN, (int)begin->content, RESET);
		}
	}
}

void	ft_print_red(t_list *begin, int *brake)
{
	if (!begin)
		ft_printf("|\t\t|");
	else
	{
		if (ft_count_int((int)begin->content) > 7)
		{
			*brake = 1;
			ft_printf("|   %s%d%s\t|", BRED, (int)begin->content, RESET);
		}
		else
		{
			*brake = 1;
			ft_printf("|\t%s%d%s\t|", BRED, (int)begin->content, RESET);
		}
	}
}

void	ft_print_tail(void)
{
	write(1, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 34);
	ft_printf("|    STACK A    ||    STACK B   |\n");
	write(1, "---------------------------------\n", 34);
}

void	ft_print_body(t_list *begin, int *last_number, int *brake)
{
	if (begin)
	{
		if ((!*last_number || *last_number < (int)begin->content) && !*brake)
			ft_print_green(begin, last_number);
		else
			ft_print_red(begin, brake);
	}
	else
		ft_printf("|\t\t|");
}

void	ft_print_list(t_list *begin_a, t_list *begin_b)
{
	int	brake_a;
	int	brake_b;
	int	last_number_a;
	int	last_number_b;

	brake_a = 0;
	brake_b = 0;
	last_number_a = 0;
	last_number_b = 0;
	dprintf(1, "\e[2J");
	write(1, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 34);
	while (begin_a || begin_b)
	{
		ft_print_body(begin_a, &last_number_a, &brake_a);
		ft_print_body(begin_b, &last_number_b, &brake_b);
		write(1, "\n", 1);
		if (begin_a)
			begin_a = begin_a->next;
		if (begin_b)
			begin_b = begin_b->next;
	}
	ft_print_tail();
	usleep(800000);
}
