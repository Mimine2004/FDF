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
# MINILIBX_DIR = minilibx-linux -L$(MINILIBX_DIR)
MINILIBX_DIR = srcs
LIBS = $(MINILIBX_DIR)/libmlx_Linux.a -lXext -lX11 -lm -lbsd

# Sourcesrcs
SRCS =	srcs/get_next_line/get_next_line.c \
		srcs/get_next_line/get_next_line_utils.c \
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
	@echo "Compiling FdF..."
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(NAME) built successfully! 🌟"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning FdF object files..."
	rm -f $(OBJS)
	@echo "FdF object files have been cleaned 👌"

fclean: clean
	rm -f $(NAME)
	@echo "FdF itself has been cleaned 👌"

re: fclean all
