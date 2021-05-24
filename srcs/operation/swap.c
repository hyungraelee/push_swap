#include "push_swap.h"

static void	swap_stack(t_stack *a)
{
	if (a->cnt > 1)
	{
		a->stack = a->stack->next;
		a->stack->prev->next = a->stack->next;
		a->stack->prev->prev = a->stack;
		if (a->stack->next)
			a->stack->next->prev = a->stack->prev;
		a->stack->next = a->stack->prev;
		a->stack->prev = NULL;
		a->head = a->stack;
		if (a->cnt == 2)
			a->tail = a->head->next;
	}
}

void		swap(t_stack *a, t_stack *b, int *operate)
{
	if (a && b)
	{
		ft_putstr_fd("ss\n", STDOUT_FILENO);
		*operate &= ~SA;
		*operate &= ~SB;
		swap_stack(a);
		swap_stack(b);
	}
	else if (a && !b)
	{
		ft_putstr_fd("sa\n", STDOUT_FILENO);
		*operate &= ~SA;
		swap_stack(a);
	}
	else if (!a && b)
	{
		ft_putstr_fd("sb\n", STDOUT_FILENO);
		*operate &= ~SB;
		swap_stack(b);
	}
}
