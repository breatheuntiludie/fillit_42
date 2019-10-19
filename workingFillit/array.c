/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:03:37 by ggeri             #+#    #+#             */
/*   Updated: 2019/10/19 21:23:23 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checktetris(char *block)
{
	int		number;
	int		i;

	i = 0;
	number = 0;
	while (i < 20)
	{
		if (block[i] == '#')
		{
			if (i >= 1 && block[i - 1] == '#')
				number++;
			if (i < 19 && block[i + 1] == '#')
				number++;
			if (i >= 5 && block[i - 5] == '#')
				number++;
			if (i < 15 && block[i + 5] == '#')
				number++;
		}
		i++;
	}
	if (number == 6 || number == 8)
		return (1);
	return (0);
}

int		checkmap(char *block)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (!(block[i * 5 + j] == '.' || block[i * 5 + j] == '#'))
				return (0);
			if (block[i * 5 + j] == '#')
				count++;
			j++;
		}
		if (block[i * 5 + j] != '\n')
			return (0);
		j = 0;
		i++;
	}
	if (count != 4)
		return (0);
	return (1);
}

int		is_input_valid(char *buff)
{
	int		i;
	char	*block;

	i = 0;
	block = ft_strnew(20);
	while (i < 26)
	{
		ft_strncpy(block, &(buff[i * 21]), 20);
		if (!checkmap(block) || !checktetris(block))
		{
			free(block);
			return (0);
		}
		i++;
		if (buff[i * 20 + (i - 1)] == '\0')
			break ;
	}
	free(block);
	return (1);
}

char	**make2darray(char *buff, int *count)
{
	char	**newarray;
	int		i;
	int		j;
	int		k;

	newarray = (char**)ft_memalloc(27 * sizeof(*newarray));
	i = 0;
	while (i < 26)
		newarray[i++] = ft_strnew(16);
	i = 0;
	k = 0;
	j = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '.')
		{
			newarray[j][k] = '.';
			k++;
		}
		else if (buff[i] == '#')
		{
			newarray[j][k] = 'A' + j;
			k++;
		}
		if (buff[i] == '\n' && buff[i + 1] == '\n')
		{
			j++;
			k = 0;
		}
		if (buff[i] == '\n' && buff[i + 1] != '\n')
			k = k;
		i++;
	}
	*count = j;
	return (newarray);
}
