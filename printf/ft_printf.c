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

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

//puts 
int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1);
		return (-1);
	return (1);
	
}

int	ft_putstr(char *s)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
		i++;
	if(write(1, s, i) == -1)
		return (-1);
	return (i);
}

int	ft_numlen(int num, int len)
{
	while(num > 0)
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

int	ft_numlen_unsigned(unsigned int num, int len)
{
	while(num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	num;
	int			i;

	i = 0;
	num = n;
	i = ft_numlen_unsigned(num, i);
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (i);
}

int	ft_numlen_hex(unsigned int num, int len)
{
	while(num > 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

void	show_nbr(unsigned int nbr, char *base)
{
	unsigned int	num;

	num = nbr;
	if (num >= (unsigned int)16)
		show_nbr(num / 16, base);
	write(1, &base[num % 16], 1);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	count;

	count = 0;
	show_nbr(nbr, base);
	count = ft_numlen_hex(nbr, count);
	return (count);
}

int	ft_putpointer(void *ptr)
{
	unsigned char *p;

	p =  (unsigned char *)ptr;
	
}

// Defino cada tipo de argumento a imprimir
int	print_int(int arg)
{
	return (ft_putnbr(arg));
}

int	print_char(char arg)
{
	return (ft_putchar(arg));
}

int	print_str(char *arg)
{
	return (ft_putstr(arg));
}

int	print_uint(unsigned int arg)
{
	return (ft_putnbr_unsigned(arg));
}

int	print_hex_low(unsigned int arg)
{
	return (ft_putnbr_base(arg, "0123456789abcdef"));
}

int	print_hex_cap(unsigned int arg)
{
	return (ft_putnbr_base(arg, "0123456789ABCDEF"));
}

int	print_pointer(void *ptr)
{
	write(1, "0x", 2);
	return (ft_putnbr_base((unsigned long)ptr, "0123456789abcdef") + 2);
}
// check type (podria entregar i para checkear flags)
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

int	ft_printf(char const *str, ...)
{
	size_t	i;
	va_list	args;
	int 		count;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i] != '\0' && str[i+1] != '\0')
	{
		if (str[i] == '%' && str[i+1] == '%')
		{
			write(1, "%", 1);
			i++;
			count++;
		}
		else if (str[i] == '%' && str[i+1] != '\0')
		{
			count += check_type(str, ++i, args);
		}
		else if(str[i] == '%' && str[i] == '\0')
		{
			i++;
			break ;
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
		//if (str[i] == '\0')
		//	break ;
	}
	if (str[i] != '\0' && str[i] != '%')
	{
		write(1, &str[i], 1);
		count++;
	}
	//va_arg(args, type);
	va_end(args);
	return (count);
}


int main() {
    // Write C code here
	printf("\n num %i\n", ft_printf("Try i:%i s:%s u:%u %%", 100, "hola", -10));
	printf("\n numf %i\n", ft_printf("%u", -10));
	printf("\n num %i\n", printf("%u", -10));
	printf("\n num %i\n",printf("Hola%u", -10));
	printf("\n cuenta pf: %i\n",printf("%x %s %X", -210, "y", -210));
	printf("\n cuenta ft: %i\n", ft_printf("%x %s %X", -210, "y", -210));
	ft_printf("\n");
	printf("cuenta pf: %i\n", printf("%p\n", 42));
	printf("cuenta ft: %i\n", ft_printf("%p\n", 42));
	return 0;
}
