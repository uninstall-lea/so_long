/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:46:41 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/22 16:01:50 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	move_up(char **map, t_data *data)
{
	if (can_i_decrease_p('y', map, &data->player, data) == CAN_MOVE)
	{
		move_ground_on_window_p(data);
		data->player.y--;
		loose_if_p_walk_on_e(map, &data->player, data);
		can_i_go_to_poney(map, &data->player, data);
		update_map_for_player('y', '-', map, &data->player);
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}

void	move_left(char **map, t_data *data)
{
	if (can_i_decrease_p('x', map, &data->player, data) == CAN_MOVE)
	{
		move_ground_on_window_p(data);
		data->player.x--;
		loose_if_p_walk_on_e(map, &data->player, data);
		can_i_go_to_poney(map, &data->player, data);
		update_map_for_player('x', '-', map, &data->player);
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}

void	move_down(char **map, t_data *data)
{
	if (can_i_increase_p('y', map, &data->player, data) == CAN_MOVE)
	{
		move_ground_on_window_p(data);
		data->player.y++;
		loose_if_p_walk_on_e(map, &data->player, data);
		can_i_go_to_poney(map, &data->player, data);
		update_map_for_player('y', '+', map, &data->player);
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}

void	move_right(char **map, t_data *data)
{
	if (can_i_increase_p('x', map, &data->player, data) == CAN_MOVE)
	{
		move_ground_on_window_p(data);
		data->player.x++;
		loose_if_p_walk_on_e(map, &data->player, data);
		can_i_go_to_poney(map, &data->player, data);
		update_map_for_player('x', '+', map, &data->player);
		move_player_on_window(data);
		count_and_print_my_moves(data);
	}
}
