##
## EPITECH PROJECT, 2024
## my_runner
## File description:
## Makefile
##

SRC		=	src/main.c		\
			src/textures.c	

OBJ_DIR	=	obj

OBJ		=	$(SRC:src/%.c=$(OBJ_DIR)/%.o)

CC		=	gcc

NAME	=	my_runner

CFLAGS	=	-I./include -g

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:	src/%.c | $(OBJ_DIR)
	$(CC) -o $@ -c $< $(CFLAGS)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all