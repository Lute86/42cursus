/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:11:02 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/02 12:17:45 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Creates a copy of the string 'src' and returns it */
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
