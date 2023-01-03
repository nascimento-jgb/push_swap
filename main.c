/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:52:38 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/02 14:31:51 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void exit_swap(t_swap *new)
{
	free(new->stack_a);
	free(new->stack_b);
	free(new->index_stack);
	free(new->len_a);
	free(new->len_b);
	free(new->sorted);
	return (0);
}

void init_struct(t_swap *new)
{

}

int main (int argc, char **argv)
{
	t_swap *new;

	if (argc > 1)
	{
		//initialize the structure
		init_struct(new);
		//find indexes
		if (argc == 3)
			sort_2(new);
		else if (argc == 4)
			sort_3(new);
		else if (argc == 5)
			sort_4(new);
		else if (argc == 6)
			sort_5(new);
		radix_sort(new);
	}
	else
	{
		write(1, "Error.\n", 7);
		return (0);
	}
	exit_swap(new);
	return (0);
}
