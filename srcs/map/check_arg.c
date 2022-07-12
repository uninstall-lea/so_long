/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:56:27 by lbisson           #+#    #+#             */
/*   Updated: 2022/07/13 01:57:20 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

int	is_name_valid(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (i > 3 && av[i - 1] == 'r' && av[i - 2] == 'e' && av[i - 3] == 'b'
		&& av[i - 4] == '.')
		return (TRUE);
	else
		return (FALSE);
}

static void	check_map_size(char **av, t_map *check)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_exit(8);
	check->nb_lines = 0;
	check->str_line = get_next_line(fd);
	check->nb_columns = ft_strlen(check->str_line) - 1;
	while (check->str_line)
	{
		if (ft_strlen(check->str_line) < 4)
		{
			free(check->str_line);
			error_exit(2);
		}
		free(check->str_line);
		check->str_line = get_next_line(fd);
		check->nb_lines++;
	}
	free(check->str_line);
	close(fd);
}

void	check_arg(int ac, char **av, t_map *check)
{
	if (ac != 2)
		error_exit(4);
	else if (is_name_valid(av[1]) == FALSE)
		error_exit(3);
	check_map_size(av, check);
	if (check->nb_lines <= 2)
		error_exit(2);
}
