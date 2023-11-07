
NAME = myproject

# Directories
SRCDIR = srcs/

OBJDIR = objs/
INCDIR = includes/
LIBDIR = libft/

# Sources
SRC = main.c

# Objects
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

# Includes
INC = -I $(INCDIR) -I $(LIBDIR)$(INCDIR)

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Libraries
LIB = $(LIBDIR)libft.a 

# Rules
all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	ar rcs $(NAME).a $(OBJ) $(LIB)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIB):
	make -C $(LIBDIR)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBDIR) clean

fclean: clean
	rm -f $(NAME).a
	make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re
