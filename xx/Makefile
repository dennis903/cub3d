NAME = cub3d

SRCS =	cub3d.c	\
srcs/map_utils.c	\
srcs/map_valid_test.c	\
srcs/parse_cub.c	\
srcs/parse_map.c	\
srcs/parse_utils.c	\
srcs/save_utils.c	\
srcs/cub_setting.c	\
srcs/player_utils.c	\
srcs/key_press.c	\
srcs/utils1.c		\
srcs/cub_start.c	\
srcs/ray_cast.c		\
get_next_line/get_next_line.c	\
get_next_line/get_next_line_utils.c

OSRC = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(OSRC)

$(NAME): $(SRCS)
	make -C libft
	make -C mlx
	make -C mlx_dylib
	cp libft/libft.a ./
	cp mlx/libmlx.a ./
	cp mlx_dylib/libmlx.dylib ./
	gcc	$(FLAGS)	./libft/libft.a ./mlx/libmlx.a -framework OpenGl -framework AppKit $(SRCS) -o $(NAME)

bonus: all

%.o: %.c $(HEADER)
	gcc -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OSRC)

fclean: clean
	make -C libft fclean
	make -C mlx clean
	make -C mlx_dylib clean
	rm -f libft.a
	rm -f libmlx.a
	rm -f libmlx.dylib
	rm -f $(NAME)

re: fclean all

run : $(NAME)
	./$(NAME) map.cub

screen : $(NAME)
	./$(NAME) map.cub --save
	open screen.bmp

norm :
	@norminette *.c *.h ./libft/*.c ./libft/*.h

.PHONY: all bonus clean fclean re norm run screen