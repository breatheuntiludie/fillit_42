/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:52:51 by xlongfel          #+#    #+#             */
/*   Updated: 2019/10/19 21:24:03 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "libft/libft.h"

int		checktetris(char *block);
int		checkmap(char *block);
int		is_input_valid(char *buff);
char	**make2darray(char *buff, int *count);
char	**emptymap(int const size);
void	rmshape(char **m, char index, int size);
int		tryshape(char *sp, char **m, int mc);
int		trymap(char **shapes, char **map, int shapeindex, int shapecount);
void	solve(char **shapes, int shapecount);

#endif
