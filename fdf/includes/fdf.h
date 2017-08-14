/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:36:30 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/14 22:42:44 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H
#include "mlx.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#define SIZE 42

//Les coordonees du point de vue. Le x et y correspondent aux tailles de la fenettre divisé par deux 
//et le z represente la distance approximative entre nous et l'ecran. On va dire 1000.
typedef struct 		s_view
{	
	double 			vx;
	double 			vy;
	double 			vz;
}					t_view;
	
typedef struct 		s_d
{	
	double 			*x;
	double 			*y;
	double 			*z;
	double 			*x2;
	double 			*y2;
} 					t_d;

typedef struct 		s_base
{
	void 			*mlx;
	void 			*win;
	int 			size;
	int 			interval;
	struct	s_d		d;
	struct	s_view	view;
}					t_base;

void				fdf(t_base *base);
void				error_parse(int e);
void				check_file(char *av);
t_base				init_base(t_base *base);
t_d					init_d(t_d *d);

#endif