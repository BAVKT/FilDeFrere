#include        <mlx.h>
#include        "../includes/fdf.h"
#include        "../includes/mlx.h"
#include        <stdlib.h>
#include        <stdio.h>

void    my_pixel_put_to_image(unsigned long img_color, char *data, int sizeline, int bpp, int x, int y)
{
  unsigned char color1;
  unsigned char color2;
  unsigned char color3;
  color1 = (img_color & 0xFF00000) >> 24;
  color2 = (img_color & 0xFF00000) >> 16;
  color3 = (img_color & 0xFF00000) >> 8;
  data[y * sizeline + x * bpp / 8 ] = color1;
  data[y * sizeline + x * bpp / 8 + 1] = color2;
  data[y * sizeline + x * bpp / 8 + 2] = color3;
}

int     main()
{
  void  *mlx_ptr;
  void  *win_ptr;
  void  *img_ptr;
  char  *data;
  int   bpp;
  int   sizeline;
  int   endian;
  unsigned long img_color;
  int   z;
  int   y;
  z = 0;
  y = 0;
  mlx_ptr = mlx_init();
  img_ptr = mlx_new_image(mlx_ptr, 500, 500);
  data = mlx_get_data_addr(img_ptr, &bpp, &sizeline, &endian);
  img_color = mlx_get_color_value(mlx_ptr, 0xf8f8ff);
  while (z < 500)
    {
      my_pixel_put_to_image(img_color, data, sizeline, bpp, z, y);
      z++;
      if (z == 500 && y < 500)
        {
          z = 0;
          y++;
        }
    }
  win_ptr = mlx_new_window(mlx_ptr, 500, 500, "WOLF SUCK A LOT !" );
  mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
  while (42)
    {
    }
}