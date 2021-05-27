#include "push_swap.h"

t_element	*init_element(void)
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
	return (stack);
}

static int	count_double_arr(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	**join_double_arr(char **des, char **src)
{
	int		des_cnt;
	int		src_cnt;
	char	**result;
	int		i;
	int		j;

	des_cnt = count_double_arr(des);
	src_cnt = count_double_arr(src);
	result = (char **)malloc(sizeof(char *) * (des_cnt + src_cnt + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < des_cnt)
		result[i] = des[i];
	j = 0;
	while (j < src_cnt)
		result[i++] = src[j++];
	free(des);
	free(src);
	result[i] = NULL;
	return (result);
}

char		**init_arg(int *argc, char **argv)
{
	char	**result;
	char	**temp;
	int		i;

	i = 1;
	result = NULL;
	while (i < *argc)
	{
		temp = ft_split(argv[i++], ' ');
		if (!result)
			result = temp;
		else
			result = join_double_arr(result, temp);
	}
	*argc = count_double_arr(result);
	return (result);
}
