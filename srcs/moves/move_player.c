/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:46:41 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/21 14:28:22 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	move_up(char **map, t_data *data)
{
	if (decrease_P('y', map, &data->player, data) == CAN_MOVE)
	{
		move_ground_on_window_P(data);
		data->player.y--;
		loose_if_P_walk_on_E(map, &data->player, data);
		can_i_go_to_poney(map, &data->player, data);
		map[data->player.y][data->player.x] = 'P';
		map[data->player.y + 1][data->player.x] = '0';
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
		loose_if_P_walk_on_E(map, &data->player, data);
		can_i_go_to_poney(map, &data->player, data);
		map[data->player.y][data->player.x] = 'P';
		map[data->player.y][data->player.x + 1] = '0';
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
		loose_if_P_walk_on_E(map, &data->player, data);
		can_i_go_to_poney(map, &data->player, data);
		map[data->player.y][data->player.x] = 'P';
		map[data->player.y - 1][data->player.x] = '0';
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
		loose_if_P_walk_on_E(map, &data->player, data);
		can_i_go_to_poney(map, &data->player, data);
		map[data->player.y][data->player.x] = 'P';
		map[data->player.y][data->player.x - 1] = '0';
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}
