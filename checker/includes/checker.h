#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include "structures.h"
# include "utils.h"
# include "get_next_line.h"

# define BUFFER_SIZE 5000

# define PUSH_A 1
# define PUSH_B 2

# define B_RED "\033[1;5;31m"
# define B_GREEN "\033[1;5;92m"
# define C_RESET "\e[0m"

# define ERR_MSG1 "Error : There are duplicate arguments.\n"
# define ERR_MSG2 "Error : Some arguments aren't integer.\n"
# define ERR_MSG3 "Error : Some arguments are bigger than an integer.\n"

char		**init_arg(int *argc, char **argv);
t_stack		*init_stack(void);
t_element	*init_element(void);
t_stack		*set_stack(int argc, char **argv);
void		check_arg(int argc, char **argv);
void		print_err(char *str);

void		checker(t_stack *a, t_stack *b, int r);

void		push(t_stack *a, t_stack *b, int type);
void		swap(t_stack *a, t_stack *b);
void		rotate(t_stack *a, t_stack *b);
void		rev_rotate(t_stack *a, t_stack *b);

void		free_all(t_stack *a, t_stack *b, char **arg);
void		free_double_arr(char **arr);

#endif
