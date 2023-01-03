/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:07:49 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/03 15:22:20 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_swap
{
	int	*stack_a;
	int	*stack_b;
	int *sorted_stack;
	int	*sorted_index;
	int	len_a;
	int	len_b;
}	t_swap;

/* main */
void	exit_swap(t_swap *new);
t_swap	*init_struct(char **argv);
void	initial_checks(t_swap *new);

/* setting structure */
void	free_array(char **array);
char	get_stack(char **argv);
void	values_setting(char *array, t_swap *new);

/* checking control */
int		valid_input(char *array);
void	check_all_number(char *array, t_swap *new);
void	check_duplicate(t_swap *new);
int		check_sorted(t_swap *new);

#endif
