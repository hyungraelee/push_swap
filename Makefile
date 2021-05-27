NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -g3 -fsanitize=address
# ifeq ($(DEBUG),true)
# 	CFLAGS += -g
# endif

SRCS_DIR =	./srcs	\
			./srcs/operation	\
			./srcs/tools	\
			./srcs/utils
OBJS_DIR = ./objs
INC_DIR = ./includes
SRCS =	./srcs/main.c	\
		./srcs/push_swap.c	\
		./srcs/quicksort_a.c	\
		./srcs/quicksort_b.c	\
		./srcs/check_arg.c	\
		./srcs/handle_little_input.c	\
		./srcs/init.c	\
		./srcs/set_stack.c	\
		./srcs/operation/push.c	\
		./srcs/operation/swap.c	\
		./srcs/operation/rotate.c	\
		./srcs/operation/rev_rotate.c	\
		./srcs/tools/chk_whole_elements.c	\
		./srcs/tools/error.c	\
		./srcs/tools/escape_condition.c	\
		./srcs/tools/free.c	\
		./srcs/tools/get_pivot.c	\
		./srcs/tools/handle_3_in_a.c	\
		./srcs/tools/handle_3_in_b.c	\
		./srcs/tools/init_cnt.c	\
		./srcs/tools/is_sorted.c	\
		./srcs/tools/optimizing.c	\
		./srcs/tools/reset_rotate.c	\
		./srcs/utils/ft_atoi.c	\
		./srcs/utils/ft_isdigit.c	\
		./srcs/utils/ft_memcpy.c	\
		./srcs/utils/ft_putstr_fd.c	\
		./srcs/utils/ft_split.c	\
		./srcs/utils/ft_strcmp.c	\
		./srcs/utils/ft_strlcpy.c	\
		./srcs/utils/ft_strlen.c

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

check :
	@make -C ./checker re
	@cp ./checker/mychecker ./mychecker

clean :
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r ./checker/$(OBJS_DIR)
	@$(RM) ./checker/mychecker
	@$(RM) ./mychecker

fclean : clean
	@$(RM) $(NAME)

re : fclean all
