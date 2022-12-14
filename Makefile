NAME = push_swap
CHECK = checker
SRCS = push_swap.c \
		push_swap_utils.c \
		ft_atoi.c \
		simple_sort.c \
		actions.c \
		actions_2.c \
		large_sort.c \
		quick_sort.c \
		large_sort_utils.c \
		stack/ft_stack.c \
		stack/ft_stack_search.c \
		stack/ft_stack_traverse.c
BNSRC = ./bonus_checker/checker.c \
		ft_atoi.c \
		actions.c \
		actions_2.c \
		simple_sort.c \
		push_swap_utils.c \
		stack/ft_stack.c \
		stack/ft_stack_search.c \
		stack/ft_stack_traverse.c
GNL = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
BNSOBJ = ${BNSRC:.c=.o}
GNLB = ${GNL:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	rm -rf ${OBJS}

clean:
	rm -rf ${OBJS} ${BNSOBJ} ${GNLB}

fclean: clean
	rm -rf ${NAME}

bonus: ${BNSOBJ} ${GNLB}
	${CC} ${CFLAGS} ${BNSOBJ} ${GNLB} -o ${CHECK}
