/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <sluterea@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:41:51 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/07 18:41:51 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t		ft_strlen(const char *s);
int			ft_putstr(char *str);
int			ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*get_fill_content(char *content, int fd);
char		*get_line_from_content(char *content);
char		*update_content(char *content);
char		*get_next_line(int fd);

#endif
