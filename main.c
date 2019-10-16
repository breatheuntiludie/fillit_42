/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:46:29 by ggeri             #+#    #+#             */
/*   Updated: 2019/10/16 17:32:06 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int				fd;
	static t_list	*head;

	if (argc != 2)
	{
		write(1, "usage: source_file", 18);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (processing_fd(fd, &head) == BUFF_ERROR)
	{
		write(1, "error", 5);
		close (fd);
		return (0);
	}
	close(fd);

	t_list	*print;
	print = head;
	int i = 1;
	while (print)
	{
		printf("Number:%d\nfigure:\n%s________\n", i, print->content);
		i++;
		print=print->next;
	}
	clear_list(&head);
	return (0);
}
