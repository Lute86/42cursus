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
#ifndef MAX_FD
# define MAX_FD 1024
#endif

int	save_lines_fill(char **buffer, int *bytes_r, int fd, char **content)
{
	if (fd < 0)
		return (-1);
	*buffer = malloc(BUFFER_SIZE + 1);
	if (!*buffer)
	{
		free(*content);
		return (-1);
	}
	*bytes_r = read(fd, *buffer, BUFFER_SIZE);
	while (*bytes_r > 0)
	{
		(*buffer)[*bytes_r] = '\0';
		*content = ft_strjoin(*content, *buffer);
		if (!*content)
		{
			free(*buffer);
			return (-1);
		}
		if (ft_strchr(*content, '\n'))
			break ;
		*bytes_r = read(fd, *buffer, BUFFER_SIZE);
	}
	return (1);
}

char	*get_fill_content(char *content, int fd)
{
	char	*buffer;
	int		bytes_r;

	buffer = NULL;
	bytes_r = 0;
	if (save_lines_fill(&buffer, &bytes_r, fd, &content) == -1)
		return (NULL);
	if (bytes_r == -1)
	{
		free(buffer);
		free(content);
		return (NULL);
	}
	free(buffer);
	return (content);
}

char	*get_line_from_content(char *content)
{
	char	*line;
	size_t	len;

	if (!content || !content[0])
		return (NULL);
	len = 0;
	while (content[len] && content[len] != '\n')
		len++;
	if (content[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	while (len-- > 0)
		line[len] = content[len];
	return (line);
}

char	*update_content(char *content)
{
	char	*new_content;
	size_t	i;
	size_t	remaining;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (!content[i])
	{
		free(content);
		return (NULL);
	}
	remaining = ft_strlen(content + ++i);
	new_content = malloc(remaining + 1);
	if (!new_content)
	{
		free(content);
		return (NULL);
	}
	remaining = 0;
	while (content[i])
		new_content[remaining++] = content[i++];
	new_content[remaining] = '\0';
	free(content);
	return (new_content);
}

char	*get_next_line(int fd)
{
	static char	*content[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	content[fd] = get_fill_content(content[fd], fd);
	if (!content[fd])
		return (NULL);
	line = get_line_from_content(content[fd]);
	if (!line)
	{
		free(content[fd]);
		content[fd] = NULL;
		return (NULL);
	}
	content[fd] = update_content(content[fd]);
	return (line);
}
