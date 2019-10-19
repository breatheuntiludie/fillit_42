/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:46:29 by ggeri             #+#    #+#             */
/*   Updated: 2019/10/19 14:32:08 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int				fd;
	static t_list	*head;

	if (argc != 2)
	{
		write(1, "usage: source_file\n", 19);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (processing_fd(fd, &head) == BUFF_ERROR)
	{
		write(1, "error\n", 6);
		close(fd);
		return (0);
	}
	close(fd);

	print_list1(&head);
	clear_list(&head);
	return (0);
}
