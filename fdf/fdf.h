/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:36:30 by vmercadi          #+#    #+#             */
/*   Updated: 2016/12/10 22:58:03 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include <sys/types.h>		//Les Headers nécéssaire
#include <sys/stat.h>
#include <fcntl.h>
#define SIZE 42

//Les coordonees du point de vue. Le x et y correspondent aux tailles de la fenettre divisé par deux 
//et le z represente la distance approximative entre nous et l'ecran. On va dire 1000.
typedef struct 	s_view
{
	float 		x;
	float 		y;
	float 		z;
}				t_view;
//Les coordonees D3 donc recuperees avec les autres fonctions
typedef struct 	s_D3
{
	float 		*x;
	float 		*y;
	float 		*z;
}				t_D3;

//La conversion des donees D3 en donnees D2.
typedef struct 	s_D2
{
	float 		*x;
	float 		*y;
} 				t_D2;

t_D3            g_D3;
t_D3            g_D2;
