/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:58:24 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/18 22:38:07 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack *a;

	if (argc <= 1)
		print_err(ERR_MSG0);
	a = get_stack_a(argc, argv);
	while (a)
	{
		printf("%d\n", a->value);
		if (a->next)
			a = a->next;
		else
			break ;
	}
	// push_swap();
	return (0);
}
