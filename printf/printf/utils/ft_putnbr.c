/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <sluterea@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:07:25 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/07 16:07:25 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	ft_numlen(int num, int len)
{
	if (num == 0)
		return (1);
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	num;
	int	i;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	i = 0;
	num = n;
	if (n < 0)
	{
		i++;
		num = -num;
	}
	i = ft_numlen(num, i);
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (i);
}
