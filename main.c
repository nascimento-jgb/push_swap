/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:52:38 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/03 15:13:03 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_swap(t_swap *new)
{
	free(new->stack_a);
	free(new->stack_b);
	free(new->sorted_stack);
	free(new->sorted_index);
	free(new);
	return (0);
}

t_swap	*init_struct(char **argv)
{
	t_swap	*swap;
	char	**array;
	char	*string;
	int		lenght;

	lenght = 0;
	string = get_stack(argv);
	array = ft_split(array, ' '); //include ft_split
	while (string[len])
		len++;
	swap = ft_calloc(1, sizeof(t_swap)); //inclide ft_calloc
	swap->stack_a = malloc(sizeof(int) * len);
	swap->stack_b = malloc(sizeof(int) * len);
	swap->sorted_stack = malloc(sizeof(int) * len);
	swap->sorted_index = malloc(sizeof(int) * len);
	values_setting(string, new)
	check_all_number(array, swap);
	free_array(array);
	free(string);
	return(swap);
}

void	initial_checks(t_swap *new)
{
	check_sorted(new);
	check_duplicate(new);
}

int	main(int argc, char **argv)
{
	t_swap	*new;

	if (argc > 1)
	{
		//initialize the structure
		new = init_struct(new);
		initial_checks(new);
		//find indexes
		//one argument
		//small sorting
		if (argc == 4)
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
