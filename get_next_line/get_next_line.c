/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <sluterea@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:40:05 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/07 18:40:05 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define BUF_SIZE 1
/*
typedef struct line_str
{
	
} 
*/

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	check_content(size_t *prevlen, char **line, char *buf, int flag)
{
	size_t	i;
	size_t	j;

	i = *prevlen;
	j = *prevlen-1;
	if (!flag)
		while (buf[i] != '\n' && buf[i])
			i++;
	else
		while (buf[i] != '\n' && buf[i])
			i++;
	*line = malloc(i + 1);
	if (!*line)
		return (0);
	while (++j < i)
		(*line)[j] = buf[j];
	(*line)[i] = '\0';
	if (buf[i] == '\n')
	{
		*prevlen = ++i;
		return (1);
	}
	else
	{
		*prevlen = --i;
		return (-1);
	}
}

char	*get_next_line(int fd)
{
	static char	*line;
	static size_t	bytesread;
	static size_t	prevlen;
	char		*buf;
	int		status;

	buf = (char*)calloc(BUF_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	bytesread = read(fd, buf, BUF_SIZE);
	while (bytesread > 0)
	{
		status = check_content(&prevlen, &line, buf, 0);
		if (status == 1)
			return (line);
		bytesread = read(fd, buf, BUF_SIZE);
	}
	if (!bytesread)
	{
		//bucle hasta que prevb termine, puede no haber sido la ultima linea
		return (NULL);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*str;

	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else if (argc < 2)
		ft_putstr("File name missing.\n");
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("Cannot read file.\n");
			return (1);
		}
		str = get_next_line(fd);
		if (!str)
			printf("Nula");
		printf("%s", str);
		if (close(fd) == -1)
		{
			ft_putstr("Cannot close file.\n");
			return (1);
		}
	}
	return (0);
}
