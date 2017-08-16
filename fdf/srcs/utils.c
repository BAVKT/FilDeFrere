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
** Get the x & y values 
*/

void 	get_xy(t_base *base, char *line)
{
			ft_putendlcolor("get_xy()", MAGENTA);
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 0;
	c = ft_strnew(8);
	while (line[i])
	{
		while (line[i] && !ft_isdigit(line[i]))
			i++;
		while (line[i] && ft_isdigit(line[i]))
			i++;
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
			ft_putendlcolor("get_z()", MAGENTA);
	int		i;
	int		k;
	char	*c;

	i = 0;
	c = ft_strnew(8);
	while (line[i])
	{
		k = 0;
		while (line[i] && !ft_isdigit(line[i]))
			i++;
				ft_putendl("yo");
		base->d.z[j] = (line[i - 1] == '-') ? -1 : 1;
		while (line[i] && ft_isdigit(line[i]))
			c[k++] = line[i++];
		c[k] = '\0';
			ft_putstr("c = ");
			ft_putendl(c);
		base->d.z[j] *= ft_atoi(c);
			ft_putstr("base->d.z = ");
			ft_putnbrendl(base->d.z[j]);
		j++;
		i++;
		//free(c);
	}
	return (j);
}

/*
** Return the interval according to the win_size and x/y
*/
// Sertt a rien parce que return 10

int		get_interval(t_base *base)
{
	int nb;
	int xm;
	int ym;

	nb = 0;
	xm = 2560;
	ym = 1440;
	if (base->d.x > xm / 4 || base->d.y > ym / 4)
		error_parse(5);
	if (base->d.x < xm / 10 && base->d.y < ym / 10)
	{
		if (base->d.x < xm / 50 && base->d.y < ym / 50)
		{
			if (base->d.x < xm / 100 && base->d.y < ym / 100)
				nb = 15;
			nb = 7;
		}
		nb = 2;
	}
	return (20);
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