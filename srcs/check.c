/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:09:10 by qurobert          #+#    #+#             */
/*   Updated: 2021/05/07 16:19:38 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_arg(t_list **num_a, size_t number)
{
	t_list	*new_elem;
	t_list	*check;
	int		num;

	num = 0;
	check = *num_a;
	while (check)
	{
		if ((int)check->content == (int)number)
			ft_error(num_a, 1, 1);
		check = check->next;
	}
	new_elem = ft_lstnew((void *)number);
	ft_lstadd_back(num_a, new_elem);
}

void	ft_check_int(char *str, size_t *number, t_list **num_a)
{
	int		i;
	int		signe;
	int		count;
	long	n;

	i = 0;
	count = 0;
	signe = 1;
	n = 0;
	while (ft_whitespace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			signe = -signe;
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + str[i++] - '0';
		if (++count > 10 || (n * signe) > INT_MAX ||\
		(n * signe) < INT_MIN)
			ft_error(num_a, 1, 1);
	}
	ft_check_special(str, i, n, num_a);
	*number = signe * (int)n;
}

int	ft_isvalid(char *str, t_list **num_a)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+' || ft_isdigit(str[i]) || \
		str[i] == ' ' || (i > 0 && str[i] == 'v' && str[i - 1] == '-'))
			i++;
		else
			ft_error(num_a, 1, 1);
	}
	return (0);
}

void	ft_check_list(char **strs, t_tab *tab, size_t *number, t_list **num_a)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		(tab->nb)++;
		if (!ft_strcmp(strs[i], "-v"))
		{
			tab->debug = 1;
			(tab->nb)--;
		}
		else
		{
			ft_check_int(strs[i], number, num_a);
			ft_list_arg(num_a, *number);
		}
		i++;
	}
}

void	ft_check_arg(int arg_num, char **args, t_list **num_a, t_tab *tab)
{
	int		i;
	int		n;
	size_t	number;
	char	**strs;

	strs = NULL;
	n = 0;
	number = 0;
	tab->debug = 0;
	while (++n < arg_num)
	{
		i = 0;
		ft_isvalid(args[n], num_a);
		strs = ft_split(args[n], ' ');
		if (!strs[i])
			ft_error(num_a, 1, 0);
		ft_check_list(strs, tab, &number, num_a);
		ft_free_tab(strs);
	}
}
