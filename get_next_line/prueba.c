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

#define BUFFER_SIZE 1
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

int check_content(size_t *prevlen, char **line, char *buf)
{
    size_t i;
    char *temp;
    
    i = 0;
    while (buf[i] != '\n' && buf[i])
        i++;
        
    if (!*line)
    {
        // First allocation
        *line = malloc((i + 1) * sizeof(char));
        if (!*line)
            return (0);
        i = 0;
        while (buf[i] && buf[i] != '\n')
        {
            (*line)[i] = buf[i];
            i++;
        }
        (*line)[i] = '\0';
    }
    else
    {
        // Subsequent allocations
        temp = *line;
        *line = malloc((*prevlen + i + 1) * sizeof(char));
        if (!*line)
        {
            free(temp);
            return (0);
        }
        strncpy(*line, temp, *prevlen);
        i = 0;
        while (buf[i] && buf[i] != '\n')
        {
            (*line)[*prevlen + i] = buf[i];
            i++;
        }
        (*line)[*prevlen + i] = '\0';
        free(temp);
    }
    
    if (buf[i] == '\n')
        return (1);
    *prevlen += i;
    return (-1);
}

char *get_next_line(int fd)
{
    static char *line = NULL;
    static size_t prevlen = 0;
    char *buf;
    ssize_t bytesread;
    int status;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
        
    buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buf)
        return (NULL);
        
    while ((bytesread = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[bytesread] = '\0';
        status = check_content(&prevlen, &line, buf);
        if (status == 1)
        {
            free(buf);
            char *temp = line;
            line = NULL;
            prevlen = 0;
            return (temp);
        }
    }
    
    free(buf);
    if (line && *line)
    {
        char *temp = line;
        line = NULL;
        prevlen = 0;
        return (temp);
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
		while (str != NULL)
		{	
			printf("%s", str);
			str = get_next_line(fd);
			if (!str)
				printf("Nula");
		}
		if (close(fd) == -1)
		{
			ft_putstr("Cannot close file.\n");
			return (1);
		}
	}
	return (0);
}
