/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:58:48 by lbisson           #+#    #+#             */
/*   Updated: 2022/06/06 20:58:28 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include "mlx_linux/mlx.h"
# include "../srcs/gnl/get_next_line.h"

# define IMG_SIZE 64
# define ON_DESTROY 17

/* MAP ELEMS */
# define ELEMS "01CNEP"
# define GROUND '0'
# define BORDER '1'
# define COLLEC 'C'
# define ENEMY 'N'
# define EXIT 'E'
# define PLAYER 'P'

/* KEYCODE */
# define ESC 65307
# define UP 65362
# define W 119
# define Z 122
# define LEFT 65361
# define A 97
# define Q 113
# define DOWN 65364
# define S 115
# define RIGHT 65363
# define D 100

/* DEFINE VALUES */
# define TRUE 1
# define FALSE 0
# define NOT_FOUND 404
# define IS_ELEM TRUE
# define NOT_ELEM FALSE
# define CAN_MOVE TRUE
# define CANT_MOVE FALSE
# define NOT_CLOSED FALSE
# define NOT_RECTANGLE FALSE
# define CAN_GO_TO_PONEY TRUE
# define CANT_GO_TO_PONEY FALSE
# define NO_MORE_COLLECTIBLE_LEFT 0

/* TYPEDEF */
typedef void	(*t_fptr)();

typedef struct s_window
{
	int		h;
	int		w;
	void	*mlx;
	void	*win_ptr;
}			t_window;

typedef struct s_image
{
	char	*path;
	int		h;
	int		w;
	void	*img;
}			t_image;

typedef struct s_map
{
	char	**map;
	char	*str_line;
	int		nb_collec;
	int		nb_columns;
	int		nb_exit;
	int		nb_lines;
	int		nb_player;
	int		nb_enemy;
}			t_map;

typedef struct s_textures
{
	t_image	border;
	t_image	collec;
	t_image	enemy;	
	t_image	player;
	t_image	exit;
	t_image	ground;
}			t_textures;

typedef struct s_player
{
	long int	x;
	long int	y;
}			t_player;

typedef struct s_enemy
{
	long int x;
	long int y;
}			t_enemy;

typedef struct s_data
{
	int			nb_moves;
	t_window	win;
	t_map		map;
	t_textures	pack;
	t_enemy		enemy;
	t_player	player;
}				t_data;

/* STRINGS */
char	*ft_strchr(const char *str, int c);
char	*ft_strstr(char *str, char *to_find);
size_t	ft_strlen(const char *start);

/* MAP */
void	init_map(int ac, char **av, t_map *map);
void	check_arg(int ac, char **av, t_map *check);
void	check_map_elems(int line, char *map, t_map *check);
void	check_map_borders(int line, char *map, t_map *check);

/* TEXTURES */
void	display_img(char **map, t_window *win, t_textures *set);
void	destroy_img(t_window *win, t_textures *pack);

/* WINDOW */
int		close_window(t_data *data);
void	move_ground_on_window(t_data *data);
void	move_player_on_window(t_data *data);
void	open_window(t_window *win, t_map *map);
void	put_img_to_window(int x, int y, t_window *win, t_image to_put);

/* EVENTS */
int		hook_events(int keycode, t_data *data);
void	move_up(char **map, t_data *data);
void	move_left(char **map, t_data *data);
void	move_down(char **map, t_data *data);
void	move_right(char **map, t_data *data);

/* MOVES ACCESSIBILITY */
int		check_accessibility(char c, t_data *data);
int		decrease(char where, char **map, t_data *data);
int		increase(char where, char **map, t_data *data);
void	check_for_collec(char **map, t_data *data);
void	check_for_exit(char **map, t_data *data);

/* OTHER UTILS */
int		ft_intchr(int *arr, int size, int to_find);
void	count_and_print_my_moves(t_data *data);
void	ft_free(char **str);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	get_coordinates_player(char to_find, char **map, t_player *to_init);
void	error_exit(int error);

#endif
