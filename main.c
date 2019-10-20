/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:42:17 by xlongfel          #+#    #+#             */
/*   Updated: 2019/10/20 18:09:23 by xlongfel         ###   ########.fr       */
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

int				main(int argc, char **argv)
{
	int		fd;
	int		ret;
	int		count;
	char	*buff;
	char	**mapsolution;

	if (argc != 2 && (mapsolution = NULL))
		write(1, "usage: source_file\n", 19);
	buff = ft_strnew(1024);
	count = 0;
	if ((fd = open(argv[1], O_RDONLY)) >= 0)
	{
		ret = read(fd, buff, 1024);
		if (is_input_valid(buff))
		{
			mapsolution = make2darray(buff, &count);
			solve(mapsolution, count);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("error\n");
	free1(mapsolution);
	return (0);
}
