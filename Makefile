#Name

NAME= fractol

#Text Colors and Emojis

GREEN=\033[0;32m
RESET=\033[0m
RED=\033[0;31m
CHECK=\xE2\x9C\x94
BROOM=\xF0\x9F\xA7\xB9

#Compilers

CFLAGS = -Wall -Wextra -Werror -g3
CC = cc 

#MLX

MLXFLAGS = -ldl -lglfw -pthread -lm
MLX_PATH = ./MLX42/build
MLX = $(MLX_PATH)/libmlx42.a

#Libft

LIBRARIES_PATH = ./libraries
INCLUDE = -L $(LIBRARIES_PATH) -lft
LIBRARIES = $(LIBRARIES_PATH)/libft.a

# Sources

SRC =	main.c \
		mandelbrot.c \
		utils.c \
		color.c \
		zooming.c \
#Objects

OBJ = $(SRC:.c=.o) 


all: $(NAME)

$(MLX): 
		cd MLX42 && cmake -B build && cmake --build build -j4;

$(LIBRARIES):
	@make -C $(LIBRARIES_PATH)
	@echo "$(GREEN)$(CHECK)Compiled Libraries Successfully$(CHECK)$(RESET)"

$(NAME): $(LIBRARIES) $(MLX) $(OBJ)  
	$(CC) $(CFLAGS) $(MLX) $(MLX_FLAGS) $(LIBRARIES) -o $(NAME) $(OBJ) $(INCLUDE) -lglfw
	@echo "$(GREEN)$(CHECK)Compiled fract-ol Successfully$(CHECK)$(RESET)"

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


re : fclean all

.PHONY: all clean fclean re