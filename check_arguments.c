/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:36:15 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/09 14:27:37 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	array_lenght(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static bool	check_digits(char **array)
{
	int		i;
	int		j;
	bool	sign;

	i = 0;
	sign = false;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][0] == '-' && !sign)
			{
				j++;
				sign = true;
			}
			if(!ft_isdigit(array[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static bool	check_duplicates(char *array, int lenght)
{
	int	i;

	i = 0;
	while (i < lenght - 1)
	{
		if (array[i] == array[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool	check_arguments(char **array)
{
	long	*str;
	int		i;

	if (!check_digits(array))
		return (false);
	i = 0;
	str = malloc(sizeof(long) * array_lenght(array));
	if (!str)
	{
		free(str);
		return (false);
	}
	while (array[i])
	{
		str[i] = ft_atol(array[i]);
		if (str[i] > 2147483647 || str[i++] < -2147483648)
			return (false);
	}
	quick_sort(str, 0 , i - 1);
	if (!check_duplicates(str, i))
	{
		free(str);
		return (false);
	}
	free(str);
	return (true);
}
