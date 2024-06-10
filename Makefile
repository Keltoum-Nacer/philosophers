NAME = philo
CFILES = main.c philo_utils.c routine_utils.c init.c monitor_utils.c
OFILES = $(CFILES:.c=.o)
CC = cc
CFILAGS = -Wall -Wextra -Werror #-g3 -fsanitize=thread

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFILAGS) $(OFILES) -o $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all