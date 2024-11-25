CC			= 	cc  #-g -fsanitize=address -Wall -Wextra -Werror
RM			= 	/bin/rm -f
NAME		= 	so_long
INCLUDES	= 	-Iheaders/
SRCS		=   $(shell find src/ -name '*.c')
SRCS_BNS	=   $(shell find src_bonus/ -name '*.c')
OBJS		= 	$(SRCS:.c=.o)
OBJS_BNS	= 	$(SRCS_BNS:.c=.o)
INCLUDE		=	include/

MLX_LIB_DIR = $(INCLUDE)mlx_linux/
MLX_INCLUDE = -I $(INCLUDE)mlx_linux

MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# ^ primeira dependencia
# @ nome da regra
all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -s -C $(INCLUDE)mlx_linux
	@$(CC) $(^) $(MLX_FLAGS) -o $(@)

%.o: %.c $(MLX_LIB)
	@$(CC) $(INCLUDES) $(MLX_INCLUDE) -c $(^) -o $(@)

bonus: $(OBJS_BNS)
	@$(MAKE) -s -C $(INCLUDE)mlx_linux
	@$(CC) $(OBJS_BNS) $(MLX_FLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "\033[0;31mREMOVED OBJECT FILES\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31mREMOVED SO_LONG EXECUTABLE\033[0m"

re: fclean all

norm :
	@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

m: fclean

1:
	@make re && make clean && clear && ./$(NAME) map/map1.ber

2:
	@make re && make clean && clear && ./$(NAME) map/map2.ber

3:
	@make re && make clean && clear && ./$(NAME) map/map3.ber

4:
	@make re && make clean && clear && ./$(NAME) map/map4.ber

.PHONY: all re clean fclean m bonus 1 2 3
