/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 21:33:33 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/14 20:30:07 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Check if file is okay
*/

void	check_file(char *av)
{
	int		i;
	int		fd;
	char	*s;

	if (!ft_strcmp(av, "usage"))
		error(-1);
	if ((fd = open(av, O_RDONLY)) < 0)
		error(3);
	s = ft_strnew(0);
	while (get_next_line(fd, &s) > 0)
	{
		i = 0;
		while (s[i])
		{
			if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '-' && s[i] != 9)
				error(4);
			i++;
		}
		free(s);
	}
	close(fd);
}

/*
** Get the x & y values
*/

void	get_xy(t_base *base, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (line[i] && !ft_isdigit(line[i]))
			i++;
		while (line[i] && ft_isdigit(line[i]))
			i++;
		if (ft_isdigit(line[i - 1]))
			j++;
	}
	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i++]))
		{
			base->d.y++;
			break ;
		}
	}
	base->d.x = (j > base->d.x) ? j : base->d.x;
}

/*
** Fill the z tab
*/

int		get_z(t_base *base, char *line, int j)
{
	int		i;
	int		k;
	char	**c;

	i = 0;
	k = 0;
	c = ft_strsplit(line, ' ');
	while (c[i])
	{
		base->d.z[j] = ft_atoi(c[i]);
		if (base->d.z[j] > base->zmax)
			base->zmax = base->d.z[j];
		else if (base->d.z[j] < base->zmin)
			base->zmin = base->d.z[j];
		j++;
		i++;
	}
	return (j);
}
