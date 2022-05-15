#include "so_long.h"

void	set_image(t_window *win)
{
	int		x;
	int		y;
	t_image sol;
	
	sol.path = "./sol.xpm";
	sol.img = mlx_xpm_file_to_image(win->mlx, sol.path, &sol.w, &sol.h);
	y = 0;
	while(y < win->h)
	{	
		x = 0;
		while (x < win->w)
		{
			mlx_put_image_to_window(win->mlx, win->mlx_win, sol.img, x, y);
			x += sol.w;
		}
		y += sol.h;
	}
	mlx_destroy_image(win->mlx, sol.img);
}
