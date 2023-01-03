/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:45:36 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/03 16:07:10 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_input(char *array)
{
	return ((array[0] == '+' && (array[1] == '+' || array[1] == '-')) ||
		(array[0] == '-' && (array[1] == '+' || array[1] == '-')) ||
		(array[0] == '+' && !(ft_isdigit[1])) ||
		(array[0] == '-' && !(ft_isdigit[1]))); //inclide ft_isdigit
}

void	check_all_number(char *array, t_swap *new)
{
	int i;

	i = 0;
	while (array[i])
	{
		if (ft_isdigit(array[i] || array[i] == ' ') || !valid_input(&array[i])) // include ft_isdigit
			++i;
		else
		{
			write(1, "Error.\n", 7);
			exit_swap(new);
		}
	}
}

void	check_duplicate(t_swap *new)
{
	int	i;

	i = 0;
	while (i < new->len_a)
	{
		if (new->stack_a[i] == new->stack_a[i + 1])
		{
			write(1, "Error.\n", 7);
			exit_swap(new);
		}
		i++;
	}
}

int	check_sorted(t_swap *new)
{
	int i;

	i = 0;
	while (i < new->len_a - 1)
	{
		if (new->stack_a[i] > new->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	exit_swap(new);
	return (1);
}
