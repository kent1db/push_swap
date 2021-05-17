/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:42:56 by qurobert          #+#    #+#             */
/*   Updated: 2021/04/07 17:37:05 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_string_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab[i] == NULL)
		return ;
	if (tab[i + 1] != NULL)
		i++;
	else
		return ;
	while (tab[i] != NULL)
	{
		if (ft_strcmp(tab[i - 1], tab[i]) > 0)
		{
			ft_swap_str(&tab[i - 1], &tab[i]);
			i = 0;
		}
		i++;
	}
}
