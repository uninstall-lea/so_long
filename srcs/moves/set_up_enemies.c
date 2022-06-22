/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:09:26 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/22 16:10:10 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	set_up_time(t_time *time)
{
	time->begin = clock();
	time->current = 0;
	time->previous = 0;
}

void	set_up_enemies(t_data *data)
{
	int		i;

	data->enemy = malloc(sizeof(t_enemy) * data->map.nb_enemy);
	if (!data->enemy)
		error_exit(1);
	i = 0;
	while (i < data->map.nb_enemy)
	{
		get_coordinates_enemy(ENEMY, data->map.str_map, &data->enemy[i]);
		data->enemy[i].dir = LEFT;
		i++;
	}
}
