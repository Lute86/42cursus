/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:51:19 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/02 12:17:45 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Applies the function 'f' to each character in the string 's',
passing its index, and returns the new resulting string */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[i] != '\0')
	{
		i++;
	}
	str = (char *) malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	i = -1;
	while (s[++i] != '\0')
		str[i] = (f)(i, s[i]);
	return (str);
}
