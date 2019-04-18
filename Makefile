# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 13:57:15 by vvlasenk          #+#    #+#              #
#    Updated: 2019/04/17 19:19:21 by vvlasenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop
CC = gcc

SRC_PATH = ./src/
OBJ_PATH = ./obj/
LIB_PATH = ./lib/
INC_PATH = ./include/ $(LIB_PATH)libft/include/ $(LIB_PATH)libmath/include/ \
			$(LIB_PATH)glfw/include/

GCC_FLGS = -Werror -Wextra -Wall -pedantic -g3
GCC_LIBS = -lglfw3 -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo

SRC_NAME = scop.c init.c utils.c sys_coords.c parce.c texture.c shade.c \
			buff_setter.c looper.c key_function.c camera_function.c \
			model_function.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft libmath glfw/src

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L$(LIB_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)libft -j
	make -C $(LIB_PATH)libmath -j
	$(CC) $(GCC_FLGS) $(LIB) -lft -lmath $(INC) $(OBJ) $(GCC_LIBS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(GCC_FLGS) $(INC) -o $@ -c $<

norme:
	norminette $(SRC) $(INC_PATH)scop.h

clean:
	rm -fv $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIB_PATH)libft fclean
	make -C $(LIB_PATH)libmath fclean
	rm -fv $(NAME)

re: fclean all