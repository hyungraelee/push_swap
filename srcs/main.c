/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:58:24 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/21 16:59:27 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_a *a;
	t_b *b;

	if (argc <= 1)
		print_err(ERR_MSG0);
	a = set_stack(argc, argv);
	b = NULL;
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
	while (a->stack->prev)
		a->stack = a->stack->prev;
	swap(a, NULL);
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
	// push_swap(a, b);
	return (0);
}
