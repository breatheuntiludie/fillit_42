/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:52:51 by xlongfel          #+#    #+#             */
/*   Updated: 2019/10/17 13:43:35 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		checktetris(char *block);
int		checkmap(char *block);
int		is_input_valid(char *buff);
char	**make2darray(char *buff, int *count);
char	**emptymap(int const size);
void	rmshape(char **m, char index, int size);
int		tryshape(char *sp, char **m, int mc);
int		trymap(char **shapes, char **map, int shapeindex, int shapecount);
void	solve(char **shapes, int shapecount);
void            *ft_memalloc(size_t size);
void            *ft_memset(void *b, int c, size_t len);
void            ft_putchar(char c);
void            ft_putendl(char const *s);
void            ft_putstr(char const *s);
size_t            ft_strlen(const char *str);
char            *ft_strncpy(char *dst, const char *src, size_t len);
char            *ft_strnew(size_t size);

#endif
