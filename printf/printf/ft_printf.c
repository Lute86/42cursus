/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <sluterea@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:25:20 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/04 14:25:20 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_type(const char *str, size_t i, va_list args)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count = print_char((char)va_arg(args, int));
	if (str[i] == 's')
		count = print_str(va_arg(args, char *));
	if (str[i] == 'i' || str[i] == 'd')
		count = print_int(va_arg(args, int));
	if (str[i] == 'u')
		count = print_uint(va_arg(args, unsigned int));
	if (str[i] == 'x')
		count = print_hex_low(va_arg(args, unsigned int));
	if (str[i] == 'X')
		count = print_hex_cap(va_arg(args, unsigned int));
	if (str[i] == 'p')
		count = print_pointer(va_arg(args, void *));
	return (count);
}

int	iter_str(int *count, char const *str, va_list args, size_t *i)
{
	while (str[(*i)] != '\0' && str[(*i) + 1] != '\0')
	{
		if (str[(*i)] == '%' && str[(*i) + 1] == '%')
		{
			if (write(1, "%", 1) == -1)
				return (0);
			(*i)++;
			(*count)++;
		}
		else if (str[(*i)] == '%' && str[(*i) + 1] != '\0')
			(*count) += check_type(str, ++(*i), args);
		else if (str[(*i)] == '%' && str[(*i)] == '\0')
		{
			(*i)++;
			break ;
		}
		else
		{
			if (write(1, &str[(*i)], 1) == -1)
				return (0);
			(*count) += 1;
		}
		(*i)++;
	}
	return (1);
}

int	ft_printf(char const *str, ...)
{
	int		count;
	size_t	i;
	va_list	args;

	i = 0;
	count = 0;
	if (!str || str[0] == '\0')
		return (0);
	va_start(args, str);
	iter_str(&count, str, args, &i);
	if (str[i] != '\0' && str[i] != '%')
	{
		write(1, &str[i], 1);
		count++;
	}
	va_end(args);
	return (count);
}
