/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:35:25 by joaonascime       #+#    #+#             */
/*   Updated: 2023/01/13 12:19:41 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		lenght;
	char	*aux;

	lenght = ft_strlen(str) + 1;
	aux = (char *)malloc(sizeof(char) * lenght);
	if (!aux)
		return (NULL);
	lenght = 0;
	ft_strlcpy(aux, str, lenght);
	return (aux);
}
