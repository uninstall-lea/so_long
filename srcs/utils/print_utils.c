/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:39:26 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/22 15:56:07 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

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
	ft_putnbr_fd(++data->player.nb_moves, 1);
	write(1, "\n", 1);
}

void	error_exit(int error)
{
	if (error == 1)
		write(2, "ERROR[1] : Wrong malloc\n", 24);
	else if (error == 2)
		write(2, "ERROR[2] : Wrong map size\n", 26);
	else if (error == 3)
		write(2, "ERROR[3] : Given arg is not a '.ber' \n", 38);
	else if (error == 4)
		write(2, "ERROR[4] : Wrong number of arg(s) given\n", 40);
	else if (error == 5)
		write(2, "ERROR[5] : Map is not closed or rectangle\n", 42);
	else if (error == 6)
		write(2, "ERROR[6] : One image (or more) couldn't be found\n", 49);
	else if (error == 7)
		write(2, "ERROR[7] : One elem (or more) has not the right value\n", 54);
	else if (error == 8)
		write(2, "ERROR[8] : One char on map (or more) is not an elem\n", 56);
	exit(EXIT_FAILURE);
}
