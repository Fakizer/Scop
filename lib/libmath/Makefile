# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 14:13:40 by vvlasenk          #+#    #+#              #
#    Updated: 2019/04/17 14:14:46 by vvlasenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH 	= ./src/
OBJ_PATH 	= ./obj/
INC_PATH 	= ./include/

NAME 		= libmath.a
CC 			= gcc
CFGLAGS 	= -Werror -Wextra -Wall

SRC_NAME  	= 	mat4f_add.c mat4f_copy.c mat4f_mult.c mat4f_rotate.c \
				mat4f_scale.c mat4f_setter.c mat4f_sub.c mat4f_transpose.c   \
				vec3f_add.c vec3f_cross.c vec3f_dot.c vec3f_float_mult.c \
				vec3f_magnitude.c vec3f_mult.c vec3f_normalize.c vec3f_rotate.c \
				vec3f_scale.c vec3f_setter.c vec3f_sub.c vec3f_copy.c vecnf_create.c

OBJ_NAME 	= $(SRC_NAME:.c=.o)

SRC 		= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ 		= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC 		= $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

norme:
	norminette $(SRC) $(INC_PATH)libmath.h

clean:
	rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all