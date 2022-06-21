/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:44:43 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/21 15:47:18 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	move_ground_on_window_P(t_data *data)
{
	mlx_put_image_to_window(data->win.mlx, data->win.win_ptr, data->pack.ground.img,
		data->player.x * IMG_SIZE, data->player.y * IMG_SIZE);
}

void	move_ground_on_window_E(t_enemy *enemy, t_data *data)
{
		mlx_put_image_to_window(data->win.mlx, data->win.win_ptr, data->pack.ground.img,
			enemy->x * IMG_SIZE, enemy->y * IMG_SIZE);
}

void	move_player_on_window(t_data *data)
{
	mlx_put_image_to_window(data->win.mlx, data->win.win_ptr, data->pack.player.img,
		data->player.x * IMG_SIZE, data->player.y * IMG_SIZE);
}

void	move_enemy_on_window(t_enemy *enemy, t_data *data)
{
	mlx_put_image_to_window(data->win.mlx, data->win.win_ptr, data->pack.enemy.img,
		enemy->x * IMG_SIZE, enemy->y * IMG_SIZE);
}