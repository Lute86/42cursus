/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:45:07 by sluterea          #+#    #+#             */
/*   Updated: 2024/08/19 19:45:11 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((s1[i] - s2[i]));
		}
		i++;
	}
	if (i != n)
		return (s1[i] - s2[i]);
	return (0);
}
/*
int main()
{
	int	test = ft_strncmp("leS", "lesx", 3);
	printf("%d", test);
	return 0;
}
*/
