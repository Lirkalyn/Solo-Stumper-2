##
## EPITECH PROJECT, 2019
## Day_10
## File description:
## makefile
##
.PHONY : clean fclean re

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	rostring

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean $(NAME)
