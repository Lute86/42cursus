/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:14:34 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/02 12:17:44 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Allocates memory for an array of x (nmemb) elements 
(each of size size) and initializes it to zero */
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	size_t	i;
	void	*pm;

	i = 0;
	total_size = nmemb * size;
	if (size && nmemb > total_size / size)
		return (NULL);
	pm = malloc(total_size);
	if (pm == NULL)
		return (NULL);
	while (i < total_size)
	{
		((unsigned char *)pm)[i] = 0;
		i++;
	}
	return (pm);
}
