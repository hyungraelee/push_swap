/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:58:24 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/26 22:27:12 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	test_print(t_stack *a)
{
	while (a->stack)
	{
		printf("%d", a->stack->value);
		if (a->stack->next)
			a->stack = a->stack->next;
		else
			break;
	}
	a->stack = a->head;
	// printf("head: %d, cnt: %d\n", a->head->value, a->cnt);
	// printf("head: %d, tail: %d, cnt: %d\n", a->head->value, a->tail->value, a->cnt);
}

int		count_double_arr(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**join_double_arr(char **des, char **src)
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

char	**init_arg(int *argc, char **argv)
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

void	print_double_arr(char **arg)
{
	int	i = 0;

	while (arg[i])
		printf("%s\n", arg[i++]);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	char	**arg;

	if (argc <= 1)
		return (0);
	arg = init_arg(&argc, argv);
	a = set_stack(argc, arg);
	b = init_stack();
	push_swap(a, b, argc);
	// test_print(a);
	return (0);
}
