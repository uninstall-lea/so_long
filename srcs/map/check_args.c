/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:56:27 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/03 17:54:13 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static int	check_type_of_arg(char **av)
{
	if (ft_strlen(ft_strstr(av[1], ".ber")) != ft_strlen(".ber"))
		return (FALSE);
	return (TRUE);
}

void	check_args(int ac, char **av)
{
	if (ac != 2)
		error_exit();
	else if (check_type_of_arg(av) == FALSE)
		error_exit();
}
