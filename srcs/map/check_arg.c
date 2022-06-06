/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:56:27 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/06 20:36:52 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static int	check_type_of_arg(char **av)
{
	if (ft_strlen(ft_strstr(av[1], ".ber")) != ft_strlen(".ber"))
		return (FALSE);
	return (TRUE);
}

static void	check_map_size(char **av, t_map *check)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	check->nb_lines = 0;
	check->str_line = get_next_line(fd);
	check->nb_columns = ft_strlen(check->str_line) - 1;
	while (check->str_line)
	{
		free(check->str_line);
		check->str_line = get_next_line(fd);
		check->nb_lines++;
	}
	close(fd);
}

void	check_arg(int ac, char **av, t_map *check)
{
	if (ac != 2)
		error_exit(4);
	else if (check_type_of_arg(av) == FALSE)
		error_exit(3);
	check_map_size(av, check);
//	printf("nb lines : %d\n", check->nb_lines);
	if (check->nb_lines <= 2)
		error_exit(2);
}