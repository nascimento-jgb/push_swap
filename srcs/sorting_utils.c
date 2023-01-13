/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:22:01 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/13 11:47:36 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_largest(t_list *list)
{
	int	largest;

	largest = INT_MIN;
	while(list != NULL)
	{
		if (largest < list->data)
			largest = list->data;
		list = list->next;
	}
	return (largest);
}

void	sorting_three_numbers(t_list **list)
{
	while (check_sorted(*list) == false)
	{
		if ((*list)->data == find_largest(*list))
			rotate(list, "ra\n");
		else if ((*list)->data > (*list)->next->data)
			swap(*list, "sa\n");
		else
			reverse_rotate(list, "rra\n");
	}
}

long	*transfer_into_array(t_list *list, int len)
{
	long	*array;
	int		i;

	i = 0;
	array = malloc(sizeof(long) * len);
	if (!array)
		exit_failure("Malloc error.\n");
	while (list)
	{
		array[i++] = list->data;
		list = list->next;
	}
	array[i] = '\0';
	return (array);
}
