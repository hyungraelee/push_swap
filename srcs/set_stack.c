#include "push_swap.h"

static t_stack	*init_stack(void)
{
	t_stack	*res;

	res = (t_stack *)malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->value = 0;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

static t_stack	*get_token_a(char *argv)
{
	t_stack	*res;

	if (!argv)
		return (NULL);
	res = init_stack();
	res->value = ft_atoi(argv);
	return (res);
}

static t_a		*init_a(void)
{
	t_a	*a;

	a = (t_a *)malloc(sizeof(t_a));
	if (!a)
		return (NULL);
	a->first = NULL;
	a->second = NULL;
	a->last = NULL;
	a->stack = NULL;
	return (a);
}

static t_stack	*get_stack_a(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*temp;
	int		i;

	i = 1;
	stack = NULL;
	temp = NULL;
	while (argv[i])
	{
		temp = get_token_a(argv[i++]);
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

t_a				*set_stack(int argc, char **argv)
{
	t_a	*a;

	check_arg(argc, argv);
	a = init_a();
	a->stack = get_stack_a(argc, argv);
	a->last = a->stack;
	while (a->stack->prev)
		a->stack = a->stack->prev;
	a->first = a->stack;
	a->second = a->stack->next;
	return (a);
}
