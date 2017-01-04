/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 03:47:30 by vmercadi          #+#    #+#             */
/*   Updated: 2016/12/10 14:19:56 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char const *s, char c)
{
	int i;
	int	nb;

	i = 0;
	nb = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		nb++;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nb);
}

static char		*ft_cp(char const *s, char c, int *i)
{
	int		a;
	char	*s2;

	a = 0;
	s2 = (char *)malloc(sizeof(s2) * (ft_strlen(s)) + 1);
	if (!s2)
		return (NULL);
	while (s[*i] != c && s[*i])
	{
		s2[a] = s[*i];
		a++;
		*i += 1;
	}
	s2[a] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (s2);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		nb;
	char	**s2;

	i = 0;
	j = 0;
	nb = ft_count(s, c);
	if (!s || !c)
		return (NULL);
	s2 = (char **)malloc(sizeof(s) * (nb + 1));
	if (!s2)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		while (j < nb && s[i])
		{
			s2[j] = ft_cp(s, c, &i);
			j++;
		}
		s2[j] = NULL;
	}
	return (s2);
}
