#include "push_swap.h"

void	push_in_b(t_stack *a, t_stack *b, t_arg *arg, int *r)
{
	push(a, b, PUSH_A);
	(*r)--;
	arg->cnt_push++;
}

void	rotate_in_b(t_stack *b, t_arg *arg, int *r)
{
	rotate(NULL, b);
	(*r)--;
	arg->cnt_rb++;
}

void	quicksort_in_b(t_stack *a, t_stack *b, int r)
{
	t_arg	arg;

	if (escape_condition_in_b(a, b, r))
		return ;
	get_pivot(b, r, arg.pivot);
	init_cnt(&arg);
	while (r > 0)
	{
		if (b->stack->value > arg.pivot[1])
		{
			push_in_b(a, b, &arg, &r);
			if (a->head->value < arg.pivot[0])
				optimizing_rotate_b(a, b, &arg, &r);
		}
		else
		{
			if (is_whole_small(b, r, arg.pivot[1]))
				break ;
			rotate_in_b(b, &arg, &r);
		}
	}
	quicksort_in_a(a, b, arg.cnt_push - arg.cnt_ra);
	reset_rotate(a, b, arg);
	quicksort_in_a(a, b, arg.cnt_ra);
	quicksort_in_b(a, b, arg.cnt_rb + r);
}
