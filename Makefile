SRCS = ft_loop.c ft_sort2.c ft_sort4.c ft_sort3.c ft_move3.c ft_utils2.c ft_utils.c ft_sort.c ft_init.c ft_move2.c main.c gnl/get_next_line.c gnl/get_next_line_utils.c ft_move.c ft_lst.c ft_print_list.c 

NAME = push_swap

OBJS = ${SRCS:.c=.o}

GCC = gcc

LIBRARY = -I. -I ./ft_printf -I ./libft -L ./libft -lftprintf -L ./ft_printf -lft -I ./gnl

CFLAGS = -Wall -Werror -Wextra

.c.o:
	${GCC} -g ${CFLAGS} -c ${LIBRARY}  $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	$(MAKE) -C ft_printf
	$(MAKE) -C libft
	${GCC} -g -o ${NAME} ${OBJS} ${LIBRARY} 

clean:
	rm -f ${OBJS}
	$(MAKE) clean -C libft
	$(MAKE) clean -C ft_printf

fclean:
	rm -f ${NAME}
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C ft_printf

re: fclean all

.PHONY: all re clean fclean