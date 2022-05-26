#include "../incs/so_long.h"

int	main(int ac, char **av)
{
	t_map		map;
	t_window	win;
	t_textures	pack;
	//t_player	player;

	init_map(ac, av, &map);
	open_window(&win, &map);
	display_img(map.map, &win, &pack);
	move_player(); 
	mlx_loop(win.mlx);
	return (0);
}
