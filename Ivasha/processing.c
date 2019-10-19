/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:44:53 by ggeri             #+#    #+#             */
/*   Updated: 2019/10/16 19:06:06 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		clear_list(t_list **head)
{
	t_list *helper;
	t_list *prev;

	helper = *head;
	while (helper)
	{
		prev = helper->next;
		free(helper->content);
		free(helper);
		helper = prev;
	}
}

static void	add_list(t_list **head, char *temp)
{
	t_list	*temp1;

	if (!(*head))
	{
		*head = (t_list*)malloc(sizeof(t_list));
		(*head)->content = ft_strdup(temp);
		(*head)->next = NULL;
		temp1 = *head;
	}
	else
	{
		temp1 = *head;
		while (temp1->next)
			temp1 = temp1->next;
		temp1->next = (t_list*)malloc(sizeof(t_list));
		temp1 = temp1->next;
		temp1->content = ft_strdup(temp);
		temp1->next = NULL;
	}
}

static int	check2(char *temp)
{
	int i;
	int check;
	int hash;

	i = 0;
	check = 0;
	hash = 0;
	while (temp[i] != '\0')
	{
		while (temp[i] != '\n' && (temp[i] == '.' || temp[i] == '#'))
		{
			if (temp[i] == '#')
				hash++;
			check++;
			i++;
		}
		if (check != 4)
			return (BUFF_ERROR);
		check = 0;
		i++;
	}
	if (hash != 4)
		return (BUFF_ERROR);
	return (0);
}

static int	check(char *temp)
{
	int		i;
	int		check1;
	int		check3;

	i = 0;
	check1 = 0;
	check3 = 0;
	if (ft_strlen(temp) != 20 || check2(temp) == BUFF_ERROR)
		return (BUFF_ERROR);
	while (temp[i] != '\0')
	{
		if (temp[i] == '#')
		{
			if (temp[i + 1] == '#')
				check1++;
			if (temp[i + 5] == '#')
				check3++;
		}
		i++;
	}
	if ((check1 == 2 && check3 == 2) || (check3 == 2 && check1 == 1) || \
			(check1 == 3 && check3 == 0) || (check1 == 2 && check3 == 1) || \
			(check3 == 3 && check1 == 0))
		return (0);
	return (BUFF_ERROR);
}

int			processing_fd(int fd, t_list **head)
{
	char	temp[BUFF_TWO + 1];

	ft_bzero(temp, BUFF_TWO + 1);
	while ((read(fd, temp, BUFF_TWO)) > 0)
	{
		if (check(temp) == BUFF_ERROR)
		{
			clear_list(head);
			return (BUFF_ERROR);
		}
		else
		{
			add_list(head, temp);
			ft_bzero(temp, BUFF_TWO);
			read(fd, temp, BUFF_ONE);
		}
	}
	if (ft_strchr(temp, '\n') != NULL)
	{
		clear_list(head);
		return (BUFF_ERROR);
	}
	return (0);
}
