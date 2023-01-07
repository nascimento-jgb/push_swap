/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:31:36 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/07 17:08:11 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_failure(char *error)
{
	ft_putstr_fd(error, 2);
	exit (1);
}

bool	check_sorted(t_list *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (false);
		a = a->next;
	}
	return (true);
}

static bool	fill_stack_a(t_list *a, char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if(!create_node(a, ft_atoi(array[i++])))
		{
			ft_free_array(array);
			return (false);
		}
	}
	ft_free_array(array);
	return (true);
}

int	main(int argc, char **argv)
{
	char **array;
	t_list *a;
	t_list *b;

	if (argc != 1)
	{
		array = get_arguments(argc, argv);
		if (!check_arguments(array) || !fill_stack_a(&a, array))
		{
			free_list(a, b);
			ft_free_array(argv);
			exit_failure("Error.\n");
		}
	}
	else
		return (0);
	if (check_sorted(a) == true)
	{
		free_list(a, b);
		return (1);
	}
	//firt step into sorting (&a, &b)
	free_list(a, b);
	return (0);
}
