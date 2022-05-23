/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:12:04 by lbisson           #+#    #+#             */
/*   Updated: 2022/05/23 21:29:45 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static void	check_map_elems(int line, char *map , t_map *check)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		if (ft_strchr(ELEMS, map[i]) == 0)
			error_exit();
		else if (map[i] == EXIT)
			check->nb_exit++;
		else if (map[i] == PLAYER)
			check->nb_player++;
		else if (map[i] == COLLEC)
			check->nb_collec++; 
		i++;
	}
	if (line == check->nb_lines - 1 && (check->nb_exit != 1
		|| check->nb_player != 1 || check->nb_collec == 0))
		error_exit();
}

static void	check_map_borders(int line, char *map, t_map *check)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		if ((int)ft_strlen(map) - 1 != check->nb_columns
			|| (map[i] != BORDER && (line == 0 || line == check->nb_lines - 1))
			|| (line > 0 && line < check->nb_lines
			&& (map[0] != BORDER || map[ft_strlen(map) - 2] != BORDER)))
			error_exit();
		i++;
	}
}

static void	check_map_size(char **av, t_map *check)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	check->str_line = get_next_line(fd);
	check->nb_columns = ft_strlen(check->str_line) - 1;
	while (check->str_line)
	{
		free(check->str_line);
		check->str_line = get_next_line(fd);
		check->nb_lines++;
	}
	close(fd);
	if (check->nb_lines <= 2)
		error_exit();
}