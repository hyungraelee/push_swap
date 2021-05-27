/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 02:26:47 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/28 02:26:48 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_err(char *str)
{
	ft_putstr_fd(B_RED, STDOUT_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(C_RESET, STDOUT_FILENO);
	exit(1);
}
