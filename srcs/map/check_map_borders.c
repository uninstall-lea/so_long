/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:46:33 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/22 15:52:41 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static int	is_len_const(char *map, t_map *check)
{
	if ((int)ft_strlen(map) - 1 != check->nb_columns)
		return (FALSE);
	return (TRUE);
}

static int	is_map_closed(int line, char c, char *map, t_map *check)
{
	if ((c != BORDER && (line == 0 || line == check->nb_lines - 1))
		|| (map[0] != BORDER && (line > 0 && line < check->nb_lines))
		|| (map[ft_strlen(map) - 2] != BORDER
			&& (line > 0 && line < check->nb_lines)))
		return (FALSE);
	return (TRUE);
}

void	check_map_borders(int line, char *map, t_map *check)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		if (is_len_const(map, check) == NOT_RECTANGLE
			|| is_map_closed(line, map[i], map, check) == NOT_CLOSED)
			error_exit(5);
		i++;
	}
}
