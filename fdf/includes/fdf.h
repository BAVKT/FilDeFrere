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
	int 			x;
	int 			y;
	int 			*z;
	int 			*x2;
	int 			*y2;
} 					t_d;

typedef struct 		s_base
{
	void 			*mlx;
	void 			*win;
	int				size;
	int				win_size_x;
	int				win_size_y;
	int				win_size;
	int 			interval;
	char			*av;
	struct	s_d		d;
	struct	s_view	view;
}					t_base;

void				fdf(t_base *base);
void				error_parse(int e);
void				check_file(char *av);
t_base				init_base(t_base *base);
void				init_d(t_base *base);
int					get_interval(t_base *base);
void 				get_xy(t_base *base, char *line);
int					get_z(t_base *base, char *line, int j);

#endif