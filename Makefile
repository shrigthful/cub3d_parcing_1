NAME= cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
FILES =	cub3d.c \
	get_next_line.c \
	error.c \
	hex.c \
	get_rgb.c \
	get_imgpath.c \
	utils.c \
	validation.c \
	check_content.c \
	ft_map.c \

LIBFT = ./libft/libft.a

CAST_FILES = file1.c file2.c file3.c file4.c #testfile.c

OBJ = $(FILES:.c=.o)

CAST_OBJ = $(CAST_FILES:.c=.o)

all : $(LIBFT) $(NAME) clean

%.o : %.c
	$(CC) $(CFLAGS) -c $^

$(LIBFT) :
	make --directory=./libft

$(NAME) : $(libft) $(OBJ) $(CAST_OBJ)
	$(CC) $(CFLAGS) $(MLXFLAGS)  $(LIBFT) $(OBJ) $(CAST_OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)
	rm -f $(CAST_OBJ)
	make clean --directory=./libft

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re : fclean all
