#include "push_swap.h"

// void	set_src_stack(t_stack *src)
// {
// 	if (src->stack)
// 	{
// 		src->first = src->stack;
// 		if (src->second->next)
// 			src->second = src->second->next;
// 		else
// 			src->second = NULL;
// 		src->first->prev = NULL;
// 		src->stack = src->first;
// 		while (src->stack->next)
// 			src->stack = src->stack->next;
// 		src->last = src->stack;
// 		src->stack = src->first;
// 	}
// 	else
// 	{
// 		src->first = NULL;
// 		src->second = NULL;
// 		src->last = NULL;
// 		src->stack = NULL;
// 	}
// }

void	push_stack(t_stack *src, t_stack *des)
{
	if (src->cnt > 0)
	{
		src->stack = src->stack->next;
		if (des->cnt == 0)
		{
			des->stack = src->head;
			des->head = des->stack;
			des->head->prev = NULL;
			des->head->next = NULL;
			if (src->cnt > 1)
			{
				src->head = src->stack;
				src->head->prev = NULL;
			}
			else
			{
				src->head = NULL;
				src->tail = NULL;
				src->stack = NULL;
			}
			des->tail = NULL;
			des->cnt++;
			src->cnt--;
		}
		else if (des->cnt >= 1)
		{
			des->head = src->head;
			des->head->next = des->stack;
			des->stack->prev = des->head;
			des->stack = des->head;
			if (src->cnt > 1)
			{
				src->head = src->stack;
				src->head->prev = NULL;
			}
			else
			{
				src->head = NULL;
				src->tail = NULL;
				src->stack = NULL;
			}
			if (des->cnt == 1)
				des->tail = des->head->next;
			des->cnt++;
			src->cnt--;
		}
	}
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
