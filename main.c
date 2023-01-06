/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:31:36 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/06 15:10:55 by jonascim         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char **array;
	t_list *a;
	t_list *b;

	if (argc != 1)
	{
		array = get_arguments(argc, argv);
		// if check argumets OR fill stack A fails
		{
			free_list(a, b);
			ft_free_array(argv);
			exit_failure("Error. \n");
		}
	}
	else
		return (0);
	if (check_sorted(a) == true)
	{
		free_list(a, b); //implement this function
		return (1);
	}
	//firt step into sorting
	free_list(a, b);
	return (0);
}
