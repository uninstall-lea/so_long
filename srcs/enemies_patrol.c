/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:47:24 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/06 18:55:06 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	enemy_patrol(t_data *data)
{
	int		i;
	t_enemy *enemy;

	enemy = malloc(sizeof(t_enemy) * data->map.nb_enemy);
	if (!enemy)
		error_exit(1);
	i = 0;
	while (i < data->map.nb_enemy)
	{
		get_coordinates_enemy(ENEMY, data->map.map, &enemy[i]);
		i++;
	}
	i = 0;
}