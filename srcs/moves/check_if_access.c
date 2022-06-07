#include "../../incs/so_long.h"

int	can_i_go_to_poney(char **map, t_player *player, t_data *data)
{
	if (map[player->y][player->x] == EXIT
		&& data->map.nb_collec <= NO_MORE_COLLECTIBLE_LEFT)
	{
		move_player_on_window(data);
		close_window(data);
	}
	return (NO);
}

static void	if_collec(char *c, t_data *data)
{
		*c = '0';
		data->map.nb_collec--;
}

static int	check_if_access(char c, t_data *data)
{
	if (c == BORDER
		|| (c == EXIT && data->map.nb_collec > 0))
		return (CANT_MOVE); 
	if (c == COLLEC)
		if_collec(&c, data);
	return (CAN_MOVE);
}

int	decrease_P(char where, char **map, t_player *player, t_data *data)
{
	if (where == 'y')
		return (check_if_access(map[player->y - 1][player->x], data));
	else if (where == 'x')
		return (check_if_access(map[player->y][player->x - 1], data));
	return (CANT_MOVE);
}

int	increase_P(char where, char **map, t_player *player, t_data *data)
{
	if (where == 'y' && map[player->y + 1][player->x])
		return (check_if_access(map[player->y + 1][player->x], data));
	else if (where == 'x')
		return (check_if_access(map[player->y][player->x + 1],  data));
	return (CANT_MOVE);
}
