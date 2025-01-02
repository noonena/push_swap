NAME = push_swap

CC = cc
FLAGS = -Wall -Werror -Wextra

SRCS	= 		./src/parser.c \
				./src/push_stack.c \
				./src/push_swap.c \
				./src/operator1.c \
				./src/operator2.c \
				./src/sort_small.c \
				./src/list_and_utils.c \
				./src/index.c \
				./src/butterfly.c \
				./src/check_context.c \


HEADER	= push_swap.h

OBJS	=	${SRCS:.c=.o}

all : $(NAME)

$(NAME) :	${OBJS} Makefile
			$(CC) ${OBJS} ${FLAGS} ${HEADERS} -o ${NAME}

%.o: 	%.c $(HEADER)
		cc -o $@ -c $< ${HEADERS}

clean:
		@rm -f ${OBJS}

fclean:
		@rm -f ${OBJS}
		@rm -f ${NAME}

re: clean all

.PHONY: all clean fclean re