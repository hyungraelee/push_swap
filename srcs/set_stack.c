#include "push_swap.h"

static t_element	*init_element(void)
{
	t_element	*res;

	res = (t_element *)malloc(sizeof(t_element));
	if (!res)
		return (NULL);
	res->value = 0;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

static t_element	*get_element(char *argv)
{
	t_element	*res;

	if (!argv)
		return (NULL);
	res = init_element();
	res->value = ft_atoi(argv);
	return (res);
}

t_stack		*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->stack = NULL;
	stack->cnt = 0;
	stack->max3 = (int *)malloc(sizeof(int) * 3);
	if (!stack->max3)
		return (NULL);
	return (stack);
}

static t_element	*get_stack(int argc, char **argv)
{
	t_element	*stack;
	t_element	*temp;
	int		i;

	i = 1;
	stack = NULL;
	temp = NULL;
	while (argv[i])
	{
		temp = get_element(argv[i++]);
		if (!temp)
			return (NULL);
		if (!stack)
			stack = temp;
		else
		{
			stack->next = temp;
			temp->prev = stack;
			stack = stack->next;
		}
	}
	return (stack);
}

static int	count_element(char **argv)
{
	int	i;
	int	cnt;

	i = 1;
	cnt = 0;
	while (argv[i++])
		cnt++;
	return (cnt);
}

int					third_max(t_stack *a)
{
	int	max;

	if (a->stack->value == a->max3[0] || a->stack->value == a->max3[1])
		a->stack = a->stack->next;
	if (a->stack->value == a->max3[0] || a->stack->value == a->max3[1])
		a->stack = a->stack->next;
	max = a->stack->value;
	while (a->stack)
	{
		if (a->stack->value != a->max3[0] && a->stack->value != a->max3[1])
		{
			if (a->stack->value > max)
				max = a->stack->value;
		}
		if (a->stack->next)
			a->stack = a->stack->next;
		else
			break ;
	}
	a->stack = a->head;
	return (max);
}

int					second_max(t_stack *a)
{
	int	max;

	if (a->stack->value == a->max3[0])
		a->stack = a->stack->next;
	max = a->stack->value;
	while (a->stack)
	{
		if (a->stack->value != a->max3[0])
		{
			if (a->stack->value > max)
				max = a->stack->value;
		}
		if (a->stack->next)
			a->stack = a->stack->next;
		else
			break ;
	}
	a->stack = a->head;
	return (max);
}

int					first_max(t_stack *a)
{
	int	max;

	max = a->stack->value;
	while (a->stack)
	{
		if (a->stack->value > max)
			max = a->stack->value;
		if (a->stack->next)
			a->stack = a->stack->next;
		else
			break ;
	}
	a->stack = a->head;
	return (max);
}

void	get_max3(t_stack *a)
{
	a->max3[0] = first_max(a);
	a->max3[1] = second_max(a);
	a->max3[2] = third_max(a);
}

t_stack				*set_stack(int argc, char **argv)
{
	t_stack	*a;

	check_arg(argc, argv);
	a = init_stack();
	a->stack = get_stack(argc, argv);
	a->tail = a->stack;
	while (a->stack->prev)
		a->stack = a->stack->prev;
	a->head = a->stack;
	a->cnt = count_element(argv);
	if (a->cnt > 3)
		get_max3(a);
	return (a);
}
