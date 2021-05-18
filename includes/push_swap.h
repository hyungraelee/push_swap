/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:57:44 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/18 22:38:36 by hyunlee          ###   ########.fr       */
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

void	print_err(char *str);
void	check_arg(int argc, char **argv);
t_stack	*get_stack_a(int argc, char **argv);

#endif
