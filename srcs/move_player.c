#include "../incs/so_long.h"

static int	move_up(char **map, t_player *player)
{
	if (ft_strchr(OBSTACLE, map[player->y - 1] != CANT_MOVE)
	{
		player->y--;
		
	}


}

static int move_left(char **map, t_player *player)
{

}

static int move_down(char **map, t_player *player)
{

}

static int move_right(char **map, t_player *player)
{

}

void	move_player(int keycode, char **map, t_textures *pack, t_player *player)
{
	player->y = 0;
	player->x = 0;

	if (keycode == W)
		move_up(map, player);
	else if (keycode == A)
		move_left(map, player);
	else if (keycode == S)
		move_down(map, player);
	else if (keycode == D)
		move_right(map, player);
}
