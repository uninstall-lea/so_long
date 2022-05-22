MLXPATH =	mlx_linux/
CFLAGS =	-fPIE -Wall -Wextra -Werror -g3 -I.
LINUX =		-I /usr/include -L /usr/lib -L mlx_linux -I mlx_linux -lXext -l X11 -lm -lz
NAME =		so_long

SRCS =		window.c					\
			display.c					\
			so_long.c					\
			read_map.c					\
			ft_strchr.c					\
			ft_strlen.c 				\
			ft_strstr.c					\
			gnl/get_next_line.c 		\
			gnl/get_next_line_utils.c	\

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
