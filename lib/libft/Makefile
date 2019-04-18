# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 14:01:50 by vvlasenk          #+#    #+#              #
#    Updated: 2019/04/17 17:01:54 by vvlasenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH 	= ./src/
OBJ_PATH 	= ./obj/
INC_PATH 	= ./include/

NAME 		= libft.a
CC 			= gcc
CFGLAGS 	= -Werror -Wextra -Wall

SRC_NAME	=	ft_memset.c ft_memcpy.c ft_memchr.c ft_memcmp.c \
				ft_strcmp.c ft_bzero.c ft_memmove.c ft_strlen.c \
				ft_strcpy.c ft_strncpy.c ft_memccpy.c ft_toupper.c \
				ft_strcat.c ft_strncat.c ft_strchr.c ft_strrchr.c \
				ft_strncmp.c ft_tolower.c ft_strstr.c ft_strdup.c \
				ft_strnstr.c ft_atoi.c ft_strlcat.c ft_isalpha.c \
				ft_isdigit.c ft_isalnum.c ft_isprint.c ft_isascii.c \
				ft_putstr.c ft_putchar.c ft_memalloc.c ft_memdel.c \
				ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
				ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
				ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
				ft_strsplit.c ft_itoa.c ft_putendl.c ft_putnbr.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_lstmap.c ft_lstnew.c ft_lstiter.c ft_lstdelone.c \
				ft_lstdel.c ft_lstadd.c ft_putnbr_fd.c ft_nbrlen.c \
				get_next_line.c ft_atof.c ft_isblank.c ft_pow.c

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
	norminette $(SRC) $(INC_PATH)libft.h

clean:
	rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all