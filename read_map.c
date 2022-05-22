#include "so_long.h"

static void	check_map_elems(int line, char *map , t_map *check)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		if (ft_strchr(ELEMS, map[i]) == 0)
			exit((write(2, "Error\n", 6), EXIT_FAILURE));
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
		exit((write(2, "Error\n", 6), EXIT_FAILURE));
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
			exit((write(2, "Error\n", 6), EXIT_FAILURE));
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
		exit((write(2, "Error\n", 6), EXIT_FAILURE));
}

static void set_vars(char **av, t_map *check)
{
	check->nb_exit = 0;
	check->nb_player = 0;
	check->nb_collec = 0;
	check->nb_lines = 0;
	check_map_size(av, check);
	check->map = malloc(sizeof(char *) * (check->nb_lines + 1));
	if (!check->map)
		exit((write(2, "Error\n", 6), EXIT_FAILURE));
	check->map[check->nb_lines] = NULL;

}

void	read_map(int ac, char **av, t_map *check)
{
	int	i;
	int	fd;

	if (ac != 2)
		exit((write(2, "Error\n", 6), EXIT_FAILURE));
	else if (ft_strstr(av[1], ".ber") == 0)
		exit((write(2, "Error\n", 6), EXIT_FAILURE));
	i = 0;
	set_vars(av, check);
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
