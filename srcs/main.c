/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:58:24 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/16 16:57:29 by hyunlee          ###   ########.fr       */
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

// int		check_arg(char **argv)
// {
// 	int	i;

// 	i = 0;
// 	while (argv[i])
// 	{

// 	}
// }

int		check_digit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i++]))
			return (0);
	}
	return (1);
}

int		check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strcmp(argv[i], argv[j++]))
				return (0);
		}
		i++;
	}
	return (1);
}

t_stack	*get_stack_a(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*temp;
	int		i;

	i = 1;
	// a = init_stack();
	if (!check_duplicate(argc, argv))
		return (NULL);
	while (argv[i])
	{
		if (!check_digit(argv[i]))
			return (NULL);

	}
}

int	main(int argc, char **argv)
{
	t_stack *a;

	// if (argc <= 1)
	// 	return (0);
	a = get_stack_a(argc, argv);
	// push_swap();
	return (0);
}
