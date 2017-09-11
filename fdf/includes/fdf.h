/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:36:30 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/11 17:00:07 by vmercadi         ###   ########.fr       */
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
	double			vx;
	double			vy;
	double			vz;
	double			zoom;
}					t_view;
	
typedef struct 		s_d
{	
	int				x;
	int				y;
	int				*z;
} 					t_d;

typedef struct 		s_base
{
	void 			*mlx;
	void 			*win;
	void			*img;		//Stocke les valeurs RGB sur les 8/16/24 bits de chaque case
	int				*data;
	int				alt;
	int				size;
	int				win_x;
	int				win_y;
	int				zmax;
	int				zmin;
	int				win_size;
	int 			interval;
	char			**av;
	struct	s_d		d;
	struct	s_view	view;
	int				endian;		//Ordre dans lequel on stocke les bits dans les octets
	int				sizeline;	//La taille d'une ligne
	unsigned int	color;		//La couleur qu'on passe a get_color_value
	int				bpp;
	int				dx;
	int				dy;
	int				x;
	int				y;
	int				xi;
	int				yi;
	int				xj;
	int				yj;
	int				*x2;
	int				*y2;
}					t_base;

typedef	struct		s_disp
{
	int				ofs;		//Offset
	int				endian;		//Ordre dans lequel on stocke les bits dans les octets
	int				sizeline;	//La taille d'une ligne
	int				bpp;
	int				img_color;	//Le retour de get_color_value
}					t_disp;

/*
** Inits
*/

t_base				init_base(t_base *base);
t_disp				init_display(t_base *base);
void				init_d(t_base *base);
void				init_image(t_base *base);

/*
** Parsing
*/

void				error_parse(int e);
void				check_file(char *av);
int					get_interval(t_base *base);
void 				get_xy(t_base *base, char *line);
int					get_z(t_base *base, char *line, int j);

/*
** Conv
*/

void 				conv_iso(t_base *base, int n, int *z, int i);
//void 				conv_iso(t_base *base, int x, int y);
void				conv_para(t_base *base, int x, int y, int z);
void 				conv_xy(t_base *base, int z);
void				get_pos(t_base *base, int i);

/*
** Display & drawing
*/

void				fdf(t_base *base);
void				draw_hori(t_base *base);
void				draw_verti(t_base *base);
void				start_line(t_base *base);
void				line1(t_base *base, int xx, int yy);
void				line2(t_base *base, int xx, int yy);
void				px_img(t_base *base, int x, int y, int color);

/*
** Colors
*/

void				get_color(t_base *base, int z);
int					get_gradiant(t_base *base, int z, unsigned int color);

/*
** Event
*/

int					event(int keycode, void *param);
void				move(int k, t_base *base);
void				refresh(t_base *base);

#endif