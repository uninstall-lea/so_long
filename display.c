#include "so_long.h"

static void	convert_all_xpm(t_window *win, t_textures *set)
{
	set->exit.img = mlx_xpm_file_to_image(win->mlx, set->exit.path,
						&set->exit.w, &set->exit.h);
	set->ground.img = mlx_xpm_file_to_image(win->mlx, set->ground.path,
						&set->ground.w, &set->ground.h);
	set->border.img = mlx_xpm_file_to_image(win->mlx, set->border.path,
						&set->border.w, &set->border.h);
	set->collec.img = mlx_xpm_file_to_image(win->mlx, set->collec.path,
						&set->collec.w, &set->collec.h);
	set->player.img = mlx_xpm_file_to_image(win->mlx, set->player.path,
						&set->player.w, &set->player.h);
	set->enemies.img = mlx_xpm_file_to_image(win->mlx, set->enemies.path,
						&set->enemies.w, &set->enemies.h);
}

static void	put_image_to_window(int x, int y, t_window *win, t_image put)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, put.img,
	x * IMG_SIZE, y * IMG_SIZE);
}

static void	set_textures(t_window *win, t_textures *set)
{	
	set->collec.path = "./doll.xpm";
	set->ground.path = "./rainbow.xpm";
	set->exit.path = "./rainbow_dash.xpm";
	set->border.path = "./malicious_star.xpm";
	set->player.path = "./lbisson_de_noel.xpm";
	set->enemies.path = "./evil_fat_bisson.xpm";
	convert_all_xpm(win, set);
}

void	set_map(char **map, t_window *win)
{
	int			x;
	int			y;
	t_textures	set;
	
	y = 0;
	set_textures(win, &set);
	while (y * IMG_SIZE < win->h)
	{
		x = 0;
		while (x * IMG_SIZE < win->w)
		{
			if (map[y][x] == EXIT)
				put_image_to_window(x, y, win, set.exit);
			else if (map[y][x] == GROUND)
				put_image_to_window(x, y, win, set.ground);
			else if (map[y][x] == BORDER)
				put_image_to_window(x, y, win, set.border);
			else if (map[y][x] == COLLEC)
				put_image_to_window(x, y, win, set.collec);
			else if (map[y][x] == PLAYER)
				put_image_to_window(x, y, win, set.player);
			else if (map[y][x] == ENEMIES)
				put_image_to_window(x, y, win, set.enemies);
			x++;
			
		}
		y++;
	}
}
