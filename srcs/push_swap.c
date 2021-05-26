#include "push_swap.h"

int	is_b_sorted(t_stack *b, int r)
{
	if (b->cnt == 0)
		return (1);
	while (r--)
	{
		if (b->stack->value < b->stack->next->value)
		{
			b->stack = b->head;
			return (0);
		}
		b->stack = b->stack->next;
	}
	b->stack = b->head;
	return (1);
}

int	is_a_sorted(t_stack *a, int r)
{
	if (a->cnt == 0)
		return (1);
	while (r--)
	{
		if (a->stack->value > a->stack->next->value)
		{
			a->stack = a->head;
			return (0);
		}
		a->stack = a->stack->next;
	}
	a->stack = a->head;
	return (1);
}

void	get_pivot(t_stack *a, int r, int *pivot)
{
	int	min;
	int	max;

	min = a->stack->value;
	max = a->stack->value;
	while (r--)
	{
		if (a->stack->value < min)
			min = a->stack->value;
		else if (a->stack->value > max)
			max = a->stack->value;
		a->stack = a->stack->next;
	}
	a->stack = a->head;
	pivot[0] = (min + max) / 2;
	pivot[1] = (pivot[0] + min) / 2;
	if (pivot[0] == pivot[1])
		pivot[0] = pivot[1] + 1;
}

void	optimizing_swap_a(t_stack *a, t_stack *b)
{
	if (b->head && b->head->next)
	{
		if (b->head->value < b->head->next->value)
			swap(a, b);
		else
			swap(a, NULL);
	}
	else
		swap(a, NULL);
}

void	handle_3_in_a(t_stack *a, t_stack *b)
{
	if (a->stack->value < a->stack->next->next->value && a->stack->next->next->value < a->stack->next->value)
	{
		rotate(a, NULL);
		optimizing_swap_a(a, b);
		rev_rotate(a, NULL);
	}
	else if (a->stack->next->value < a->stack->value && a->stack->value < a->stack->next->next->value)
	{
		optimizing_swap_a(a, b);
	}
	else if (a->stack->next->next->value < a->stack->value && a->stack->value < a->stack->next->value)
	{
		rotate(a, NULL);
		optimizing_swap_a(a, b);
		rev_rotate(a, NULL);
		optimizing_swap_a(a, b);
	}
	else if (a->stack->next->value < a->stack->next->next->value && a->stack->next->next->value < a->stack->value)
	{
		optimizing_swap_a(a, b);
		rotate(a, NULL);
		optimizing_swap_a(a, b);
		rev_rotate(a, NULL);
	}
	else if (a->stack->next->next->value < a->stack->next->value && a->stack->next->value < a->stack->value)
	{
		optimizing_swap_a(a, b);
		rotate(a, NULL);
		optimizing_swap_a(a, b);
		rev_rotate(a, NULL);
		optimizing_swap_a(a, b);
	}
}

int		is_whole_big(t_stack *a, int r, int pivot)
{
	while (r--)
	{
		if (a->stack->value <= pivot)
			return (0);
		a->stack = a->stack->next;
	}
	a->stack = a->head;
	return (1);
}

void	sort_a_to_b(t_stack *a, t_stack *b, int r)
{
	int	pivot[2];
	int	cnt_ra;
	int	cnt_rb;
	int	cnt_pb;
	int	tmp;

	a->stack = a->head;
	if (r == 0 || r == 1)
		return ;
	else if (r == 2)
	{
		if (a->stack->value > a->stack->next->value)
			optimizing_swap_a(a, b);
		return ;
	}
	else if (r == 3)
	{
		handle_3_in_a(a, b);
		return ;
	}
	else if (is_a_sorted(a, r))
		return ;
	get_pivot(a, r, pivot);
	cnt_ra = 0;
	cnt_rb = 0;
	cnt_pb = 0;
	while (r > 0)
	{
		if (a->stack->value > pivot[0])
		{
			if (is_whole_big(a, r, pivot[0]))
				break ;
			rotate(a, NULL);
			cnt_ra++;
		}
		else
		{
			push(a, b, PUSH_B);
			cnt_pb++;
			if (b->head->value > pivot[1])
			{
				rotate(NULL, b);
				cnt_rb++;
			}
		}
		r--;
	}
	if (cnt_rb > cnt_ra) // same as b to a
	{
		tmp = cnt_ra;
		while (tmp-- > 0)
			rev_rotate(a, b);
		tmp = cnt_rb - cnt_ra;
		while (tmp-- > 0)
			rev_rotate(NULL, b);
	}
	else
	{
		tmp = cnt_rb;
		while (tmp-- > 0)
			rev_rotate(a, b);
		tmp = cnt_ra - cnt_rb;
		while (tmp-- > 0)
			rev_rotate(a, NULL);
	}
	sort_a_to_b(a, b, cnt_ra + r);
	sort_b_to_a(a, b, cnt_rb);
	sort_b_to_a(a, b, cnt_pb - cnt_rb);
}

void	optimizing_swap_b(t_stack *a, t_stack *b)
{
	if (a->head && a->head->next)
	{
		if (a->head->value > a->head->next->value)
			swap(a, b);
		else
			swap(NULL, b);
	}
	else
		swap(NULL, b);
}

void	handle_3_in_b(t_stack *a, t_stack *b)
{
	if (b->stack->value < b->stack->next->value && b->stack->next->value < b->stack->next->next->value)
	{
		optimizing_swap_b(a, b);
		rotate(NULL, b);
		optimizing_swap_b(a, b);
		rev_rotate(NULL, b);
		optimizing_swap_b(a, b);
	}
	else if (b->stack->value < b->stack->next->next->value && b->stack->next->next->value < b->stack->next->value)
	{
		optimizing_swap_b(a, b);;
		rotate(NULL, b);
		optimizing_swap_b(a, b);
		rev_rotate(NULL, b);
	}
	else if (b->stack->next->value < b->stack->value && b->stack->value < b->stack->next->next->value)
	{
		rotate(NULL, b);
		optimizing_swap_b(a, b);
		rev_rotate(NULL, b);
		optimizing_swap_b(a, b);
	}
	else if (b->stack->next->next->value < b->stack->value && b->stack->value < b->stack->next->value)
	{
		optimizing_swap_b(a, b);
	}
	else if (b->stack->next->value < b->stack->next->next->value && b->stack->next->next->value < b->stack->value)
	{
		rotate(NULL, b);
		optimizing_swap_b(a, b);
		rev_rotate(NULL, b);
	}
}

int		is_whole_small(t_stack *b, int r, int pivot)
{
	while (r--)
	{
		if (b->stack->value > pivot)
			return (0);
		b->stack = b->stack->next;
	}
	b->stack = b->head;
	return (1);
}

void	sort_b_to_a(t_stack *a, t_stack *b, int r)
{
	int	pivot[2];
	int	cnt_ra;
	int	cnt_rb;
	int	cnt_pa;
	int	tmp;

	b->stack = b->head;
	if (r == 0)
		return ;
	else if (r == 1)
	{
		push(a, b, PUSH_A);
		return ;
	}
	else if (r == 2)
	{
		if (b->stack->value < b->stack->next->value)
			optimizing_swap_b(a, b);
		push(a, b, PUSH_A);
		push(a, b, PUSH_A);
		return ;
	}
	else if (r == 3)
	{
		handle_3_in_b(a, b);
		push(a, b, PUSH_A);
		push(a, b, PUSH_A);
		push(a, b, PUSH_A);
		return ;
	}
	else if (is_b_sorted(b, r))
	{
		while (r--)
			push(a, b, PUSH_A);
		return ;
	}
	get_pivot(b, r, pivot);
	cnt_ra = 0;
	cnt_rb = 0;
	cnt_pa = 0;
	while (r > 0)
	{
		if (b->stack->value > pivot[1])
		{
			push(a, b, PUSH_A);
			cnt_pa++;
			if (a->head->value < pivot[0])
			{
				rotate(a, NULL);
				cnt_ra++;
			}
		}
		else
		{
			if (is_whole_small(b, r, pivot[1]))
				break ;
			rotate(NULL, b);
			cnt_rb++;
		}
		r--;
	}
	sort_a_to_b(a, b, cnt_pa - cnt_ra);
	if (cnt_rb > cnt_ra)
	{
		tmp = cnt_ra;
		while (tmp-- > 0)
			rev_rotate(a, b);
		tmp = cnt_rb - cnt_ra;
		while (tmp-- > 0)
			rev_rotate(NULL, b);
	}
	else
	{
		tmp = cnt_rb;
		while (tmp-- > 0)
			rev_rotate(a, b);
		tmp = cnt_ra - cnt_rb;
		while (tmp-- > 0)
			rev_rotate(a, NULL);
	}
	sort_a_to_b(a, b, cnt_ra);
	sort_b_to_a(a, b, cnt_rb + r);
}

void	quick_sort(t_stack *a, t_stack *b, int r)
{
	sort_a_to_b(a, b, r);
}

int	push_swap(t_stack *a, t_stack *b, int r)
{
	if (a->cnt == 3)
	{
		if (a->head->value < a->tail->value && a->tail->value < a->head->next->value)
		{
			swap(a, NULL);
			rotate(a, NULL);
		}
		else if (a->head->next->value < a->head->value && a->head->value < a->tail->value)
			swap(a, NULL);
		else if (a->tail->value < a->head->value && a->head->value < a->head->next->value)
			rev_rotate(a, NULL);
		else if (a->tail->value < a->head->next->value && a->head->next->value < a->head->value)
		{
			swap(a, NULL);
			rev_rotate(a, NULL);
		}
		else
			rotate(a, NULL);
	}
	else
		quick_sort(a, b, r);
	free_all(a, b);
	return (1);
}
