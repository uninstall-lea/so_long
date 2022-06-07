MLXPATH =	mlx_linux/
CFLAGS =	-fPIE -Wall -Wextra -Werror -g3 -I.
LINUX =		-I /usr/include -L /usr/lib -L mlx_linux -I mlx_linux -lXext -l X11 -lm -lz
NAME =		so_long

SRCS =		srcs/trash.c					\
			srcs/window.c					\
			srcs/so_long.c					\
			srcs/hook_events.c				\
			srcs/map/init_map.c				\
			srcs/map/check_arg.c			\
			srcs/map/check_map_elems.c		\
			srcs/map/check_map_borders.c	\
			srcs/moves/move_player.c		\
			srcs/moves/check_if_access.c\
			srcs/textures/display_img.c		\
			srcs/textures/destroy_img.c		\
			srcs/gnl/get_next_line.c		\
			srcs/gnl/get_next_line_utils.c	\

OBJS =		$(SRCS:.c=.o)

%.o: %.c
			$(CC) $(CFLAGS) -I /usr/include -Imlx_linux -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(MLXPATH) all 
			gcc $(CFLAGS) $(OBJS) mlx_linux/libmlx_Linux.a $(LINUX) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
