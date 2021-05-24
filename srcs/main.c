/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:58:24 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/24 17:18:11 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	test_print(t_stack *a)
{
	while (a->stack)
	{
		printf("%d\n", a->stack->value);
		if (a->stack->next)
			a->stack = a->stack->next;
		else
			break;
	}
	a->stack = a->head;
	// printf("head: %d, cnt: %d\n", a->head->value, a->cnt);
	// printf("head: %d, tail: %d, cnt: %d\n", a->head->value, a->tail->value, a->cnt);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc <= 1)
		return (0);
		// print_err(ERR_MSG0);
	a = set_stack(argc, argv);
	b = init_stack();
	// test_print(a);
	// swap(a, NULL);
	// rotate(a, NULL);
	// rev_rotate(a, NULL);
	// push(a, b, PUSH_B);
	// push(a, b, PUSH_B);
	// swap(NULL, b);
	// test_print(a);
	// test_print(b);
	// push(a, b, PUSH_A);
	// test_print(a);
	// test_print(b);
	push_swap(a, b);
	test_print(a);
	return (0);
}
