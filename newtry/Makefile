LIBFT = /libft/libft.a

NAME = libftprintf.a

SRCS = new.c print_cs.c print_diu.c print_pox.c printfloat.c

CC = gcc

FLAGS = -Wall -Wextra -Werror -c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C libft
	rm -rf $(SURPL_O)
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C libft
	rm -rf $(NAME)

re : fclean all
