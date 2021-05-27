/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 02:27:01 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/28 02:27:02 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_ok(void)
{
	ft_putstr_fd(B_GREEN, STDOUT_FILENO);
	ft_putstr_fd("OK\n", STDOUT_FILENO);
	ft_putstr_fd(C_RESET, STDOUT_FILENO);
}

void	print_ko(void)
{
	ft_putstr_fd(B_RED, STDOUT_FILENO);
	ft_putstr_fd("KO\n", STDOUT_FILENO);
	ft_putstr_fd(C_RESET, STDOUT_FILENO);
}
