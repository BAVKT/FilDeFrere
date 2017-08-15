/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 20:32:51 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/14 22:52:07 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** All the parsing & args errors
*/

void	error_parse(int e)
{
			ft_putendlcolor("error_parse()", MAGENTA);
	ft_putstr("Error: ");
	if (e == -1)
		ft_putendlcolor("Usage: ./fdf map.fdf", GREEN);
	else if (e == 1)
		ft_putstr_fd("Too much args. ", 2);
	else if (e == 2)
		ft_putstr_fd("One arg is needed. ", 2);
	else if (e == 3)
		ft_putstr_fd("File is empty or doesn't exist. ", 2);
	else if (e == 4)
		ft_putstr_fd("Map contain somes wrong char. ", 2);	
	else if (e == 5)
		ft_putstr_fd("Le fichier passé est vide. ", 2);	
	exit(0);
}
