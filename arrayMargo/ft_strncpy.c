/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:58:52 by xlongfel          #+#    #+#             */
/*   Updated: 2019/10/17 13:30:19 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, int len)
{
	int	i;
	int		wow;

	i = 0;
	wow = 0;
	while (i < len)
	{
		if (src[i] == '\0')
			wow = 1;
		if (wow == 1)
		{
			dst[i] = '\0';
			i++;
		}
		else
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
