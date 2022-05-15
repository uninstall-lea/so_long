#include "so_long.h"

int	main(int ac, char **av)
{
	t_window win;

	read_map(ac, av);
	open_window(&win);
	set_image(&win);
	mlx_loop(win.mlx);
	return (0);
}
