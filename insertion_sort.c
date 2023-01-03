/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:26:26 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/02 10:42:36 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void insertion_sort(int *array, int len)
{
	int i;
	int j;
	int key;

	i = 1;
	while (i < len)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
		i++;
	}
}
void print_array(int *array, int len)
{
	int aux;

	aux = 0;
	while (aux < len)
	{
		printf("%d", array[aux]);
		printf("\n");
		aux++;
	}

}

int main(void)
{
	int len;
	int array[] = {-2, 10, 15, 4, 3, 9, 0, 25};

	len = sizeof(array) / sizeof(array[0]);
	insertion_sort(array, len);
	print_array(array, len);
	return (0);
}
