#include "push_swap.h"

static void	swap_stack(t_stack *a)
{
	a->stack = a->stack->next;
	a->stack->prev->next = a->stack->next;
	a->stack->prev->prev = a->stack;
	a->stack->next = a->stack->prev;
	a->stack->prev = NULL;
	a->first = a->stack;
	a->second = a->stack->next;
}

void		swap(t_stack *a, t_stack *b)
{
	if (a && b)
	{
		ft_putstr_fd("ss\n", STDOUT_FILENO);
		swap_stack(a);
		swap_stack(b);
	}
	else if (a && !b)
	{
		ft_putstr_fd("sa\n", STDOUT_FILENO);
		swap_stack(a);
	}
	else if (!a && b)
	{
		ft_putstr_fd("sb\n", STDOUT_FILENO);
		swap_stack(b);
	}
}
