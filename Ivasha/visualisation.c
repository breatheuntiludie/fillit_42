/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:48:47 by ggeri             #+#    #+#             */
/*   Updated: 2019/10/17 20:07:54 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_list1(t_list **head)
{
	int		i;
	t_list	*print;

	i = 0;
	print = *head;
	while (print)
	{
		write(1, "Number:", 7);
		ft_putchar(i + '0');
		write(1, "\n", 1);
		ft_putstr(print->content);
		write(1, "\n", 1);
		print = print->next;
		i++;
	}
}
