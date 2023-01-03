/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:54:31 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/03 15:22:22 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void number_check(char *array, t_swap *new)
{
	int	aux;

	aux = 0;
	while (array[aux])
	{
		if (array[aux] == '+' || array[aux] == '-')
			aux++;
		if (array[aux] >= '0' && array[aux] <= '9')
			aux++;
		if (!array[aux])
			break;
		if (!(array[aux] >= '0' && array[aux] <= '9') && !(array[aux] == ' '))
		{
			write(1, "Error.\n", 7);
			exit_swap(new);
		}
	}
}

void	free_array(char **array)
{
	char	**beginning;

	beginning = array;
	while (beginning && *array)
			free(*array++);
	free(beginning);
}

char	get_stack(char **argv)
{
	int		i;
	int		j;
	char	**split;
	char	*res;
	char	*temp;

	i = 0;
	res = ft_calloc(2047, sizeof(char *)); //insert ft_calloc
	while (argv[++i])
	{
		split = ft_split(argv[i], ' '); //insert ft_split
		j = -1;
		while (split[++j])
		{
			temp = res;
			res = ft_strjoin(res, split[j]);
			free(temp);
			temp = res;
			res = ft_strjoin(res, " ");
			free(temp);
		}
		free_array(split);
	}
	return (res);
}

void	values_setting(char *string, t_swap *new)
{
	//implement atoi
	//use number_check
}
