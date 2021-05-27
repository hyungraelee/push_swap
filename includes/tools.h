#ifndef TOOLS_H
# define TOOLS_H

# include "push_swap.h"

# define ERR_MSG0 "Error : Please input some arguments.\n"
# define ERR_MSG1 "Error : There are duplicate arguments.\n"
# define ERR_MSG2 "Error : Some arguments aren't integer.\n"
# define ERR_MSG3 "Error : Some arguments are bigger than an integer.\n"

void	get_pivot(t_stack *a, int r, int *pivot);
int		is_a_sorted(t_stack *b, int r);
int		is_b_sorted(t_stack *b, int r);
void	reset_rotate(t_stack *a, t_stack *b, t_arg arg);
void	init_cnt(t_arg *arg);
void	print_err(char *str);
void	free_all(t_stack *a, t_stack *b);
void	handle_3_in_a(t_stack *a, t_stack *b);
void	handle_3_in_b(t_stack *a, t_stack *b);
int		escape_condition_in_a(t_stack *a, t_stack *b, int r);
int		escape_condition_in_b(t_stack *a, t_stack *b, int r);
int		is_whole_big(t_stack *a, int r, int pivot);
int		is_whole_small(t_stack *b, int r, int pivot);
void	optimizing_swap_a(t_stack *a, t_stack *b);
void	optimizing_rotate_a(t_stack *a, t_stack *b, t_arg *arg, int *r);
void	optimizing_swap_b(t_stack *a, t_stack *b);
void	optimizing_rotate_b(t_stack *a, t_stack *b, t_arg *arg, int *r);

#endif
