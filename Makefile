CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIBS = -lmlx -lXext -lX11 -L minilibx-linux -lm libft/libft.a

SRCS = events.c fractals.c fractol.c utils.c window.c

HEADERS = fractol.h

OBJS = $(SRCS:.c=.o)

TARGET = fractol

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

all: $(TARGET)
