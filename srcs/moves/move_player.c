#include "../../incs/so_long.h"

void	move_up(char **map, t_data *data)
{
	if (decrease('y', map, data) == CAN_MOVE)
	{
		put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.ground);
		data->player.y--;
		check_for_collec(map, data);
		check_for_exit(map, data);
		put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.player);
		count_and_print_my_moves(data);
	}
}

void move_left(char **map, t_data *data)
{
	if (decrease('x', map, data) == CAN_MOVE)
	{
		put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.ground);
		data->player.x--;
		check_for_collec(map, data);
		check_for_exit(map, data);
		put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.player);
		count_and_print_my_moves(data);
	}
}

void move_down(char **map, t_data *data)
{
	printf("hello\n");
	if (increase('y', map, data) == CAN_MOVE)
	{
		printf("pb5\n");
		put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.ground);
		printf("pb6\n");
		data->player.y++;
		check_for_collec(map, data);
		printf("pb7\n");
		check_for_exit(map, data);
		printf("pb8\n");
		put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.player);
		printf("pb9\n");
		count_and_print_my_moves(data);
		printf("pb10\n");
	}
}

void move_right(char **map, t_data *data)
{
	if (increase('x', map, data) == CAN_MOVE)
	{
		put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.ground);
		data->player.x++;
		check_for_collec(map, data);
		check_for_exit(map, data);
		put_img_to_window(data->player.x, data->player.y,
							&data->win, data->pack.player);
		count_and_print_my_moves(data);
	}
}
