/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 03:03:51 by vmercadi          #+#    #+#             */
/*   Updated: 2016/12/05 16:24:21 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_scount(const char *s)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		i++;
		nb++;
	}
	if (s[i])
	{
		i = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i--;
			nb++;
		}
	}
	return (ft_strlen(s) - nb);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		nb;
	char	*s2;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	nb = ft_scount(s);
	s2 = (char *)malloc(sizeof(char) * (nb + 1));
	if (!s2)
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (j < nb)
	{
		s2[j] = s[i];
		i++;
		j++;
	}
	s2[j] = '\0';
	return (s2);
}
