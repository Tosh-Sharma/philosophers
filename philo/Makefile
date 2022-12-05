NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	main.c \
		ft_superatoi.c \
		philo.c \
		core.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${@} ${^}

%.o: %.c
	${CC} ${CFLAGS} -o ${@} -c ${@:.o=.c}

re: fclean all

fclean: clean
	rm -f ${NAME}

clean:
	rm -f ${OBJS} ${BONUS_OBJS}

.PHONY: clean fclean re all