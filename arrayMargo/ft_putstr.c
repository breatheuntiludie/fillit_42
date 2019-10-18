/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:32:11 by xlongfel          #+#    #+#             */
/*   Updated: 2019/10/17 13:28:59 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void		ft_put(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_put(s[i]);
		i++;
	}
}
