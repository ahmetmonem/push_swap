NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCE  =  ft_split.c ft_strdup.c ft_strlen.c ft_substr.c ft_uatoi.c push_swap.c push_swap1.c push_swap2.c push_swap3.c push_swap4.c push_swap5.c

$(NAME):
	$(CC) $(FLAGS) $(SOURCE) -Iincludes -o $(NAME)

all: $(NAME)

clean:
	@rm -rf ft_split.o ft_strdup.o ft_strlen.o ft_substr.o ft_uatoi.o push_swap.o push_swap1.o push_swap2.o push_swap3.o push_swap4.o push_swap5.o
	
fclean: clean
	@rm -rf $(NAME)

re: fclean all