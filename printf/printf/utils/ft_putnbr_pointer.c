/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <sluterea@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:47:09 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/07 14:47:09 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	ft_numlen_hex(unsigned long long num, int len)
{
	if (num == 0)
		return (1);
	while (num > 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

static void	show_nbr(unsigned long long nbr, char *base)
{
	unsigned long long	num;

	num = nbr;
	if (num >= (unsigned long long)16)
		show_nbr(num / 16, base);
	write(1, &base[num % 16], 1);
}

int	ft_putnbr_pointer(unsigned long long nbr, char *base)
{
	int	count;

	count = 0;
	show_nbr(nbr, base);
	count = ft_numlen_hex(nbr, count);
	return (count);
}
