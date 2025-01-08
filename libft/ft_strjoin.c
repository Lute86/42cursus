/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:12:03 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/02 12:17:45 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Join the strings 's1' and 's2' into a new string */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = 0;
	while (s1[len_s1] != '\0')
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2] != '\0')
		len_s2++;
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
	return (dst);
}
