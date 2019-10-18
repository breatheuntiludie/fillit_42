/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:24:13 by xlongfel          #+#    #+#             */
/*   Updated: 2019/10/17 13:31:25 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void    *ft_memsett(void *b, int c, int len)
{
    int    i;
    char    *arr;
    
    i = 0;
    arr = b;
    while (i < len)
    {
        arr[i] = c;
        i++;
    }
    return (arr);
}

char	*ft_strnew(int size)
{
	char	*t;

	if (size + 1 == 0)
		return (NULL);
	t = (char *)malloc(sizeof(char) * (size + 1));
	if (!t)
		return (0);
	ft_memsett(t, 0, size + 1);
	return (t);
}
