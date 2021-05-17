/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:48:01 by qurobert          #+#    #+#             */
/*   Updated: 2021/05/07 16:32:56 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*num_a;
	t_list	*num_b;
	t_tab	tab;

	tab.nb = 0;
	num_a = NULL;
	num_b = NULL;
	if (argc < 2)
		ft_error(&num_a, 0, 0);
	else
		ft_check_arg(argc, argv, &num_a, &tab);
	ft_list_to_tab(num_a, &tab);
	ft_resolve_algo(&tab, &num_a, &num_b);
	ft_free(&tab, &num_a, 1);
	return (0);
}
