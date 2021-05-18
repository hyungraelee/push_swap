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

t_stack	*get_stack_a(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*temp;
	int		i;

	i = 1;
	a = NULL;
	temp = NULL;
	check_arg(argc, argv);
	while (argv[i])
	{
		temp = get_token_a(argv[i++]);
		if (!temp)
			return (NULL);
		if (!a)
			a = temp;
		else
		{
			a->next = temp;
			temp->prev = a;
			a = a->next;
		}
	}
	while (a->prev)
		a = a->prev;
	return (a);
}

