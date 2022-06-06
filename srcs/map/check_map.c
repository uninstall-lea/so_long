/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:12:04 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/06 16:31:02 by lbisson          ###   ########.fr       */
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
	if (line == check->nb_lines - 1 && (check->nb_exit != 1
			|| check->nb_player != 1 || check->nb_collec == 0))
		return (FALSE);
	return (TRUE);
}

void	check_map_elems(int line, char *map, t_map *check)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		if (is_elem(map[i]) == NOT_ELEM)
			error_exit();
		count_each_elems(line, map[i], check);
		i++;
	}
	if (count_each_elems(line, map[i], check) == FALSE)
		error_exit();
}

static int	is_map_rectangle(char *map, t_map *check)
{
	if ((int)ft_strlen(map) - 1 != check->nb_columns)
		return (FALSE);
	return (TRUE);
}

static int	is_map_closed(int line, char c, char *map, t_map *check)
{
	if ((c != BORDER && (line == 0 || line == check->nb_lines - 1))
		|| (map[0] != BORDER && (line > 0 && line < check->nb_lines))
		|| (map[ft_strlen(map) - 2] != BORDER && (line > 0 && line < check->nb_lines)))
		return (FALSE);
	return (TRUE);
}

void	check_map_borders(int line, char *map, t_map *check)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		if (is_map_rectangle(map, check) == FALSE
			|| is_map_closed(line, map[i], map, check) == FALSE)
			error_exit();
		i++;
	}
}

void	check_map_size(char **av, t_map *check)
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
