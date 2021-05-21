/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:58:24 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/21 19:42:58 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc <= 1)
		print_err(ERR_MSG0);
	a = set_stack(argc, argv);
	b = init_stack();
	while (a->stack)
	{
		printf("%d\n", a->stack->value);
		if (a->stack->next)
			a->stack = a->stack->next;
		else
			break ;
	}
	printf("first %d\n", a->first->value);
	printf("second %d\n", a->second->value);
	printf("last %d\n", a->last->value);
	printf("stack a\n");
	a->stack = a->first;
	while (b->stack)
	{
		printf("%d\n", b->stack->value);
		if (b->stack->next)
			b->stack = b->stack->next;
		else
			break ;
	}
	// printf("first %d\n", b->first->value);
	// printf("second %d\n", b->second->value);
	// printf("last %d\n", b->last->value);
	printf("stack b\n");
	b->stack = b->first;
	// swap(a, NULL);
	push(a, b, PUSH_B);
	while (a->stack)
	{
		printf("%d\n", a->stack->value);
		if (a->stack->next)
			a->stack = a->stack->next;
		else
			break ;
	}
	// printf("first %d\n", a->first->value);
	// printf("second %d\n", a->second->value);
	// printf("last %d\n", a->last->value);
	printf("stack a\n");
	a->stack = a->first;
	while (b->stack)
	{
		printf("%d\n", b->stack->value);
		if (b->stack->next)
			b->stack = b->stack->next;
		else
			break ;
	}
	// printf("first %d\n", b->first->value);
	// printf("second %d\n", b->second->value);
	// printf("last %d\n", b->last->value);
	printf("stack b\n");
	b->stack = b->first;
	// push_swap(a, b);
	return (0);
}
