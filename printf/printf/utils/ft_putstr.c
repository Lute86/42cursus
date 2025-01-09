/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <sluterea@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:08:57 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/07 16:08:57 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_putstr(char *s)
{
	size_t	i;

	if (!s && write(1, "(null)", 6))
		return (6);
	i = 0;
	while (s[i] != '\0')
		i++;
	if (write(1, s, i) == -1)
		return (0);
	return (i);
}
