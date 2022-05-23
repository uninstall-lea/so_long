/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:12:22 by lbisson           #+#    #+#             */
/*   Updated: 2022/05/23 21:29:49 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static void set_vars(char **av, t_map *check)
{
	check->nb_exit = 0;
	check->nb_player = 0;
	check->nb_collec = 0;
	check->nb_lines = 0;
	check_map_size(av, check);
	check->map = malloc(sizeof(char *) * (check->nb_lines + 1));
	if (!check->map)
		error_exit();
	check->map[check->nb_lines] = NULL;

}

static void read_and_check_map(char **av, t_map *check)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(av[1], O_RDONLY);
	while (i < check->nb_lines)
	{
		check->map[i] = get_next_line(fd);
		check_map_elems(i, check->map[i], check);
		check_map_borders(i, check->map[i], check);
		i++;
	}
	close(fd);
}
void	init_map(int ac, char **av, t_map *check)
{
	check_args(ac, av);
	set_vars(av, check);
	read_and_check_map(av, check);
}
