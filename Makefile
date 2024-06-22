#Name

NAME= fractol

#Text Colors and Emojis

# for linux 
RED=$(shell tput setaf 1)
GREEN=$(shell tput setaf 2)
RESET=$(shell tput sgr0)
# for mac 
# RED=\033[0;31m
# GREEN=\033[0;32m
# RESET=\033[0m
# CHECK=\xE2\x9C\x94
# BROOM=\xF0\x9F\xA7\xB9

#Compilers

CFLAGS = -Wall -Wextra -Werror -g3
CC = cc 

#MLX

MLXFLAGS = -ldl -lglfw -pthread -lm 
MLXPATH = ./MLX42/build
MLX = $(MLXPATH)/libmlx42.a

#Libft

LIBRARIESPATH = ./libraries
INCLUDE = -L $(LIBRARIESPATH) -lft
LIBRARIES = $(LIBRARIESPATH)/libft.a

# Sources

SRC =	srcs/main.c \
		srcs/color.c \
		srcs/zooming.c \
		srcs/utils.c \
		srcs/messages.c \
		srcs/init.c \
		srcs/fractals/julia.c \
		srcs/fractals/mandelbrot.c 

# Objects

OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(MLX): 
		@echo "$(GREEN)$(CHECK)Compiling MLX$(CHECK)$(RESET)"
		cd MLX42 && cmake -B build && cmake --build build -j4;

$(LIBRARIES):
	@make -C $(LIBRARIESPATH)
	@echo "$(GREEN)$(CHECK)Compiled Libraries Successfully$(CHECK)$(RESET)"

$(NAME): $(LIBRARIES) $(MLX) $(OBJ)  
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDE) $(MLX) $(LIBRARIES) $(MLXFLAGS)
	@echo "$(GREEN)$(CHECK)Compiled fract-ol Successfully$(CHECK)$(RESET)"

submodule:
			git submodule update --init --recursive

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	@rm -f $(OBJ) 
	@make -C $(LIBRARIESPATH) clean
	@echo "$(RED)$(BROOM)Cleaning object files$(RESET)$(BROOM)"


fclean : clean
	@rm -f $(NAME)
	@make fclean -C $(LIBRARIESPATH)
	@echo "$(RED)$(BROOM)Cleaning object files && $(NAME) $(RESET)$(BROOM)"

re : fclean all

.PHONY: all clean fclean re