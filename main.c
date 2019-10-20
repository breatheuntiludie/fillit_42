/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:42:17 by xlongfel          #+#    #+#             */
/*   Updated: 2019/10/20 19:58:50 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		free1(char **mapsolution)
{
	int i;

	i = 0;
	while (i < 27)
	{
		free(mapsolution[i]);
		i++;
	}
	free(mapsolution);
}

static int		check(int argc)
{
	int			error;

	error = 0;
	if (argc != 2)
	{
		write(1, "usage: source file\n", 19);
		error = 1;
	}
	return (error);
}

int				main(int argc, char **argv)
{
	int		fd;
	int		ret;
	int		count;
	char	buff[1024];
	char	**mapsolution;

	mapsolution = NULL;
	if (check(argc) == 1)
		return (0);
	count = 0;
	if ((fd = open(argv[1], O_RDONLY)) >= 0)
	{
		ret = read(fd, buff, 1024);
		if (is_input_valid(buff))
		{
			mapsolution = make2darray(buff, &count);
			solve(mapsolution, count);
			free1(mapsolution);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("error\n");
	return (0);
}
