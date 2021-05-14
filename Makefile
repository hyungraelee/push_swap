NAME = push_swap
CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -g3 -fsanitize=address
SRCS_DIR = ./srcs
OBJS_DIR = ./objs
INC_DIR = ./includes
SRCS =	./srcs/main.c
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
vpath %.c $(SRCS_DIR)
RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I$(INC_DIR) -c $^

run: re
	@./$(NAME)

clean :
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
