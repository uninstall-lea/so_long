/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_elems.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:44:49 by lbisson           #+#    #+#             */
/*   Updated: 2022/07/13 01:57:14 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static int	is_elem(char elem)
{
	if (ft_strchr(ELEMS, elem) == NOT_ELEM)
		return (FALSE);
	return (TRUE);
}

static int	count_each_elems(int line, char elem, t_map *check)
{
	if (elem == EXIT)
		check->nb_exit++;
	else if (elem == PLAYER)
		check->nb_player++;
	else if (elem == COLLEC)
		check->nb_collec++;
	else if (elem == ENEMY)
		check->nb_enemy++;
	if (line == check->nb_lines - 1 && (check->nb_exit != 1
			|| check->nb_player != 1 || check->nb_collec == 0))
		return (FALSE);
	return (TRUE);
}

int	check_map_elems(int line, char *map, t_map *check)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		if (is_elem(map[i]) == NOT_ELEM)
			return (ERROR);
		count_each_elems(line, map[i], check);
		i++;
	}
	if (count_each_elems(line, map[i], check) == FALSE)
		return (ERROR);
	return (1);
}
