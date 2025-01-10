/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <sluterea@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:02:37 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/07 15:02:37 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	char	str[] = "";
	void	*ptr = NULL;

	ft_printf("Comparacion\n");
	printf("\n Cuenta pf mult arg: %i\n",
		printf("Try i:%i s:%s u:%u %%", 100, "hola", -10));
	ft_printf("\n");
	printf("\n Cuenta ft mult arg: %i\n",
		ft_printf("Try i:%i s:%s u:%u %%", 100, "hola", -10));
	ft_printf("Comparacion\n");
	printf("\n cuenta ft: %i\n", ft_printf("%u", -10));
	ft_printf("\n");
	printf("\n cuenta pf: %i\n", printf("%u", -10));
	ft_printf("\n");
	printf("\n cuenta ft s+u: %i\n", ft_printf("Hola %u", -10));
	ft_printf("\n");
	printf("\n cuenta pf s+u: %i\n", printf("Hola %u", -10));
	ft_printf("Comparacion\n");
	printf("\n cuenta pf x-X: %i\n", printf("%x %s %X", -210, "y", -210));
	ft_printf("\n");
	printf("\n cuenta ft x-X: %i\n", ft_printf("%x %s %X", -210, "y", -210));
	ft_printf("Comparacion\n");
	printf("cuenta pf p: %i\n", printf("%p\n", (void *)42));
	ft_printf("\n");
	printf("cuenta ft p: %i\n", ft_printf("%p\n", (void *)42));
	ft_printf("Comparacion\n");
	ft_printf("cspdiuxX%");
	ft_printf("\n");
	//printf("cspdiuxX%");
	ft_printf("Comparacion\n");
	printf("cuenta ft s "": %i\n", ft_printf("%s", str));
	printf("\n");
	printf("cuenta pf s "": %i\n", printf("%s", str));
	ft_printf("\n");
	printf("cuenta pf "": %i\n", printf(""));
	printf("\n");
	printf("cuenta ft "": %i\n", ft_printf(""));
	ft_printf("\nComparacion\n");
	printf("cuenta ft p nulo: %i\n", ft_printf("%p\n", ptr));
	ft_printf("\n");
	printf("cuenta ft p nulo: %i\n", printf("%p\n", ptr));
	printf("\n");
	printf("cuenta ft mult arg: %i\n", ft_printf("H%su%ia", "cinco", 1));
	ft_printf("\n");
	printf("cuenta ft mult arg: %i\n", printf("H%su%ia", "cinco", 1));
	ft_printf("\n");
	/*arreglado
	printf("Categoria s\n");
	//printf("cuenta pf: %i\n", ft_printf("\n NULL %s NULL \n", NULL));
	printf("cuenta pf: %i\n", ft_printf(" NULL %s NULL ", NULL));
	printf("\n");
	//printf("cuenta pf: %i", printf(" NULL %s NULL ", NULL));
	*/
	/*arreglado
	printf("Categoria p\n");
	//ft_printf("cuenta pf: %i", printf(" %p %p ", LONG_MIN, LONG_MAX));
	//ft_printf("cuenta pf: %i", printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
	ft_printf("cuenta ft: %i", ft_printf(" %p %p ", LONG_MIN, LONG_MAX));
	printf("\n");
	ft_printf("cuenta ft: %i", ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
	*/
	/* arreglado
	printf("Categoria d/i/u/x/X\n");
	printf("cuenta ft: %i", ft_printf(" %d ", 0));
	printf("\n");
	printf("cuenta pf: %i", printf(" %d ", 0));
	printf("\n");
	printf("cuenta ft: %i", ft_printf(" %d ", LONG_MIN));
	printf("\n");
	printf("cuenta ft: %i", ft_printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("\n");
	//printf("cuenta ft: %i", printf(" %d ", LONG_MIN));
	//printf("cuenta ft: %i", printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	*/
	/* arreglado
	printf("Categoria %%\n");
	printf("cuenta ft: %i", ft_printf(" %% "));
	printf("\n");
	printf("cuenta ft: %i", ft_printf(" %%%% "));
	printf("\n");
	printf("cuenta ft: %i", ft_printf(" %% %% %% "));
	printf("\n");
	printf("cuenta ft: %i", ft_printf(" %%  %%  %% "));
	printf("\n");
	printf("cuenta ft: %i", ft_printf(" %%   %%   %% "));
	printf("\n");
	printf("cuenta ft: %i", ft_printf("%% %%"));
	printf("\n");
	printf("cuenta pf: %i", printf(" %% "));
	printf("\n");
	printf("cuenta pf: %i", printf(" %%%% "));
	printf("\n");
	printf("cuenta pf: %i", printf(" %% %% %% "));
	printf("\n");
	printf("cuenta pf: %i", printf(" %%  %%  %% "));
	printf("\n");
	printf("cuenta pf: %i", printf(" %%   %%   %% "));
	printf("\n");
	printf("cuenta pf: %i", printf("%% %%"));
	printf("\n");
	*/
	/* arreglado
	printf("Categoria mix\n");
	printf("cuenta ft: %i", ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
	printf("\n");
	printf("cuenta pf: %i", printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
	*/
	return (0);
}
