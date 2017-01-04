/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 01:04:18 by vmercadi          #+#    #+#             */
/*   Updated: 2016/12/10 13:55:13 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int				n;
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	if (!s || !f)
		return ;
	n = ft_strlen(s);
	if (!n)
		return ;
	while (j < n)
	{
		f(i, &s[j]);
		i++;
		j++;
	}
}
