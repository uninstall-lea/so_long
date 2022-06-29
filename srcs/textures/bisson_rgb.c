/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bisson_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:09:23 by lea               #+#    #+#             */
/*   Updated: 2022/06/29 18:16:51 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	bisson_rgb(t_enemy *enemy, t_data *data)
{
	enemy->rgb++;
	if (enemy->rgb > BLUE)
		enemy->rgb = RED;
	if (enemy->rgb == RED)
	{
		put_img_to_window(enemy->x, enemy->y, &data->win,
			data->pack.red_enemy);
	}
	else if (enemy->rgb == GREEN)
	{
		put_img_to_window(enemy->x, enemy->y, &data->win,
			data->pack.green_enemy);
	}
	else if (enemy->rgb == BLUE)
	{
		put_img_to_window(enemy->x, enemy->y, &data->win,
			data->pack.blue_enemy);
	}
}
