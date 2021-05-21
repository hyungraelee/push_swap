#include "push_swap.h"

void	set_src_stack(t_stack *src)
{
	if (src->stack)
	{
		src->first = src->stack;
		if (src->second->next)
			src->second = src->second->next;
		else
			src->second = NULL;
		src->first->prev = NULL;
		src->stack = src->first;
		while (src->stack->next)
			src->stack = src->stack->next;
		src->last = src->stack;
		src->stack = src->first;
	}
	else
	{
		src->first = NULL;
		src->second = NULL;
		src->last = NULL;
		src->stack = NULL;
	}
}

void	push_stack(t_stack *src, t_stack *des)
{
	src->stack = src->stack->next;
	if (!des->stack)
	{
		des->first = src->first;
		des->stack = des->first;
		des->second = NULL;
		des->last = des->stack;
		des->first->next = NULL;
	}
	else
	{
		src->first->next = des->first;
		des->first->prev = src->first;
		des->second = des->first;
		des->first = src->first;
		des->stack = des->first;
	}
	set_src_stack(src);
}

void	push(t_stack *a, t_stack *b, int type)
{
	if (type == PUSH_A)
	{
		ft_putstr_fd("pa\n", STDOUT_FILENO);
		push_stack(b, a);
	}
	else if (type == PUSH_B)
	{
		ft_putstr_fd("pb\n", STDOUT_FILENO);
		push_stack(a, b);
	}
}
