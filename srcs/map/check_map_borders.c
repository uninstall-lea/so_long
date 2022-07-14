/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:46:33 by lbisson           #+#    #+#             */
/*   Updated: 2022/07/14 20:35:16 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static int	if_no_nl_at_eof(int line, char *map, t_map *check)
{
	if ((int)ft_strlen(map) == check->nb_columns && line == check->nb_lines -1
		&& map[ft_strlen(map) - 1] != '\n')
		return (TRUE);
	return (FALSE);
}

static int	is_len_const(int line, char *map, t_map *check)
{
	if (if_no_nl_at_eof(line, map, check) == TRUE)
		return (TRUE);
	else if ((int)ft_strlen(map) - 1 != check->nb_columns)
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

int	check_map_borders(int line, char *map, t_map *check)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		if (is_len_const(line, map, check) == NOT_RECTANGLE
			|| is_map_closed(line, map[i], map, check) == NOT_CLOSED)
			return (ERROR);
		i++;
	}
	return (1);
}
