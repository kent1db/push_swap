/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:19:26 by qurobert          #+#    #+#             */
/*   Updated: 2021/03/30 11:07:34 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s == NULL)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(str))
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, ((char *)s)[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
