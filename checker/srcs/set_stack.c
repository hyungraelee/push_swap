/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 02:27:03 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/28 02:27:04 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_element	*get_element(char *argv)
{
	t_element	*res;

	if (!argv)
		return (NULL);
	res = init_element();
	res->value = ft_atoi(argv);
	return (res);
}

static t_element	*get_stack(char **argv)
{
	t_element	*stack;
	t_element	*temp;
	int			i;

	i = 0;
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

static void			get_mid(t_stack *a)
{
	int	min;
	int	max;

	min = a->stack->value;
	max = a->stack->value;
	while (a->stack)
	{
		if (a->stack->value < min)
			min = a->stack->value;
		else if (a->stack->value > max)
			max = a->stack->value;
		if (a->stack->next)
			a->stack = a->stack->next;
		else
			break ;
	}
	a->stack = a->head;
	a->mid = (min + max) / 2;
}

t_stack				*set_stack(int argc, char **argv)
{
	t_stack	*a;

	check_arg(argc, argv);
	a = init_stack();
	a->stack = get_stack(argv);
	a->tail = a->stack;
	while (a->stack->prev)
		a->stack = a->stack->prev;
	a->head = a->stack;
	a->cnt = argc;
	if (a->cnt == 5)
		get_mid(a);
	return (a);
}
