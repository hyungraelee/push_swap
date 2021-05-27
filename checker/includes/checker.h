/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 02:24:59 by hyunlee           #+#    #+#             */
/*   Updated: 2021/05/28 02:25:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include "structures.h"
# include "utils.h"
# include "get_next_line.h"

# define BUFFER_SIZE 5000

# define PUSH_A 1
# define PUSH_B 2

# define B_RED "\033[1;5;31m"
# define B_GREEN "\033[1;5;92m"
# define C_RESET "\e[0m"

# define ERR_MSG1 "Error : There are duplicate arguments.\n"
# define ERR_MSG2 "Error : Some arguments aren't integer.\n"
# define ERR_MSG3 "Error : Some arguments are bigger than an integer.\n"

char		**init_arg(int *argc, char **argv);
t_stack		*init_stack(void);
t_element	*init_element(void);
t_stack		*set_stack(int argc, char **argv);
void		check_arg(int argc, char **argv);
void		print_err(char *str);

void		checker(t_stack *a, t_stack *b, int r);

int			is_push(char *operation);
int			is_swap(char *operation);
int			is_rotate(char *operation);
int			is_rev_rotate(char *operation);

void		push_handler(t_stack *a, t_stack *b, char *operation);
void		swap_handler(t_stack *a, t_stack *b, char *operation);
void		rotate_handler(t_stack *a, t_stack *b, char *operation);
void		rev_rotate_handler(t_stack *a, t_stack *b, char *operation);

void		push(t_stack *a, t_stack *b, int type);
void		swap(t_stack *a, t_stack *b);
void		rotate(t_stack *a, t_stack *b);
void		rev_rotate(t_stack *a, t_stack *b);

void		print_ok(void);
void		print_ko(void);

void		free_all(t_stack *a, t_stack *b, char **arg);
void		free_double_arr(char **arr);

#endif
