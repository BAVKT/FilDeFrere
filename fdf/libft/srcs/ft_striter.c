/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 00:59:29 by vmercadi          #+#    #+#             */
/*   Updated: 2016/12/10 13:54:57 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int n;
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	n = ft_strlen(s);
	while (i < n)
	{
		f(&s[i]);
		i++;
	}
}