/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:57:44 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/21 16:50:26 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "structures.h"
# include "utils.h"

# define ERR_MSG0 "Error : Please input some arguments.\n"
# define ERR_MSG1 "Error : There are duplicate arguments.\n"
# define ERR_MSG2 "Error : Some arguments aren't integer.\n"
# define ERR_MSG3 "Error : Some arguments are bigger than an integer.\n"

int		push_swap(t_stack *a, t_stack *b);
void	print_err(char *str);
void	check_arg(int argc, char **argv);
t_a		*set_stack(int argc, char **argv);
void	swap(t_a *a, t_b *b);

#endif
