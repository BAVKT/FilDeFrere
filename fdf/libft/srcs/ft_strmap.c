/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 01:15:39 by vmercadi          #+#    #+#             */
/*   Updated: 2016/12/05 16:25:15 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	int		n;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	n = ft_strlen(s);
	s2 = (char *)malloc(sizeof(char) * (n + 1));
	if (!s2)
		return (NULL);
	while (i < n)
	{
		s2[i] = f(s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
