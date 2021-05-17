/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:58:24 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/17 18:23:56 by hyunlee          ###   ########.fr       */
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

int		ft_atoi(char *str)
{
	long long	res;
	int			sign;
	int			cnt;

	res = 0;
	sign = 1;
	cnt = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	// to cnt check (length str ex)900000000000000 of ex)000000000000000001 )
	while (*str)
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	res *= sign;
	if (res < -2147483648 || res > 2147483647)
		exit(1);
	// return ((int))\
}

t_stack	*get_token_a(char *argv)
{
	t_stack	*res;

	if (!argv)
		return (NULL);
	res = init_stack();
	res->value = ft_atoi(argv);
	return (res);
	// to check if argv is in integer range
}

t_stack	*get_stack_a(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*temp;
	int		i;

	i = 1;
	a = NULL;
	temp = NULL;
	if (!check_duplicate(argc, argv))
		return (NULL);
	while (argv[i])
	{
		if (!check_digit(argv[i]))
			return (NULL);
		temp = get_token_a(argv[i]);
		if (!temp)
			return (NULL);
		if (!a)
			a = temp;
		else
		{
			a->next = temp;
			temp->prev = a;
			a = a->next;
		}
	}
	while (a->prev)
		a = a->prev;
	return (a);
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
