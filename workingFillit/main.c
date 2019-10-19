/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:42:17 by xlongfel          #+#    #+#             */
/*   Updated: 2019/10/19 22:02:36 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	int		count;
	char	*buff;
	char	**mapsolution;

	if (argc != 2)
	{
		write(1, "usage: source_file\n", 19);
		return (0);
	}
	buff = ft_strnew(1024);
	count = 0;
	if ((fd = open(argv[1], O_RDONLY)) >= 0)
	{
		ret = read(fd, buff, 1024);
		if (is_input_valid(buff))
		{
			mapsolution = make2darray(buff, &count);
			int c = 0;
			int p = 0;
			while (mapsolution[c])
				printf("figure %d:\n%s\n", p++, mapsolution[c++]);
			solve(mapsolution, count);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("error\n");
	int k;
	k = 0;
	while (k < 26)
	{
		printf("cleaned %d\n", k);
		free(mapsolution[k++]);
	}
	free(mapsolution);
	return (0);
}
