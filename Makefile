# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 17:14:43 by wwatkins          #+#    #+#              #
#    Updated: 2016/11/30 10:49:57 by wwatkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop
CC = gcc

SRC_PATH = ./src/
OBJ_PATH = ./obj/
LIB_PATH = ./lib/
INC_PATH = ./include/ $(LIB_PATH)libft/include/ $(LIB_PATH)mlx/ $(LIB_PATH)glfw/include/

GCC_FLGS = -Werror -Wextra -Wall -pedantic -g3
MLX_FLGS = -framework OpenGL -framework Appkit
GCC_LIBS = -lglfw3 -framework AppKit -framework OpenGL -Framework IOKit -framework CoreVideo
# or "-framework Cocoa" instead of AppKit ?

SRC_NAME = main.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft mlx glfw/src

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L$(LIB_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)libft -j
	make -C $(LIB_PATH)mlx -j
	$(CC) $(GCC_FLGS) $(LIB) -lft -lmlx $(INC) $(OBJ) $(MLX_FLGS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(GCC_FLGS) $(INC) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	rm -rf $(OBJ_PATH)

fclean:
	make -C $(LIB_PATH)libft fclean
	make -C $(LIB_PATH)mlx clean
	rm -fv $(NAME)

re: fclean all
