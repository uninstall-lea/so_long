#include "so_long.h"

int	main(int ac, char **av)
{
	t_map		map;
	t_window	win;

	read_map(ac, av, &map);
	open_window(&win, &map);
	set_map(map.map, &win);
	mlx_loop(win.mlx);
	return (0);
}
