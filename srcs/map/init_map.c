/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:12:22 by lbisson           #+#    #+#             */
/*   Updated: 2022/07/13 01:55:37 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static void	set_up_vars(t_map *set)
{
	int	i;

	set->nb_exit = 0;
	set->nb_enemy = 0;
	set->nb_player = 0;
	set->nb_collec = 0;
	set->str_map = malloc(sizeof(char *) * (set->nb_lines + 1));
	if (!set->str_map)
		error_exit(1);
	i = 0;
	while (i <= set->nb_lines)
	{
		set->str_map[i] = NULL;
		i++;
	}
}

static void	read_and_check_map(char **av, t_map *set, t_data *data)
{
	int	i;
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_exit(8);
	i = 0;
	while (i < set->nb_lines)
	{
		set->str_map[i] = get_next_line(fd);
		if (check_map_elems(i, set->str_map[i], set) == ERROR)
		{
			ft_free(data->map.str_map);
			error_exit(7);
		}
		if (check_map_borders(i, set->str_map[i], set) == ERROR)
		{
			ft_free(data->map.str_map);
			error_exit(5);
		}
		i++;
	}
	close(fd);
}

void	init_map(int ac, char **av, t_data *data)
{
	check_arg(ac, av, &data->map);
	set_up_vars(&data->map);
	read_and_check_map(av, &data->map, data);
}
