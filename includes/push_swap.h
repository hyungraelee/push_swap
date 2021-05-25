/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:57:44 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/25 21:27:08 by hyunlee          ###   ########.fr       */
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

# define PUSH_A 1
# define PUSH_B 2

# define SA 1
# define SB 2
# define SS 4
# define PA 8
# define PB 16
# define RA 32
# define RB 64
# define RR 128
# define RRA 256
# define RRB 512
# define RRR 1024


int		push_swap(t_stack *a, t_stack *b);
void	print_err(char *str);
void	check_arg(int argc, char **argv);
t_stack	*set_stack(int argc, char **argv);
t_stack	*init_stack(void);
void	push(t_stack *a, t_stack *b, int type);
void	swap(t_stack *a, t_stack *b);
void	rotate(t_stack *a, t_stack *b);
void	rev_rotate(t_stack *a, t_stack *b);
void	free_all(t_stack *a, t_stack *b);

#endif
