/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:46:35 by ggeri             #+#    #+#             */
/*   Updated: 2019/10/17 20:07:32 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft/libft.h"

#include <stdio.h>

# define BUFF_ONE 1
# define BUFF_TWO 20
# define BUFF_ERROR -1

int					processing_fd(int fd, t_list **head);
void				clear_list(t_list **head);

void				print_list1(t_list **head);

#endif
