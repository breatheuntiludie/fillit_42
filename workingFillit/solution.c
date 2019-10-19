/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:18:03 by xlongfel          #+#    #+#             */
/*   Updated: 2019/10/19 20:23:15 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**emptymap(int const size)
{
	char	**map;
	int		i;
	int		j;

	if (!(map = (char **)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	map[size] = NULL;
	i = -1;
	while (++i < size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		map[i][size] = '\0';
	}
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (j < size)
			map[i][j++] = '.';
	}
	return (map);
}

void	rmshape(char **m, char index, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (m[i][j] == ('A' + index))
				m[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		tryshape(char *sp, char **m, int mc)
{
	int		i;
	int		f;
	int		s;

	f = 0;
	s = ft_strlen(m[0]);
	while (sp[f] == '.')
		f++;
	i = 0;
	while (i < 16)
	{
		if (sp[i] != '.')
			if (mc / s + i / 4 - f / 4 >= s ||
					mc % s + i % 4 - f % 4 >= s ||
					m[mc / s + i / 4 - f / 4][mc % s + i % 4 - f % 4] != '.')
				return (0);
		i++;
	}
	i = -1;
	while (sp[++i])
		if (sp[i] != '.')
			m[mc / s + i / 4 - f / 4][mc % s + i % 4 - f % 4] = sp[i];
	return (1);
}

int		trymap(char **shapes, char **map, int shapeindex, int shapecount)
{
	int		mapcoor;
	int		mapsize;

//	printf("check07: trymap\n");
	mapsize = ft_strlen(map[0]);
	mapcoor = 0;
	while (mapcoor < mapsize * mapsize)
	{
		//printf("check07:mapcoor=%d ", mapcoor);
		if (tryshape(shapes[shapeindex], map, mapcoor) == 1)
		{
			if (shapeindex == shapecount - 1 ||
					trymap(shapes, map, shapeindex + 1, shapecount))
				return (1);
			rmshape(map, shapeindex, mapsize);
			//printf("__check07:rmshape->success__\n");
		}
		mapcoor++;
	}
	return (0);
}

void	solve(char **shapes, int shapecount)
{
	char	**map;
	int		mapsize;
	int		i;

	int k;//delete
	//printf("check06: solve\n");
	mapsize = 1;
	while (mapsize * mapsize < shapecount * 4)
		mapsize++;
	while (1)
	{
		map = emptymap(mapsize);
		//printf("\ncheck06:solve:mapsize=%d\nemptymap:\n", mapsize);
		//k = 0;//delete
		//while(map[k])
			//printf("%s\n",map[k++]);
		if (trymap(shapes, map, 0, shapecount))
			break ;
		i = 0;
		while (i < mapsize)
			free(map[++i]);
		free(map);
		map = NULL;
		mapsize++;
	}
	i = 0;
	while (map[i])
		ft_putendl(map[i++]);
//	printf("check06: end of solving\n");
}
