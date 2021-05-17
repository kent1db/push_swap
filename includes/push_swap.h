/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:34:32 by qurobert          #+#    #+#             */
/*   Updated: 2021/05/07 16:32:33 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "color.h"

typedef struct s_tab
{
	int	*p;
	int	*tabl;
	int	nb;
	int	med;
	int	start;
	int	first;
	int	end;
	int	i;
	int	debug;
}	t_tab;

void	ft_check_arg(int arg_num, char **args, t_list **num_a, t_tab *tab);
void	ft_check_special(char *str, int index, int number, t_list **num_a);
void	ft_copy_tab(t_tab *tab);
int		ft_next(t_list *num_a, t_tab *tab);
int		ft_min(t_list *begin);

void	ft_free_tab(char **strs);
void	ft_error(t_list **to_free, int bool, int msg);
void	ft_del(void *to_del);
void	ft_free(t_tab *tab, t_list **begin, int bool);

void	ft_print_list(t_list *begin_a, t_list *begin_b);

void	ft_swap_stack(t_list **begin, char stack);
void	ft_push_stack(t_list **begin_from, t_list **begin_to, char stack);
void	ft_rotate_stack(t_list **begin, char stack);
void	ft_rev_rotate_stack(t_list **begin, char stack);

void	ft_rrotate_stack(t_list **begin_a, t_list **begin_b, int bool);
void	ft_sswap_stack(t_list **begin_a, t_list **begin_b, int bool);
void	ft_rrev_rotate_stack(t_list **begin_a, t_list **begin_b, int bool);

void	ft_read_standart_input(t_list **num_a, t_list **num_b);
void	ft_resolve_algo(t_tab *tab, t_list **num_a, t_list **num_b);

void	ft_list_to_tab(t_list *begin, t_tab *tab);
int		ft_give_index_tab(t_tab *tab, int nb);
void	ft_calc_med(t_tab *tab, int nb, int *t);
void	ft_calc_new_tab(t_list *begin, t_tab *tab);

void	ft_algo(t_list **num_a, t_list **num_b, t_tab *tab);
void	ft_algo_three(t_list **num_a);
void	ft_algo_five(t_list **num_a, t_list **num_b, t_tab *tab);
void	ft_resolve_algo(t_tab *tab, t_list **num_a, t_list **num_b);

int		ft_position(t_list *begin, int nb);
int		ft_is_sort(t_list **num_a);
int		ft_is_first_sort(t_list *num_a);
int		ft_min_position(t_list *current);
int		ft_is_last(t_list *begin, t_tab *tab);
int		ft_last_num(t_list *begin_a, t_list *begin_b, t_tab *tab);

void	ft_push_med_to_a(t_list **num_a, t_list **num_b, t_tab *tab);
void	ft_push_med_to_b(t_list **num_a, t_list **num_b, t_tab *tab, int bool);
void	ft_push_into_a(t_tab *tab, t_list **num_a, t_list **num_b);
void	ft_push_into_b(int nb, t_list **num_a, t_list **num_b, t_tab *tab);
int		ft_no_more_to_push(t_list *begin, t_tab *tab);

void	ft_check_rotate(t_list **num_a, t_list **num_b, char stack);
void	ft_check_rev_rotate(t_list **num_a, t_list **num_b, char stack);
void	ft_check_swap(t_list **num_a, t_list **num_b, char stack);
void	ft_sort_stack(t_list **begin, t_tab *tab, t_list **other);
void	ft_check(t_list **num_a, t_list **num_b, t_tab *tab);

#endif