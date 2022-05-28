#include "../incs/so_long.h"

void	close_window(t_data *data)
{
	destroy_img(&data->win, &data->pack);
	mlx_destroy_window(data->win.mlx, data->win.win_ptr);
	mlx_destroy_display(data->win.mlx);
	ft_free(data->map.map);
	free(data->win.mlx);
	exit(EXIT_SUCCESS);
}

void	open_window(t_window *win, t_map *map)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		error_exit();
	win->h = map->nb_lines * IMG_SIZE;
	win->w = map->nb_columns * IMG_SIZE;
	win->win_ptr = mlx_new_window(win->mlx, win->w, win->h, "Run away from fat_bisson");
}
