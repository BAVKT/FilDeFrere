/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:46:46 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/06 17:20:33 by vmercadi         ###   ########.fr       */
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
	char	**c;

	i = 0;
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

/*
** Return the interval according to the win_size and x/y
*/
// Sert a rien parce que return 10

int		get_interval(t_base *base)
{
			ft_putendlcolor("get_interval()", MAGENTA);
	int nb;
	int xm;
	int ym;

	nb = 0;
	xm = 2560;
	ym = 1440;
	if (base->d.x * 10 > xm || base->d.y * 10 > ym)
		nb = 5;
	else if (base->d.x * 10 > xm / 1.5 || base->d.y * 10 > ym / 1.5)
		nb = 7;
	else if (base->d.x * 10 > xm / 2 || base->d.y * 10 > ym / 2)
		nb = 10;
	else if (base->d.x * 10 > xm / 3 || base->d.y * 10 > ym / 3)
		nb = 12;
	else if (base->d.x * 10 > xm / 4 || base->d.y * 10 > ym / 4)
		nb = 20;
	else if (base->d.x * 10 > xm / 10 || base->d.y * 10 > ym / 10)
		nb = 27;
	else if (base->d.x * 10 > xm / 20 || base->d.y * 10 > ym / 20)
		nb = 40;
	else if (base->d.x * 10 > xm / 40 || base->d.y * 10 > ym / 40)
		nb = 50;
	else
		nb = 70;
		ft_putnbrendl(base->d.x);
		ft_putnbrendl(base->d.y);
		ft_putnbrendl(nb);
	return (nb);
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