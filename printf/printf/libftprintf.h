/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <sluterea@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:04:10 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/07 16:04:14 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	check_type(const char *str, size_t i, va_list args);
int	ft_printf(char const *str, ...);
int	print_char(char arg);
int	print_str(char *arg);
int	print_hex_cap(unsigned int arg);
int	print_uint(unsigned int arg);
int	print_int(int arg);
int	print_hex_low(unsigned int arg);
int	print_pointer(void *ptr);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putnbr_pointer(unsigned long long nbr, char *base);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putstr(char *s);

#endif 
