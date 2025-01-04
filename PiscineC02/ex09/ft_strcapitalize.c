/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:44:55 by sluterea          #+#    #+#             */
/*   Updated: 2024/08/13 14:45:01 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	convert(int i, int flag, char *str)
{
	while (str[i] != '\0')
	{
		if ((i == 0 && str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = str[i] - 32;
		}
		if ((flag == 0 && i != 0 && str[i] >= 'A' && str[i] <= 'Z'))
		{
			str[i] = str[i] + 32;
		}
		if ((flag == 1 && str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = str[i] - 32;
			flag = 0;
		}
		if ((str[i] < 'A' || str[i] > 'Z' && str[i] < 'a' || str[i] > 'z'))
		{
			flag = 1;
		}
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	convert(i, flag, str);
	return (str);
}
