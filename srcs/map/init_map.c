/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:12:22 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/07 17:20:58 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static void	set_up_vars(t_map *set)
{
	set->nb_exit = 0;
	set->nb_enemy = 0;
	set->nb_player = 0;
	set->nb_collec = 0;
	set->str_map = malloc(sizeof(char *) * (set->nb_lines + 1));
	if (!set->str_map)
		error_exit(1);
	set->str_map[set->nb_lines] = NULL;
}

static void	read_and_check_map(char **av, t_map *set)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(av[1], O_RDONLY);
	while (i < set->nb_lines)
	{
		set->str_map[i] = get_next_line(fd);
		check_map_elems(i, set->str_map[i], set);
		check_map_borders(i, set->str_map[i], set);
		i++;
	}
	close(fd);
}

void	init_map(int ac, char **av, t_map *set)
{
	check_arg(ac, av, set);
	set_up_vars(set);
	read_and_check_map(av, set);
}
