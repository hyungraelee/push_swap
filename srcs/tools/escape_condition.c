#include "push_swap.h"

int	escape_condition_in_a(t_stack *a, t_stack *b, int r)
{
	if (r == 0 || r == 1)
		;
	else if (r == 2)
	{
		if (a->stack->value > a->stack->next->value)
			optimizing_swap_a(a, b);
	}
	else if (r == 3)
		handle_3_in_a(a, b);
	else if (is_a_sorted(a, r))
		;
	else
		return (0);
	return (1);
}

int	escape_condition_in_b(t_stack *a, t_stack *b, int r)
{
	if (r == 0)
		;
	else if (r == 1)
		push(a, b, PUSH_A);
	else if (r == 2)
	{
		if (b->stack->value < b->stack->next->value)
			optimizing_swap_b(a, b);
		while (r--)
			push(a, b, PUSH_A);
	}
	else if (r == 3)
	{
		handle_3_in_b(a, b);
		while (r--)
			push(a, b, PUSH_A);
	}
	else if (is_b_sorted(b, r))
	{
		while (r--)
			push(a, b, PUSH_A);
	}
	else
		return (0);
	return (1);
}
