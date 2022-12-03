NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =	main. c \
		philo.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

fclean: clean
	rm -f ${NAME}

clean:
	rm -f ${OBJS} ${BONUS_OBJS}

.PHONY: clean fclean re all
