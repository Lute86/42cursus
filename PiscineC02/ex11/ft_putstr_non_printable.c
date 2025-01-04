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

void	convert(char c)
{
	char	hex_representation[2];

	hex_representation[0] = "0123456789abcdef"[(c >> 4) & 0xF];
	hex_representation[1] = "0123456789abcdef"[c & 0xF];
	write(1, hex_representation, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 0 && str[i] <= 32) || str[i] == 127)
		{
			write(1, "\\", 1);
			convert(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
