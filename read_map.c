#include "so_long.h"

void	check_map_elems(int line, int last_line, char *map)
{
	int	i;
	int	nb_exit;
	int	nb_player;
	int	nb_collectible;

	i = 0;
	nb_exit = 0;
	nb_player = 0;
	nb_collectible = 0;
	while (map[i] != '\n')
	{
		if ((line == 1 && map[i] != BORDER)
			|| (line == last_line && map[i] != BORDER)
			|| (line > 1 && line < last_line
				&& (map[0] != BORDER || map[ft_strlen(map) - 2] != BORDER)))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		else if (map[i] == EXIT)
			nb_exit++;
		else if (map[i] == PLAYER)
			nb_player++;
		else if (map[i] == COLLECTIBLE)
			nb_collectible++; 
		i++;
	}
	if (line == last_line && (nb_exit != 1 || nb_player != 1 || nb_collectible == 0))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

void	read_map(int ac, char **av)
{
	int		fd;
	int		nb_call;
	int		max_call;
	char	*map;

	if (ac != 2)
	{
		write(2, "Error1\n", 6);
		exit(EXIT_FAILURE);
	}
	max_call = 1;
	fd = open(av[1], O_RDONLY);
	map = get_next_line(fd);
	if (!map)
	while (map)
	{
		free(map);
		map = get_next_line(fd);
		max_call++;
	}
	close(fd);
	if (max_call <= 3)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	nb_call = 1;
	fd = open(av[1], O_RDONLY);
	map = get_next_line(fd);
	while (map)
	{
		check_map_elems(nb_call, max_call, map);
		free(map);
		map = get_next_line(fd);
		nb_call++;
	}
	close(fd);
}
