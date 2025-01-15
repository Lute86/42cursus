/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <sluterea@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:41:36 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/07 18:41:36 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dst = (char *) malloc(len_s1 + len_s2 + 1);
	if (dst == NULL)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		dst[i] = s1[i];
	while (i < len_s1 + len_s2)
	{
		dst[i] = s2[i - len_s1];
		i++;
	}
	dst[i] = '\0';
	free(s1);
	return (dst);
}

char	*ft_strdup(const char *src)
{
	char	*s;
	int		len;
	int		i;

	i = -1;
	len = 0;
	while (src[++i] != '\0')
		len ++;
	s = (char *)malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	i = -1;
	while (src[++i] != '\0')
		s[i] = src[i];
	s[len] = '\0';
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = 0;
	while (s[s_len] != '\0')
		s_len++;
	if (start >= s_len)
		return (ft_strdup(""));
	i = 0;
	if (len > s_len - start)
		len = s_len - start;
	dst = (char *) malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*get_fill_content(char *content, int fd)
{
	char	*buffer;
	int	bytes_r;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_r = 1;
	while (!ft_strchr(buffer, '\n') && bytes_r > 0)
	{
		bytes_r = read(fd, buffer, BUFFER_SIZE);
		if (bytes_r == -1)
		{
		    free(buffer);
		    free(content);
		    return (NULL);
		}
		buffer[bytes_r] = '\0';
		content = ft_strjoin(content, buffer);
		if (!content)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (content);
}

char	*get_line_from_content(char *content)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!content[i])
		return (NULL);
	while (content[i] && content[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (content[i] && content[i] != '\n')
	{
		line[i] = content[i];
		i++;
	}
	if (content[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_content(char *content)
{
	char	*new_content;
	size_t	i;
	size_t	j;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (!content[i])
	{
		free(content);
		return (NULL);
	}
	new_content = malloc(ft_strlen(content) - i + 1);
	if (!new_content)
		return (NULL);
	i++;
	j = 0;
	while (content[i])
		new_content[j++] = content[i++];
	new_content[j] = '\0';
	free(content);
	return (new_content);
}

