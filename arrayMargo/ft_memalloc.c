/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:27:18 by xlongfel          #+#    #+#             */
/*   Updated: 2019/10/17 13:27:38 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(int size)
{
	unsigned char	*t;
	int			i;

	i = 0;
	t = malloc(sizeof(char) * (size));
	if (!t)
		return (0);
	while (i < size)
	{
		t[i] = '\0';
		i++;
	}
	return (t);
}
