/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_phase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:42:22 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/14 15:32:50 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	shortest_path_second_phase(t_list **b, int largest, int len)
{
	long	*array;
	int		i;
	int		top;
	int		bottom;

	i = 0;
	top = 0;
	bottom = 1;
	array = transfer_into_array(*b, len);
	while (array[i++] != largest)
		top++;
	while (array[--len] != largest)
		bottom++;
	if (top <= bottom)
		rotate_some_b(b, top);
	else
		reverse_rotate_some_b(b, bottom);
	free(array);
	array = NULL;
}

int	select_largest(t_list **b, int nbr, t_helper *aux, bool flag_to_2nd)
{
	long	*array;
	int		i;
	int		top;
	int		bottom;
	int		temp_len;

	temp_len = aux->len;
	i = 0;
	top = 0;
	bottom = 1;
	array = transfer_into_array(*b, aux->len);
	while (array[i++] != nbr)
		top++;
	while (array[--aux->len] != nbr)
		bottom++;
	aux->len = temp_len;
	if (top <= bottom) // maybe can be changed for <= lets wait for the tests
		return (top);
	else
		{
			if (flag_to_2nd == true)
				aux->reverse_flag = true;
			return (bottom);
		}
}

void	second_phase_sorting(t_list **a, t_list **b)
{
	t_helper	aux;
	long		*array;
	int			i;

	while(*b)
	{
		ft_bzero(&aux, sizeof(t_helper));
		aux.len = size_list(*b);
		array = transfer_into_array(*b, aux.len);
		quick_sort(array, 0, aux.len - 1);
		printf("hey6\n");
		aux.shortest_largest = select_largest(b, array[aux.len - 1], &aux, false);
		if (aux.len != 1)
			aux.shortest_2nd_largest = select_largest(b, array[aux.len - 2], &aux, true);
		printf("hey7\n");
		if (aux.shortest_2nd_largest < aux.shortest_largest)
		{
			printf("hey8\n");
			push_second_largest(a, b, array[aux.len -1], &aux);
			printf("hey9\n");
		}
		else
		{
			printf("hey10\n");
			push_largest(a, b, array[aux.len -1], &aux);
			printf("hey11\n");
		}
		printf("hey12\n");
		while (array[i])
			ft_free((void *)array[i++]);
		printf("hey13\n");
	}
}
