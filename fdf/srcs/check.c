/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 21:33:33 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/31 17:10:39 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Check if file is okay
*/

void	check_file(char *av)
{
			ft_putendlcolor("check_file()", MAGENTA);	
	int		i;
	int		fd;
	char	*s;

	if (!ft_strcmp(av, "usage"))
		error_parse(-1);
	if ((fd = open(av, O_RDONLY)) < 0)
		error_parse(3);
	s = ft_strnew(0);
	while (get_next_line(fd, &s) > 0)
	{
		i = 0;
		while (s[i])
		{
			if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '-' && s[i] != 9)
				error_parse(4);
			i++;
		}
		free(s);
	}
	close(fd);
}
