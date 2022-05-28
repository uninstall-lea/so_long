#include "../incs/so_long.h"

int	main(int ac, char **av)
{
	t_data		data;

	data.nb_moves = 0;
	init_map(ac, av, &data.map);
	open_window(&data.win, &data.map);
	display_img(data.map.map, &data.win, &data.pack);
	get_coordinates(PLAYER, data.map.map, &data.player);
	mlx_key_hook(data.win.win_ptr, handle_events, &data);
	mlx_loop(data.win.mlx);
	return (0);
}
