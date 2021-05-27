#include "checker.h"

static void	free_stack(t_stack *a)
{
	while (a->stack)
	{
		if (a->stack->next)
		{
			a->stack = a->stack->next;
			free(a->stack->prev);
		}
		else
		{
			free(a->stack);
			break ;
		}
	}
}

void	free_double_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_all(t_stack *a, t_stack *b, char **arg)
{
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
	free_double_arr(arg);
}
