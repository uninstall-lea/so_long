/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player->c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:46:41 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/29 16:50:49 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	move_up(char **map, t_player *player, t_data *data)
{
	if (can_i_decrease_p('y', map, player, data) == CAN_MOVE)
	{
		put_img_to_window(player->x, player->y, &data->win, data->pack.ground);
		player->y--;
		loose_if_p_walk_on_e(map, player, data);
		can_i_go_to_poney(map, player, data);
		update_map_for_player('y', '-', map, player);
		put_img_to_window(player->x, player->y, &data->win, data->pack.player);
		count_and_print_my_moves(data);
	}
}

void	move_left(char **map, t_player *player, t_data *data)
{
	if (can_i_decrease_p('x', map, player, data) == CAN_MOVE)
	{
		put_img_to_window(player->x, player->y, &data->win, data->pack.ground);
		player->x--;
		loose_if_p_walk_on_e(map, player, data);
		can_i_go_to_poney(map, player, data);
		update_map_for_player('x', '-', map, player);
		put_img_to_window(player->x, player->y, &data->win, data->pack.player);
		count_and_print_my_moves(data);
	}
}

void	move_down(char **map, t_player *player, t_data *data)
{
	if (can_i_increase_p('y', map, player, data) == CAN_MOVE)
	{
		put_img_to_window(player->x, player->y, &data->win, data->pack.ground);
		player->y++;
		loose_if_p_walk_on_e(map, player, data);
		can_i_go_to_poney(map, player, data);
		update_map_for_player('y', '+', map, player);
		put_img_to_window(player->x, player->y, &data->win, data->pack.player);
		count_and_print_my_moves(data);
	}
}

void	move_right(char **map, t_player *player, t_data *data)
{
	if (can_i_increase_p('x', map, player, data) == CAN_MOVE)
	{
		put_img_to_window(player->x, player->y, &data->win, data->pack.ground);
		player->x++;
		loose_if_p_walk_on_e(map, player, data);
		can_i_go_to_poney(map, player, data);
		update_map_for_player('x', '+', map, player);
		put_img_to_window(player->x, player->y, &data->win, data->pack.player);
		count_and_print_my_moves(data);
	}
}
