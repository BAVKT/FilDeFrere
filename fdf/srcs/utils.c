/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:46:46 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/14 22:52:08 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Fill the x tab
*/

void 	get_xyz(t_d *d, char *line)
{
			ft_putendlcolor("get_x()", MAGENTA);
	int		i;
	int		j;
	int		k;
	char	*c;

	i = 0;
	j = 1;
	c = ft_strnew(8);
	while (line[i])
	{
		k = 0;
		while (line[i] && !ft_isdigit(line[i]))
			i++;
		d->z[j] = (line[i - 1] == '-') ? -1 : 1;
		while (line[i] && ft_isdigit(line[i]))
			c[k++] = line[i++];
		c[k] = '\0';
		d->x[j] = j;
		d->y[j] = j;
		d->z[j] *= ft_atoi(c);
		j++;
		i++;
		free(c);
	}
}











//############################################################################################
//############################################################################################
//############################################################################################

// /*
// ** Rempli le tableau de valeurs 3D en x et renvoi le tableau rempli.
// */
// //Fuionner les 2 voir les 3 et utiliser ft_range 

// void 	ft_rempx(int x, int y)
// {
// 	ft_putendl("rempx");
// 	int 	i;
// 	int 	j;
// 	int 	k;

// 	i = 0;
// 	j = 0;
// 	k = 1;
// 	while (j <= x * y)
// 	{
// 		if (k == x + 1)
// 			k = 1;
// 		g_D3.x[i++] = k++;
// 		j++;
// 	}
// }


// /*
// ** Fill the Y tab
// */

// void 	ft_rempy(int y, int x)
// {
// 	ft_putendl("rempy");
// 	int 	i;
// 	int 	j;
// 	int 	k;

// 	i = 0;
// 	j = 0;
// 	k = 1;
// 	while (j <= y * x)
// 	{
// 		if (k == y + 1)
// 			k = 1;
// 		g_D3.y[i++] = k++;
// 		j++;
// 	}
// }

// /*
// ** Fill the Z tab
// */

// void 	ft_rempz(char *buf, int fd)
// {
// 	ft_putendl("rempz");
// 	int 	end;
// 	char 	**tabc;		//Le retour de strsplit, double tableau de char
// 	int 	i;
// 	int 	j;

// 	j = 0;
// 	while ((end = read(fd, buf, SIZE)) > 0)
// 	{
// 		i = 0;
// 		buf[end] = '\0';
// 		tabc = ft_strsplit((const char *)buf, ' ');			
// 		while (tabc[i])
// 			g_D3.z[j++] = ft_atoi(tabc[i++]); 	//On converti le resultat dans le tableau.
// 	}
// }