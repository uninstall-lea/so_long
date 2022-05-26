#include "../incs/so_long.h"

static int	close_window(int keycode, t_window *win)
{
	printf("%d\n", keycode);
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(win->mlx, win->win_ptr);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	open_window(t_window *win, t_map *map)
{
	win->mlx = mlx_init();
	if (!win->mlx)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	win->h = map->nb_lines * IMG_SIZE;
	win->w = map->nb_columns * IMG_SIZE;
	win->win_ptr = mlx_new_window(win->mlx, win->w, win->h, "Run away from fat_bisson");
}
