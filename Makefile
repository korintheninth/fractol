CC = gcc

CFLAGS = -O3 -Ipthreads -Wall -Wextra -Werror

LIBS =  -framework OpenGL minilibx/libmlx.a libft/libft.a -framework AppKit

SRCS = events.c fractals.c fractol.c utils.c window.c calc.c

HEADERS = fractol.h

OBJS = $(SRCS:.c=.o)

TARGET = fractol
 
SUBDIRS = libft minilibx

$(TARGET): build_subdirs $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: clean_subdirs
	rm -f $(OBJS)

fclean: fclean_subdirs clean
	rm -f $(TARGET)

build_subdirs:
		@for dir in $(SUBDIRS); do \
			$(MAKE) -C $$dir; \
		done

clean_subdirs:
			$(MAKE) -C libft clean;

fclean_subdirs:
			$(MAKE) -C libft fclean; \
			$(MAKE) -C minilibx clean;

re: fclean all

all: $(TARGET)

.PHONY: all clean fclean re build_subdirs clean_subdirs fclean_subdirs