/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:11:02 by sluterea          #+#    #+#             */
/*   Updated: 2024/12/17 15:11:14 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
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
/*
int	main()
{
	ft_strdup("Hola");
	return 0;
}*/
