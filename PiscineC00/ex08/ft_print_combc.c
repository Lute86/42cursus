/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:38:41 by sluterea          #+#    #+#             */
/*   Updated: 2024/08/12 12:38:44 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(int n, int pos, int start, char *result)
{
	int	i;

	i = start;
	if (pos == n)
	{
		write(1, result, n);
		if (result[0] != '9' - n + 1)
		{
			write(1, ", ", 2);
		}
		return ;
	}
	while (i <= 9)
	{
		result[pos] = '0' + i;
		ft_print_comb(n, pos + 1, i + 1, result);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	result[10];

	ft_print_comb(n, 0, 0, result);
}
