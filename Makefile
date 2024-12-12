##
## Makefile for MiniLibX in /home/boulon/work/c/raytraceur/minilibx
## 
## Made by Olivier Crouzet
## Login   <ol@epitech.net>
## 
## Started on  Tue Oct  5 15:56:43 2004 Olivier Crouzet
## Last update Tue May 15 15:44:41 2007 Olivier Crouzet
##

## Please use configure script


# Compiler setup
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -Iincludes

# Library Directories
MINILIBX_DIR = minilibx-linux
LIBS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -lbsd

# Sourcesrcs
SRCS =	srcs/get_next_line/get_next_line.c \
		srcs/convert_map.c \
		srcs/draw.c \
		srcs/draw_utils.c \
		srcs/ft_putstr_fd.c \
		srcs/keys.c \
		srcs/keys_utils.c \
		srcs/main.c \
		srcs/next_matrix.c \
		srcs/matrix_utils.c \
		srcs/matrix.c	\
		srcs/mlx.c 
OBJS = $(SRCS:.c=.o)

# Output binary
NAME = fdf

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "Building MiniLibX..."
	@$(MAKE) -C $(MINILIBX_DIR) # Build MiniLibX first
	@echo "Compiling FdF..."
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(NAME) built successfully!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning FdF object files..."
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(MINILIBX_DIR) clean # Clean MiniLibX
	rm -f $(NAME)

re: fclean all