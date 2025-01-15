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

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s || !c)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	if (s[i] == (char) c)
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	i;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (++i < ft_strlen(s1))
		dst[i] = s1[i];
	i--;
	while (++i < (ft_strlen(s2) + ft_strlen(s1)))
		dst[i] = s2[i - ft_strlen(s1)];
	dst[i] = '\0';
	free(s1);
	return (dst);
}

char	*ft_strdup(const char *src)
{
	char	*s;
	int		len;
	int		i;

	if (!src)
		return (NULL);
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
