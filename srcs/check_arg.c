/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:17:13 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/27 21:17:14 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
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

static int	check_integer_format(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j++]))
				return (0);
		}
		i++;
	}
	return (1);
}

static int	check_integer_range(char **argv)
{
	int	i;
	int	j;
	int	flag;
	int	cnt;

	i = 0;
	while (argv[i])
	{
		j = 0;
		flag = 0;
		cnt = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j++] != '0')
				flag = 1;
			if (flag == 1)
				cnt++;
			if (cnt >= 11)
				return (0);
		}
		i++;
	}
	return (1);
}

void		check_arg(int argc, char **argv)
{
	if (!check_duplicate(argc, argv))
		print_err(ERR_MSG1);
	if (!check_integer_format(argv))
		print_err(ERR_MSG2);
	if (!check_integer_range(argv))
		print_err(ERR_MSG3);
}
