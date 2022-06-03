/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:20:53 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/03 16:52:42 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	ft_intchr(int *arr, int size, int to_find)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == to_find)
			return (i);
		i++;
	}
	return (NOT_FOUND);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c % 256)
			return ((char *)str);
		str++;
	}
	if (*str == '\0' && c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
				return (str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *start)
{
	const char	*end;

	if (!start)
		return (0);
	end = start;
	while (*end)
		end++;
	return (end - start);
}

void	ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	get_coordinates(char to_find, char **map, t_player *to_init)
{
	to_init->y = 0;
	to_init->x = 0;
	while (map[to_init->y])
	{
		to_init->x = ft_strchr(map[to_init->y], to_find) - map[to_init->y];
		if (to_init->x >= 1)
			return ;
		to_init->y++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	tmp;

	tmp = n * (1 - (2 * (n < 0)));
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (tmp > 9)
		ft_putnbr_fd(tmp / 10, fd);
	ft_putchar_fd(tmp % 10 + '0', fd);
}

void	count_and_print_my_moves(t_data *data)
{
	ft_putnbr_fd(++data->nb_moves, 1);
	write(1, "\n", 1);
}
