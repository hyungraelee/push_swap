#include "push_swap.h"

int	is_b_sorted(t_stack *b)
{
	if (b->cnt == 0)
		return (1);
	while (b->stack->next)
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

int	is_a_sorted(t_stack *a)
{
	if (a->cnt == 0)
		return (1);
	while (a->stack->next)
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

int	is_finish(t_stack *a, t_stack *b)
{
	if (is_a_sorted(a))
	{
		if (b->cnt == 0 && b->stack == NULL)
			return (1);
	}
	return (0);
}

int	find_max_b(t_stack *b)
{
	int	cnt;
	int	cnt_max;
	int	max;

	cnt = 1;
	cnt_max = 1;
	max = b->stack->value;
	while (b->stack)
	{
		if (b->stack->value > max)
		{
			max = b->stack->value;
			cnt_max = cnt;
		}
		if (b->stack->next)
			b->stack = b->stack->next;
		else
			break ;
		cnt++;
	}
	b->max3[0] = max;
	b->stack = b->head;
	return (cnt_max);
}

int	push_swap(t_stack *a, t_stack *b)
{
	if (a->cnt < 3)
	{
		if (a->head->value > a->head->next->value)
			swap(a, NULL);
	}
	else if (a->cnt == 3)
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
	{
		while (a->stack->value != a->mid)
		{
			if (a->stack->value != a->max3[0] && a->stack->value != a->max3[1] && a->stack->value != a->max3[2])
			{
				if (a->stack->value < a->mid)
					push(a, b, PUSH_B);
				else
					rotate(a, NULL);
			}
			else
				rotate(a, NULL);
		}
		while (a->cnt > 3)
		{
			if (a->stack->value != a->max3[0] && a->stack->value != a->max3[1] && a->stack->value != a->max3[2])
				push(a, b, PUSH_B);
			else
			{
				if (a->cnt < 6)
				{
					if (a->tail->value != a->max3[0] && a->tail->value != a->max3[1] && a->tail->value != a->max3[2])
						rev_rotate(a, NULL);
					else
						rotate(a, NULL);
				}
				else
					rotate(a, NULL);
			}
		}
		if (!is_a_sorted(a))
		{
			if (a->head->value == a->max3[2])
			{
				swap(a, NULL);
				rotate(a, NULL);
			}
			else if (a->head->value == a->max3[1])
			{
				if (a->tail->value == a->max3[0])
					swap(a, NULL);
				else
					rev_rotate(a, NULL);
			}
			else if (a->head->value == a->max3[0])
			{
				if (a->tail->value == a->max3[2])
				{
					swap(a, NULL);
					rev_rotate(a, NULL);
				}
				else
					rotate(a, NULL);
			}
		}
		while (!is_finish(a, b))
		{
			if (find_max_b(b) <= (b->cnt / 2))
			{
				while (b->head->value != b->max3[0])
					rotate(NULL, b);
			}
			else
			{
				while (b->head->value != b->max3[0])
					rev_rotate(NULL, b);
			}
			push(a, b, PUSH_A);
		}
	}
	free_all(a, b);
	return (1);
}
