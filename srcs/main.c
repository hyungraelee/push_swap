/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:58:24 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/14 23:53:42 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
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

t_stack	*get_stack_a(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*temp;
	int		i;

	// if (argc <= 1)
	// 	return ();
	i = 1;
	// a = init_stack();
	while (argv[i])
	{
		;
	}
}

int	main(int argc, char **argv)
{
	t_stack *a;

	a = get_stack_a(argc, argv);
	// push_swap();
	return (0);
}
