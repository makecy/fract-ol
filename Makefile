GREEN=\033[0;32m
RESET=\033[0m
RED=\033[0;31m
CHECK=\xE2\x9C\x94
BROOM=\xF0\x9F\xA7\xB9

NAME= fractol

RM = rm -f
CC = cc 

CFLAGS = -Wall -Wextra -Werror -g3
MLXFLAGS = -ldl -lglfw -pthread -lm

LIBRARIES_PATH = ./libraries
INCLUDE = -L $(LIBRARIES_PATH) -lft
LIBRARIES = $(LIBRARIES_PATH)/libft.a


SRC =	main.c \
		

OBJ = $(SRC:.c=.o) 

MLX_PATH = ./MLX42/build
MLX = $(MLX_PATH)/libmlx42.a

all: $(NAME)

$(MLX): 
		cd MLX42 && cmake -B build && cmake --build build -j4;

$(LIBRARIES):
	@make -C $(LIBRARIES_PATH)
	@echo "$(GREEN)$(CHECK)Compiled Libraries Successfully$(CHECK)$(RESET)"

$(NAME): $(LIBRARIES) $(MLX) $(OBJ)  
	$(CC) $(CFLAGS) $(MLX) $(MLX_FLAGS) $(LIBRARIES) -o $(NAME) $(OBJ) $(INCLUDE)
	@echo "$(GREEN)$(CHECK)Compiled push_swap Successfully$(CHECK)$(RESET)"

submodule:
			git submodule update --init --recursive


%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	@make -C $(LIBRARIES_PATH) clean
	@$(RM) $(OBJ) $(BONUS_OBJ)
	
fclean : clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@make fclean -C $(LIBRARIES_PATH)
	@echo "$(RED)$(BROOM)Cleaned Successfully$(RESET)$(BROOM)"


re : fclean all bonus

.PHONY: all clean fclean re