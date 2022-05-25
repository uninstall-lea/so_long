#include "../incs/so_long.h"

static int	move_up(char **map, t_window *win, t_textures *pack, t_player *player)
{
	if (ft_strchr(OBSTACLE, map[player->y - 1] != CANT_MOVE)
	{
		put_image_tp_window(player->x, player->y, win, pack->ground);
		player->y--;
		put_image_to_window(player->x, player->y, win, pack->player);
	}
}

static int move_left(char **map, t_window *win, t_textures *pack, t_player *player)
{
	if (ft_strchr(OBSTACLE, map[player->x - 1] != CANT_MOVE)
		{
			put_image_tp_window(player->x, player->y, win, pack->ground);
			player->x--;
			put_image_to_window(player->x, player->y, win, pack->player);
		}
}

static int move_down(char **map, t_window *win, t_textures *pack, t_player *player)
{
	if (ft_strchr(OBSTACLE, map[player->y + 1] != CANT_MOVE)
	{
		put_image_tp_window(player->x, player->y, win, pack->ground);
		player->y++;
		put_image_to_window(player->x, player->y, win, pack->player);
	}
}

static int move_right(char **map, t_window *win, t_textures *pack, t_player *player)
{
	if (ft_strchr(OBSTACLE, map[player->x + 1] != CANT_MOVE)
	{
		put_image_tp_window(player->x, player->y, win, pack->ground);
		player->x++;
		put_image_to_window(player->x, player->y, win, pack->player);
	}
}

void	move_player(int keycode, char **map, t_window *win, t_textures *pack)
{
	t_player player;

	get_coordinates(PLAYER, map, &player);

	if (keycode == W)
		move_up(map, win, pack, &player);
	else if (keycode == A)
		move_left(map, win, pack, &player);
	else if (keycode == S)
		move_down(map, win, pack, &player);
	else if (keycode == D)
		move_right(map, win, pack, &player);
}
