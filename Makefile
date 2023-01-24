SRCS = main.c gnl/get_next_line.c gnl/get_next_line_utils.c ft_move.c

NAME = push_swap

OBJS = ${SRCS:.c=.o}

GCC = gcc

LIBRARY = -I. -I ./ft_printf -I ./libft -L ./libft -lftprintf -L ./ft_printf -lft -I ./gnl

CFLAGS = -Wall -Werror -Wextra

.c.o:
	${GCC} ${CFLAGS} -c ${LIBRARY} $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	$(MAKE) -C ft_printf
	$(MAKE) -C libft
	${GCC} -o ${NAME} ${OBJS} ${LIBRARY}

clean:
	rm -f ${OBJS}
	$(MAKE) clean -C libft
	$(MAKE) clean -C ft_printf

fclean:
	rm -f ${NAME}
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C ft_printf

re: fclean all