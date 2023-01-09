/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:25:00 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/09 13:30:05 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	push(t_list **list_from, t_list **list_to, char *msg)
{
	t_list	*aux;

	if (!(*list_from))
		return ;
	else
	{
		aux = *list_from;
		*list_from = (*list_from)->next;
		aux->next = *list_to;
		*list_to = aux;
	}
	ft_putstr_fd(msg, 1);
}
