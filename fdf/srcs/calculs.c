/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:43:13 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/14 18:48:43 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Convert the 2D values in 3D values
*/

void 	conv_xy(t_base *base)
{
			ft_putendlcolor("conv_xy()", MAGENTA);
	int 	i;
	float 	cte;

	i = 0;
	cte = 0.789;
	while (i < (base->nblc[0] * base->nblc[1]))
	{
		base->d.x2[i] = (base->d.x[i] + cte * base->d.z[i]);
		base->d.y2[i] = (base->d.y[i] + (cte/2) * base->d.z[i]);
		i++;
	}
}
