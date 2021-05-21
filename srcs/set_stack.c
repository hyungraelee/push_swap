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
	stack->first = NULL;
	stack->second = NULL;
	stack->last = NULL;
	stack->stack = NULL;
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

t_stack				*set_stack(int argc, char **argv)
{
	t_stack	*a;

	check_arg(argc, argv);
	a = init_stack();
	a->stack = get_stack(argc, argv);
	a->last = a->stack;
	while (a->stack->prev)
		a->stack = a->stack->prev;
	a->first = a->stack;
	a->second = a->stack->next;
	return (a);
}
