/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:07:49 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/09 14:24:22 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "libft.h"

typedef struct	s_list
{
	int	data;
	struct s_list *next;
}	t_list;

// main
void			exit_failure(char *error);
bool			check_sorted(t_list *a);
static bool		fill_stack_a(t_list *a, char **array);

// get arguments
static char		**oneline_arguments(char **argv);
static char		**multiple_arguments(int argc, char **argv);
char			**get_arguments(int argc, char **argv);

// check arguments
static int		array_lenght(char **array);
static bool		check_digits(char **array);
static bool		check_duplicates(char *array, int lenght);
bool			check_arguments(char **array);

// quick sorting
static void		swap_position(long *a, long *b);
static int		partition(long *str, int lower, int higher);
void			quick_sort(long *str, int lower, int higher);

// list utils
void			free_list(t_list *a, t_list *b);
int				size_list(t_list *list);
static t_list	*last_node(t_list *node);
bool			create_node(t_list **list, int number);

// push operation
void			push(t_list **list_from, t_list **list_to, char *msg);

// swap operation
void			swap(t_list *list, char *msg);
void			double_swap(t_list *a, t_list *b);

// rotate operation
void			rotate(t_list **list, char *msg);
void			double_rotate(t_list **a, t_list **b);

// reverese rotate
void			reverse_rotate(t_list **list, char *msg);
void			double_reverse_rotate(t_list **a, t_list **b);

// sorting utils
static int		find_largest(t_list *list);
void			sorting_three_numbers(t_list **list);
long			transfer_into_array(t_list *list, int len);

#endif
