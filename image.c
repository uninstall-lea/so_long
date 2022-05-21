#include "so_long.h"

void	set_image(t_window *win)
{
	int		x;
	int		y;
	t_image	img;
	
	img.path = "./rainbow.xpm";
	img.img = mlx_xpm_file_to_image(win->mlx, img.path, &img.w, &img.h);
	y = 0;
	while(y < win->h)
	{	
		x = 0;
		while (x < win->w)
		{
			mlx_put_image_to_window(win->mlx, win->mlx_win, img.img, x, y);
			x += img.w;
		}
		y += img.h;
	}
	mlx_destroy_image(win->mlx, img.img);
}
