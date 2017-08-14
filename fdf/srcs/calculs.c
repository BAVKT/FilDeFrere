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

/*
** Sert a compter le nombre de lignes et de caracteres (win_x && win_y)
*/
//Fonction a retrecir.

int 	*ft_count_xy(char *buf, int fd, int *nblc)
{
	ft_putendl("countxy");
	int i;
	int end;

	while ((end = read(fd, buf, SIZE)))
	{
		buf[end] = '\0';
		i = 0;
		while (buf[i])
		{
			while (buf[i] && buf[i] == ' ')
				i++;
			while (buf[i] && buf[i] != ' ' && buf[i] != '\n')
				i++;
			while (buf[i] && buf[i] == ' ')
				i++;
			if (buf[i] == '\n')
			{
				i++;
				nblc[1]++;
			}
			nblc[0]++;
		}
	}
	nblc[0] = nblc[0]/nblc[1];
	return (nblc);
}



/*
** Convert the 2D values in 3D values
*/

void 	ft_conv_xy(int *countxy)
{
	ft_putendl("convxy");
	int 	i;
	float 	cte;

	i = 0;
	cte = 0.789;
	while (i < countxy[0] * countxy[1])
	{
		g_D2.x[i] = (g_D3.x[i] + cte * g_D3.z[i]);
		g_D2.y[i] = (g_D3.y[i] + (cte/2) * g_D3.z[i]);
		i++;
	}
}
