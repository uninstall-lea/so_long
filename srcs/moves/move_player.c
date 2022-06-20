/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:46:41 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/20 17:52:26 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	move_up(char **map, t_data *data)
{
	if (decrease_P('y', map, &data->player, data) == CAN_MOVE)
	{
		move_ground_on_window_P(data);
		data->player.y--;
		can_i_go_to_poney(map, &data->player, data);
		map[data->player.y][data->player.x] = 'P';
		map[data->player.y + 1][data->player.x] = '0';
		check_if_loose_P(map, &data->player, data);
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}

void	move_left(char **map, t_data *data)
{
	if (decrease_P('x', map, &data->player, data) == CAN_MOVE)
	{
		move_ground_on_window_P(data);
		data->player.x--;
		can_i_go_to_poney(map, &data->player, data);
		map[data->player.y][data->player.x] = 'P';
		map[data->player.y][data->player.x + 1] = '0';
		check_if_loose_P(map, &data->player, data);
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}

void	move_down(char **map, t_data *data)
{
	if (increase_P('y', map, &data->player, data) == CAN_MOVE)
	{
		move_ground_on_window_P(data);
		data->player.y++;
		can_i_go_to_poney(map, &data->player, data);
		map[data->player.y][data->player.x] = 'P';
		map[data->player.y - 1][data->player.x] = '0';
		check_if_loose_P(map, &data->player, data);
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}

void	move_right(char **map, t_data *data)
{
	if (increase_P('x', map, &data->player, data) == CAN_MOVE)
	{
		move_ground_on_window_P(data);
		data->player.x++;
		check_if_loose_P(map, &data->player, data);
		can_i_go_to_poney(map, &data->player, data);
		map[data->player.y][data->player.x] = 'P';
		map[data->player.y][data->player.x - 1] = '0';
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}
