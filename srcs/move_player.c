#include "../incs/so_long.h"

static void	count_and_print_my_moves(t_data *data)
{
	ft_putnbr_fd(++data->nb_moves, 1);
	write(1, "\n", 1);
}

void	move_up(char **map, t_data *data)
{
	if (ft_strchr(OBSTACLE, map[data->player.y - 1][data->player.x]) == CAN_MOVE)
	{
		put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.ground);
		data->player.y--;
		put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.player);
		count_and_print_my_moves(data);
	}
}

void move_left(char **map, t_data *data)
{
	if (ft_strchr(OBSTACLE, map[data->player.y][data->player.x - 1]) == CAN_MOVE)
	{
		put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.ground);
		data->player.x--;
		put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.player);
		count_and_print_my_moves(data);
	}
}

void move_down(char **map, t_data *data)
{
	if (ft_strchr(OBSTACLE, map[data->player.y + 1][data->player.x]) == CAN_MOVE)
	{
		put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.ground);
		data->player.y++;
		put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.player);
		count_and_print_my_moves(data);
	}
}

void move_right(char **map, t_data *data)
{
	if (ft_strchr(OBSTACLE, map[data->player.y][data->player.x + 1]) == CAN_MOVE)
	{
		put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.ground);
		data->player.x++;
		put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.player);
		count_and_print_my_moves(data);
	}
}
