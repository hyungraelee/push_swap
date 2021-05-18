/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:58:24 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/19 00:29:45 by hyunlee          ###   ########.fr       */
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
	a = get_stack_a(argc, argv);
	b = NULL;
	// while (a)
	// {
	// 	printf("%d\n", a->value);
	// 	if (a->next)
	// 		a = a->next;
	// 	else
	// 		break ;
	// }
	push_swap(a, b);
	return (0);
}
