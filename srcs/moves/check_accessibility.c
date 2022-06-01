#include "../../incs/so_long.h"

static int	can_i_go_to_poney(t_data *data)
{
	if (data->map.nb_collec <= NO_MORE_COLLECTIBLE_LEFT)
		return (CAN_GO_TO_PONEY);
	return (CANT_GO_TO_PONEY);
}

void	check_for_exit(char **map, t_data *data)
{
	if (map[data->player.y][data->player.x] == EXIT)
		if (can_i_go_to_poney(data) == CAN_GO_TO_PONEY)
		{
			put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.player);
			close_window(data);
		}
}

void	check_for_collec(char **map, t_data *data)
{
	if (map[data->player.y][data->player.x] == COLLEC)
	{
		data->map.nb_collec--;
		map[data->player.y][data->player.x] = '0';
	}
}

int	check_accessibility(char c, t_data *data)
{
	if (c == BORDER || (c == EXIT && can_i_go_to_poney(data) == CANT_GO_TO_PONEY))
	{
		printf("pb11\n");
		return (CANT_MOVE);
	}
	printf("pb12\n");
	return (CAN_MOVE);
}

int decrease(char where, char **map, t_data *data)
{
	if (where == 'y')
	{
		printf("pb13\n");
		return (check_accessibility(map[data->player.y - 1][data->player.x],
				data));
	}
	else if (where == 'x')
	{
		printf("pb14\n");
		return (check_accessibility(map[data->player.y][data->player.x - 1],
				data));
	}
	printf("pb15\n");
	return (CANT_MOVE);
}

int increase(char where, char **map, t_data *data)
{
	if (where == 'y')
	{
		printf("pb13\n");
		if (map[data->player.y+1][data->player.x])
			return (check_accessibility(map[data->player.y + 1][data->player.x],
				data));
	}
	else if (where == 'x')
	{
		printf("pb14\n");
		return (check_accessibility(map[data->player.y][data->player.x + 1],
				data));
	}
	printf("pb15\n");
	return (CANT_MOVE);
}
