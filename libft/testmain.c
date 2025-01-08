/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-la <matde-la@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:18:17 by matde-la          #+#    #+#             */
/*   Updated: 2025/01/02 12:17:45 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// gcc -o testmain testmain.c libft.a -lbsd

#include "libft.h"
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <bsd/string.h>
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>

void test_ft_isalnum() 
{
    char input[4];
    int c;

    printf("Ingresa un caracter: ");
    scanf("%4s", input);
    if (input[2]) {
        printf("Entrada invalida");
        return;
    }
    c = input[0];
    if (ft_isalnum(c)) {
        printf("Entrada es alfanumérica: '%c'\n", c);
    } else {
        printf("Entrada no válida.\n");
    }
    if (c >= 32 && c <= 126) {
        printf("Caracter (ASCII): '%c'\n", c);
    } else {
        printf("El valor ingresado no corresponde a un carácter imprimible.\n");
    }
    printf("Resultado ft_isalnum('%c'): %d\n", c, ft_isalnum(c));
    printf("Resultado isalnum('%c'): %d\n", c, isalnum(c));
}

void	test_ft_isalpha()
{
	char	input[4];
	int	c;

	printf("Ingresa un caracter: ");
	scanf("%4s", input);
	if (input[2])
		printf("Entrada invalida");
	c = input[0];
	if (ft_isalpha(c))
		printf("Entrada es letra: '%c'\n", c);
	else
		printf("Entrada no valida.\n");
	if (c >=  32 && c <= 126)
		printf("Caracter (ASCII): '%c'\n", c);
	else
		printf("El valor ingresado no corresponde a un caracer imprimible.\n");
	printf("Resultado ft_isalpha('%c'): %d\n", c, ft_isalpha(c));
	printf("Resultado isalpha('%c'): %d\n", c, isalpha(c));
}

void	test_ft_isascii()
{
	char	input[4];
	int	c;

	printf("Ingresa un caracter: ");
	scanf("%4s", input);
	c = input[0];
	if (input[2])
		printf("Entrada no valida.\n");
	printf("Caracter (ASCII): '%c'\n", c);
	printf("Resultado ft_isascii('%c'): %d\n", c, ft_isascii(c));
	printf("Resultado isascii('%c'): %d\n", c, isascii(c));
}

void	test_ft_isdigit()
{
	char	input[4];
	int	c;

	printf("Ingresa un caracter: ");
	scanf("%4s", input);
	if (input[1])
		printf("Entrada no valida\n");
	c = input[0];
	printf("Resultado ft_isdigit(%d): %d\n", c, ft_isdigit(c));
	printf("Resultado isdigit(%d): %d\n", c, isdigit(c));
}

void	test_ft_isprint()
{
	char	input[4];
	int	c;

	printf("Ingresa un caracter: ");
	scanf("%4s", input);
	if (input[1])
		printf("Entrada no valida\n");
	c = input[0];
	printf("Resultado ft_isprint(%d): %d\n", c, ft_isprint(c));
	printf("Resultado isprint(%d): %d\n", c, isprint(c));
}

void	test_ft_strlcpy()
{
	char		dst[20];
	char		dst2[20];
	const char	*src;
	size_t		size;

	src = "Bienvenidos";
	size = 5;
	size_t	res1 = ft_strlcpy(dst, src, size);
	printf("\n");
	printf("ft_strlcpy:\n");
	printf("Copiando '%s'  a dst con size %zu:\n", src, size);
	printf("Resultado ft_strlcpy: %zu, dst: '%s'\n\n", res1, dst);
	size_t	res2 = strlcpy(dst2, src, size);
	printf("strlcpy:\n");
	printf("Copiando '%s'  a dst con size %zu:\n", src, size);
	printf("Resultado strlcpy: %zu, dst2: '%s'\n\n", res2, dst2);
}

void	test_ft_strlen()
{
	const char	*s;

	s = "Bienvenidos";
	size_t	res1 = ft_strlen(s);
	printf("\n");
	printf("ft_strlen:\n");
	printf("Resultado ft_strlen: %zu\n\n", res1);
	size_t	res2 = strlen(s);
	printf("strlen:\n");
	printf("Resultado strlen: %zu\n\n", res2);
	
}

void	test_ft_strlcat()
{
	char		dst[20];
	char		dst2[20];
	const char	*src;
	size_t		size;

	ft_strlcpy(dst, "Bien", 5);
	ft_strlcpy(dst2, "Bien",5);
	src = "venidos";
	size = 8;
	size_t res1 = ft_strlcat(dst, src, size);
	printf("\n");
	printf("ft_strlcat:\n");
	printf("Resultado ft_strlcat: %zu, dst: '%s'\n\n", res1, dst);
	size_t res2 = strlcat(dst2, src, size);
	printf("\n");
	printf("strlcat:\n");
	printf("Resultado strlcat: %zu, dst2: '%s'\n\n", res2, dst2);
}

void	test_ft_strchr()
{
	const char	*str;
	int		c;

	str = "Bienvenidos";
	c = 'v';
	char *res1 = ft_strchr(str, c);
	printf("\n");
	printf("ft_strchr:\n");
	printf("Resultado ft_strchr: %s.\n\n", res1);
	printf("Resultado ft_strchr: %p.\n\n", res1);
	char *res2 = strchr(str, c);
	printf("\n");
	printf("ft_strchr:\n");
	printf("Resultado strchr: %s.\n\n", res2);
	printf("Resultado strchr: %p.\n\n", res2);
}

void	test_ft_strrchr()
{
	const char	*str;
	int		c;

	str = "Bienvenidos";
	c = 'e';
	char *res1 = ft_strrchr(str, c);
	printf("\n");
	printf("ft_strrchr:\n");
	printf("Resultado ft_strrchr: %s.\n\n", res1);
	printf("Resultado ft_strrchr: %p.\n\n", res1);
	char *res2 = strrchr(str, c);
	printf("\n");
	printf("ft_strrchr:\n");
	printf("Resultado strrchr: %s.\n\n", res2);
	printf("Resultado strrchr: %p.\n\n", res2);
}
void	test_ft_strncmp()
{
	const char	*str;
	const char	*str2;
	size_t		c;

	str = "test";
	str2 = "testss";
	c = 7;
	ft_strncmp(str, str2, c);
	printf("\n");
	printf("Resultado ft_strncmp: %d.\n\n", ft_strncmp(str, str2, c));
	printf("\n");
	printf("Resultado strncmp: %d.\n\n", strncmp(str, str2, c));
}

void	test_ft_strnstr()
{
	const char *big;
	const char *little;
	size_t	len;

	big = "Bienvenidos";
	little = "B";
	len = 6;
	char *res = ft_strnstr(big, little, len);
	printf("\n");
	if (res)
	{
		size_t chars_to_print = len - (res - big);
		printf("Resultado ft_strnstr: %.*s\n", (int)chars_to_print, res);
	}
	else
		printf("Resultado ft_strnstr: NULL\n");
	char *res2 = strnstr(big, little, len);
	printf("\n");
	if (res2)
	{
		size_t chars_to_print = len - (res2 - big);
		printf("Resultado strnstr: %.*s\n", (int)chars_to_print, res2);
	}
	else
			printf("Resultado strnstr: NULL\n");
}

void	test_ft_toupper()
{
	int	c;
	c = 'a';
	printf("Argumento 1: %c\n", c);
	printf("Resultado ft_toupper(%c): %c\n", c, ft_toupper(c));
	printf("Resultado toupper(%c): %c\n", c, toupper(c));
	c = 'A';
	printf("Argumento 3: %c\n", c);
	printf("Resultado ft_toupper(%c): %c\n", c, ft_toupper(c));
	printf("Resultado toupper(%c): %c\n", c, toupper(c));
	c = 0;
	printf("Argumento 2: %c\n", c);
	printf("Resultado ft_toupper(%c): %c\n", c, ft_toupper(c));
	printf("Resultado toupper(%c): %c\n", c, toupper(c));
}
void	test_ft_tolower()
{
	int	c;
	c = 'a';
	printf("Argumento 1: %c\n", c);
	printf("Resultado ft_tolower(%c): %c\n", c, ft_tolower(c));
	printf("Resultado tolower(%c): %c\n", c, tolower(c));
	c = 'A';
	printf("Argumento 3: %c\n", c);
	printf("Resultado ft_tolower(%c): %c\n", c, ft_tolower(c));
	printf("Resultado tolower(%c): %c\n", c, tolower(c));
	c = 0;
	printf("Argumento 2: %c\n", c);
	printf("Resultado ft_tolower(%c): %c\n", c, ft_tolower(c));
	printf("Resultado tolower(%c): %c\n", c, tolower(c));
}

void	test_ft_memchr()
{
	const void *str;
	int	c;
	size_t	n;

	str = "Bienvenidos";
	c = 'v';
	n = 16;

	printf("Resultado ft_memchr: %p\n\n", ft_memchr(str, c, n));
	printf("Reultado memchr: %p\n", memchr(str, c, n));
}

void	test_ft_memcmp()
{	
	const void *str;
	const void *str2;
	size_t	n;

	str = "Bienvenidos";
	str2 = "Bienvenios";
	n = 16;
	printf("Resultado ft_memcmp: %d\n\n", ft_memcmp(str, str2, n));
	printf("Reultado memcmp: %d\n", memcmp(str, str2, n));

}

void	test_ft_memcpy()
{
	unsigned char		dst[20];
	unsigned char		dst2[20];
	const char	*str;
	size_t		n;

	str = "Bienvenidos";
	n = 4;
	void	*res1 = ft_memcpy(dst, str, n);
	printf("\n");
	printf("ft_memcpy:\n");
	printf("Copiando '%s'  a dst con size %zu:\n", str, n);
	printf("Resultado ft_memcpy: %p, dst: '%s'\n\n", res1, dst);
	void	*res2 = memcpy(dst2, str, n);
	printf("memcpy:\n");
	printf("Copiando '%s'  a dst con size %zu:\n", str, n);
	printf("Resultado memcpy: %p, dst2: '%s'\n\n", res2, dst2);
}

void	test_ft_memmove()
{
	unsigned char		dst[20];
	unsigned char		dst2[20];
	const char	*str;
	size_t		n;

	str = "Bienvenidos";
	n = 13;
	void	*res1 = ft_memmove(dst, str, n);
	printf("\n");
	printf("ft_memmove:\n");
	printf("Copiando '%s'  a dst con size %zu:\n", str, n);
	printf("Resultado ft_memmove: %p, dst: '%s'\n\n", res1, dst);
	void	*res2 = memmove(dst2, str, n);
	printf("memcpy:\n");
	printf("Copiando '%s'  a dst con size %zu:\n", str, n);
	printf("Resultado memmove: %p, dst2: '%s'\n\n", res2, dst2);

}

void	test_ft_memset()
{
	unsigned char		dst[20];
	unsigned char		dst2[20];
	int			c;
	size_t			n;

	c = 'A';
	n = 6;
	void	*res1 = ft_memset(dst, c, n);
	printf("\n");
	printf("ft_memset:\n");
	printf("LLenando dst con el caracter '%c' (ASCII %d) hasta %zu bytes:\n", c, c, n);
	printf("Resultado ft_memset: %p\n", res1);
	printf("%.*s\n", (int)n, dst);
	void	*res2 = memset(dst2, c, n);
	printf("memset:\n");
	printf("LLenando dst2 con el caracter '%c' (ASCII %d) hasta %zu bytes:\n", c, c, n);
	printf("Resultado memset: %p\n", res2);
	printf("%.*s\n", (int)n, dst2);
}

void	test_ft_bzero()
{
	unsigned char		dst[20];
	unsigned char		dst2[20];
	size_t			n;

	n = 6;
	ft_bzero(dst, n);
	printf("\n");
	printf("ft_bzero:\n");
	printf("Estableciendo en cero dst hasta %zu bytes:\n", n);
	printf("dst: %.*s.\n\n", (int)n, dst);
	bzero(dst2, n);
	printf("bzero:\n");
	printf("Estableciendo en cero dst2 hasta %zu bytes:\n", n);
	printf("dst2: %.*s.\n", (int)n, dst2);
}


void	test_ft_atoi()
{
	char str[12];
		

	printf("Ingresa un numero:");
	scanf("%13s", str);
	printf("\n");
	printf("ft_atoi:%d\n", ft_atoi(str));
	printf("atoi   :%d\n", atoi(str));
}

void	test_ft_calloc()
{
	size_t num_elements;
	size_t element_size;
	void *ft_mem;
	void *real_mem;

	printf("Esta función probará ft_calloc y calloc.\n");
	printf("Ingresa el número de elementos: ");
	scanf("%zu", &num_elements);
	printf("Ingresa el tamaño de cada elemento: ");
	scanf("%zu", &element_size);
	ft_mem = ft_calloc(num_elements, element_size);
	if (!ft_mem)
	{
		printf("Error al asignar memoria con ft_calloc\n");
		return;
	}
	real_mem = calloc(num_elements, element_size);
	if (!real_mem)
	{
		printf("Error al asignar memoria con calloc\n");
		free(ft_mem);
	}
	if (ft_memcmp(ft_mem, real_mem, num_elements * element_size) == 0)
		printf("ft_calloc y calloc asignan memoria de manera similar.\n");
	else
        	printf("ft_calloc y calloc asignan memoria de manera diferente.\n");
	free(ft_mem);
	free(real_mem);
}

void	test_ft_strdup()
{
	const char 	*s;
	char		buffer[1024];
	char 		*copia;
	char		*copia2;
	int		len;
	char		*lastn;
	
	printf("Ingrese una frase:\n");
	fgets(buffer, 1024, stdin);
	lastn = ft_strrchr(buffer, '\n');
	if (lastn)
		*lastn = '\0';
	len = ft_strlen(buffer);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
	{
		printf("Error al asignar memeria");
		free((char *)s);
		return;
	}
	ft_strlcpy((char *)s, buffer, len);
	copia = ft_strdup(s);
	copia2 = strdup(s);
	printf("Frase original: %s\n", s);
	printf("Copia con ft_strdup: %s\n", copia);
	printf("Copia con strdup: %s\n\n", copia);
	((char *)s)[0] = 'X';
	printf("Modifica primera letra del original por X\n");
	printf("Original: %s\n", s);
	printf("Copia con ft_strdup: %s\n", copia);
	printf("Copia con strdup: %s\n\n", copia);
	free((char *)s);
	free(copia);
	free(copia2);
}

void	test_ft_substr()
{
	const char	*s;
	char		buffer[1024];
	unsigned int	start;
	size_t		len;
	char		*lastn;
	char		*res;

	printf("Ingresa una frase:\n");
	fgets(buffer, 1024, stdin);
	lastn = ft_strrchr(buffer, '\n');
	if (lastn)
		*lastn = '\0';
	len = ft_strlen(buffer);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
	{
		printf("Error al asignar memoria");
		free((char *)s);
		return;
	}
	ft_strlcpy((char *)s, buffer, len);
	printf("Ingresa inicio de copia:");
	scanf("%u", &start);
	printf("Ingresa largo a copiar:\n");
	scanf("%zu", &len);
	res = ft_substr(s, start, len);
	printf("Nueva frase: %s\n", res);
	free((char *)s);
	free((char *)res);
}

void	test_ft_strjoin()
{	char		buffer[1024];
	char		buffer2[1024];
	char	 	*s1;
	char		*s2;
	char		*res;
	char		*lastn;	

	printf("Ingresa una frase o palabra:");
	fgets(buffer, 1024, stdin);
	lastn = ft_strrchr(buffer, '\n');
	if (lastn)
		*lastn = '\0';
	printf("Ingresa una frase o palabra para concatenar con la anterior:");
	fgets(buffer2, 1024, stdin);
	lastn = ft_strrchr(buffer2, '\n');
	if (lastn)
		*lastn = '\0';
	s1 = (char *)malloc((ft_strlen(buffer) + 1) * sizeof(char));
	if (!s1)
	{
		printf("Error al asignar memoria");
		return;
	}
	s2 = (char *)malloc((ft_strlen(buffer2) + 1) * sizeof(char));
	if (!s2)
	{
		printf("Error al asignar memoria");
		return;
	}
	ft_strlcpy(s1, buffer, ft_strlen(buffer) + 1);
	ft_strlcpy(s2, buffer2, ft_strlen(buffer2) + 1);
	printf("%s\n", s1);
	printf("%s\n", s2);
	res = ft_strjoin(s1, s2);
	printf("Nueva frase: %s\n", res);
	free(s1);
	free(s2);
	free(res);
}

void	test_ft_strtrim()
{
	char		buffer[1024];
	char		buffer2[1024];
	char	 	*s1;
	char		*set;
	char		*res;
	char		*lastn;	

	printf("Considera que la funcion ft_strtrim eliminara de la frase los caracteres\n");
	printf("de al principio y al final.\n");
	printf("Ingresa una frase o palabra:");
	fgets(buffer, 1024, stdin);
	lastn = ft_strrchr(buffer, '\n');
	if (lastn)
		*lastn = '\0';
	printf("Ingresa caracteres a eliminar: ");
	fgets(buffer2, 1024, stdin);
	lastn = ft_strrchr(buffer2, '\n');
	if (lastn)
		*lastn = '\0';
	s1 = (char *)malloc((ft_strlen(buffer) + 1) * sizeof(char));
	if (!s1)
	{
		printf("Error al asignar memoria");
		return;
	}
	set = (char *)malloc((ft_strlen(buffer2) + 1) * sizeof(char));
	if (!set)
	{
		printf("Error al asignar memoria");
		return;
	}
	ft_strlcpy(s1, buffer, ft_strlen(buffer) + 1);
	ft_strlcpy(set, buffer2, ft_strlen(buffer2) + 1);
	printf("Frase >> %s\n", s1);
	printf("Caracteres a elminar >> %s\n", set);
	res = ft_strtrim(s1, set);
	printf("Nueva frase: %s\n", res);
	free(s1);
	free(set);
	free(res);
}

void	to_upper(unsigned int i, char *c)
{
	*c = ft_toupper(*c);
}

char	to_lower(unsigned int i, char c)
{
    return (ft_tolower(c));
}

void	test_ft_putchar_fd()
{
	char	buffer[1024];
	char	*lastn;
	int	fd;

	printf("Esta función escribirá un carácter en un archivo.\n");
	printf("Ingresa un carácter: ");
	fgets(buffer, 1024, stdin);
	lastn = strrchr(buffer, '\n');
	if (lastn)
		*lastn = '\0';
	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		printf("Error al abrir el archivo\n");
		return;
	}
	ft_putchar_fd(buffer[0], fd);
	close(fd);
	printf("El carácter '%c' ha sido escrito en el archivo 'output.txt'.\n", buffer[0]);
}

void	test_ft_putstr_fd()
{
	char	buffer[1024];
	char	*lastn;
	int	fd;

	printf("Esta función escribirá una cadena en un archivo.\n");
	printf("Ingresa una palabra o frase: ");
	fgets(buffer, 1024, stdin);
	lastn = strrchr(buffer, '\n');
	if (lastn)
		*lastn = '\0';
	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		printf("Error al abrir el archivo\n");
		return;
	}
	ft_putstr_fd(buffer, fd);
	close(fd);
	printf("La cadena '%s' ha sido escrita en el archivo 'output.txt'.\n", buffer);
}

void	test_ft_putendl_fd()
{
	char	buffer[1024];
	char	*lastn;
	int	fd;

	printf("Esta función escribirá una cadena seguida de un salto de línea en un archivo.\n");
	printf("Ingresa una palabra o frase: ");
	fgets(buffer, 1024, stdin);
	lastn = strrchr(buffer, '\n');
	if (lastn)
	*lastn = '\0';
	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		printf("Error al abrir el archivo\n");
		return;
	}
	ft_putendl_fd(buffer, fd);
	close(fd);
	printf("La cadena '%s' seguida de un salto de línea ha sido escrita en el archivo 'output.txt'.\n", buffer);
}

void	test_ft_putnbr_fd()
{
	char	buffer[1024];
	int	number;
	int	fd;

	printf("Esta función escribirá un número en un archivo.\n");
	printf("Ingresa un número: ");
	fgets(buffer, 1024, stdin);
	number = ft_atoi(buffer);
	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
	printf("Error al abrir el archivo\n");
	return;
	}
	ft_putnbr_fd(number, fd);
	close(fd);
	printf("El número '%d' ha sido escrito en el archivo 'output.txt'.\n", number);
}
void	test_ft_strmapi()
{
	char buffer[1024];
	char *s;
	char *res;
	char *lastn;

	printf("Esta función aplicará una transformación a cada carácter de la cadena.\n");
	printf("Ingresa una palabra o frase: ");
	fgets(buffer, 1024, stdin);
	lastn = strrchr(buffer, '\n');
	if (lastn)
		*lastn = '\0';
	s = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
	if (!s)
	{
		printf("Error al asignar memoria\n");
		return;
	}
	ft_strlcpy(s, buffer, ft_strlen(buffer) + 1);
	res = ft_strmapi(s, to_lower);
	if (!res)
	{
		printf("Error al asignar memoria para el resultado\n");
 		free(s);
		return;
	}
	printf("Se usa la función ft_tolower como ejemplo\n");
	printf("Resultado con ft_strmapi(): %s\n", res);
	free(s);
	free(res);
}

void	test_ft_striteri()
{
	char		buffer[1024];
	char		*s;
	char		*lastn;

	printf("Esta función aplicará una transformación a cada carácter de la cadena.\n");
	printf("Ingresa una palabra o frase: ");
	fgets(buffer, 1024, stdin);
	lastn = strrchr(buffer, '\n');
	if (lastn)
		*lastn = '\0';
	s = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
	if (!s)
	{
		printf("Error al asignar memoria\n");
		return;
	}
	strcpy(s, buffer);
	ft_striteri(s, to_upper);
	printf("Se usa la funcion ft_toupper como ejemplo");
	printf("Resultado con ft_striteri(): %s\n", s);
	free(s);
}

void	test_ft_split()
{
	char 	buffer[200];
	char	*s;
	char	c;
	int	i;
	int	len;
	char	*lastn;

	printf("Escribe una frase:");
	fgets(buffer, 200, stdin);
	lastn = ft_strrchr(buffer, '\n');
	if (lastn)
		*lastn = '\0';
	len = ft_strlen(buffer);	
	s = malloc((len + 1) * sizeof(char));
	if (!s)
	{
		printf("Error al asignar memoria\n");
		free((char *)s);
		return ;
	}
	ft_strlcpy(s, buffer, len+1);
	printf("Entrega el delimitador:");
	scanf(" %c", &c);
	printf("\n");
	char **res = ft_split(s, c);
	printf("Resultado:\n");
	i = 0;
	if (res)
	{
		while (res[i] != NULL)
		{
			printf("%s\n", res[i]);
			free(res[i]);
			i++;
		}	
	}
	free(s);
}

void test_ft_itoa() 
{
    char buffer[200];
    int num;
    char *lastn;

    printf("Escribe un número: ");
    fgets(buffer, 200, stdin);
    lastn = ft_strrchr(buffer, '\n');
    if (lastn) 
        *lastn = '\0';
    if (sscanf(buffer, "%d", &num) != 1) 
    {
        printf("Entrada no válida.\n");
        return;
    }
    char *res = ft_itoa(num);
    printf("Variable: %d\n", num);
    printf("ft_itoa : %s\n", res);
    free(res);
}

void test_ft_lstnew()
{
	    // Crear un contenido de ejemplo
	    char *content = "Hola, Mundo!";
	    
	    // Crear el nodo con ft_lstnew
	    t_list *node = ft_lstnew(content);
	    
	    // Comprobar que el nodo no es NULL
	    if (node == NULL)
	    {
		printf("Error: El nodo es NULL\n");
		return;
	    }
	    
	    // Comprobar que el contenido del nodo es correcto
	    if (node->content == content)
	    {
		printf("El contenido del nodo es correcto: %s\n", (char *)node->content);
	    }
	    else
	    {
		printf("Error: El contenido del nodo es incorrecto\n");
	    }
	    
	    // Comprobar que el puntero next está a NULL, ya que es un nuevo nodo
	    if (node->next == NULL)
	    {
		printf("El puntero next está correctamente a NULL\n");
	    }
	    else
	    {
		printf("Error: El puntero next no está a NULL\n");
	    }
	    
	    // Liberar la memoria del nodo después de la prueba
	    free(node);
}

void make_uppercase(void *content)
{
   char *str = (char *)content;
   while (*str)
   {
       if (*str >= 'a' && *str <= 'z')
           *str = *str - 32;
       str++;
   }
}

void *uppercase_str(void *content)
{
    char *str = strdup((char *)content);  // Create new string
    char *ptr = str;
    
    while (*ptr)
    {
        if (*ptr >= 'a' && *ptr <= 'z')
            *ptr -= 32;
        ptr++;
    }
    return (str);
}

void del_content(void *content)
{
   if (content != NULL)
    {
        free(content);  // Libera la memoria asociada al contenido
    }
}

void test_ft_lstclear()
{
   t_list *lst = NULL;
   t_list *new;
   int *num;

   // Create list nodes with dynamic integers
   for (int i = 0; i < 5; i++)
   {
       new = malloc(sizeof(t_list));
       num = malloc(sizeof(int));
       *num = i;
       new->content = num;
       new->next = lst;
       lst = new;
   }

   // Print original list
   printf("Original list:\n");
   t_list *current = lst;
   while (current)
   {
       printf("%d -> ", *(int*)current->content);
       current = current->next;
   }
   printf("NULL\n");

   // Clear list
   ft_lstclear(&lst, del_content);

   // Verify list is cleared
   printf("After clear: %s\n", lst == NULL ? "List is empty" : "List is not empty");
}

void test_ft_lstiter()
{
   t_list *lst = NULL;
   t_list *new;

   // Create list with strings
   char *strs[] = {"hello", "world", "test", NULL};
   for (int i = 0; strs[i]; i++)
   {
       new = malloc(sizeof(t_list));
       new->content = strdup(strs[i]);
       new->next = lst;
       lst = new;
   }

   // Print original
   printf("Original:\n");
   for (t_list *tmp = lst; tmp; tmp = tmp->next)
       printf("%s -> ", (char *)tmp->content);
   printf("NULL\n");

   // Apply uppercase function
   ft_lstiter(lst, make_uppercase);

   // Print result
   printf("After uppercase:\n");
   for (t_list *tmp = lst; tmp; tmp = tmp->next)
       printf("%s -> ", (char *)tmp->content);
   printf("NULL\n");

}

void test_ft_lstmap()
{
    t_list *lst = NULL;
    t_list *new;
    
    // Create original list
    char *strs[] = {"hello", "world", "test", NULL};
    for (int i = 0; strs[i]; i++)
    {
        new = malloc(sizeof(t_list));
        new->content = strdup(strs[i]);
        new->next = lst;
        lst = new;
    }
    
    // Print original
    printf("Original list:\n");
    for (t_list *tmp = lst; tmp; tmp = tmp->next)
        printf("%s -> ", (char *)tmp->content);
    printf("NULL\n");
    
    // Map to new list
    t_list *mapped = ft_lstmap(lst, uppercase_str, del_content);
    
    // Print mapped list
    printf("Mapped list:\n");
    for (t_list *tmp = mapped; tmp; tmp = tmp->next)
        printf("%s -> ", (char *)tmp->content);
    printf("NULL\n");
    
    // Clean up
    ft_lstclear(&lst, del_content);
    ft_lstclear(&mapped, del_content);
    

}

void test_ft_lstdelone()
{
    t_list *list;
    t_list *new_node;
    t_list *first_node;
    int *value1 = malloc(sizeof(int));  // Asignamos memoria dinámica
    int *value2 = malloc(sizeof(int));  // Asignamos memoria dinámica

    if (value1 == NULL || value2 == NULL)
    {
        printf("Failed to allocate memory.\n");
        return ;
    }

    *value1 = 42;
    *value2 = 24;

    list = NULL; // Start with an empty list

    first_node = ft_lstnew(value1);  // Pasamos la memoria dinámica
    if (first_node == NULL)
    {
        printf("Failed to create new node.\n");
        return ;
    }
    ft_lstadd_front(&list, first_node); // Add the first node to the list

    printf("contenido nodo: %d\n", *(int *)list->content);
    
    ft_lstdelone(first_node, del_content);

}
	
int main(int argc, char *argv[]) 
{
	if (argc > 2)
	{
		printf("Too arguments");
		return (1);
	}
	if (argc == 1)
	{
		printf("Falta el nombre de la funcion (ej. ft_split)");
		return 0;
	}
	if(strcmp(argv[1], "ft_lstnew") == 0)
	{
		test_ft_lstnew();
			return(0);
	}
	if(strcmp(argv[1], "ft_lstclear") == 0)
	{
		test_ft_lstclear();
			return(0);
	}
	if(strcmp(argv[1], "ft_lstiter") == 0)
	{
		test_ft_lstiter();
			return(0);
	}
	if(strcmp(argv[1], "ft_lstmap") == 0)
	{
		test_ft_lstmap();
			return(0);
	}
	if(strcmp(argv[1], "ft_lstdelone") == 0)
	{
		test_ft_lstdelone();
			return(0);
	}
	if(strcmp(argv[1], "ft_isalnum") == 0)
	{
		test_ft_isalnum();
			return(0);
	}
	else if (strcmp(argv[1], "ft_isalpha") == 0)
	{	
		test_ft_isalpha();
			return(0);
	}
	else if (strcmp(argv[1], "ft_isascii") == 0)
	{
		test_ft_isascii();
			return(0);
	}
	else if (strcmp(argv[1], "ft_isdigit") == 0)
	{
		test_ft_isdigit();
			return(0);
	}
	else if (strcmp(argv[1], "ft_isprint") == 0)
	{
		test_ft_isprint();
			return(0);
	}
	else if (strcmp(argv[1], "ft_strlcpy") == 0)
	{
		test_ft_strlcpy();
			return(0);
	}
	else if (strcmp(argv[1], "ft_strlen") == 0)
	{
		test_ft_strlen();
		return(0);
	}
	else if (strcmp(argv[1], "ft_strlcat") == 0)
	{
		test_ft_strlcat();
		return(0);
	}
	else if (strcmp(argv[1], "ft_strchr") == 0)
	{
		test_ft_strchr();
		return(0);
	}
	else if (strcmp(argv[1], "ft_strrchr") == 0)
	{
		test_ft_strrchr();
		return(0);
	}
	else if (strcmp(argv[1], "ft_strncmp") == 0)
	{
		test_ft_strncmp();
		return(0);
	}
	else if (strcmp(argv[1], "ft_strnstr") == 0)
	{
		test_ft_strnstr();
		return(0);
	}
	else if (strcmp(argv[1], "ft_toupper") == 0)
	{
		test_ft_toupper();
		return(0);
	}
	else if (strcmp(argv[1], "ft_tolower") == 0)
	{
		test_ft_tolower();
		return(0);
	}
	else if (strcmp(argv[1], "ft_memchr") == 0)
	{
		test_ft_memchr();
		return(0);
	}
	else if (strcmp(argv[1], "ft_memcmp") == 0)
	{
		test_ft_memcmp();
		return(0);
	}
	else if (strcmp(argv[1], "ft_memcpy") == 0)
	{
		test_ft_memcpy();
		return(0);
	}
	else if (strcmp(argv[1], "ft_memmove") == 0)
	{
		test_ft_memmove();
		return(0);
	}
	else if (strcmp(argv[1], "ft_memset") == 0)
	{
		test_ft_memset();
		return(0);
	}
	else if (strcmp(argv[1], "ft_bzero") == 0)
	{
		test_ft_bzero();
		return(0);
	}
	else if (strcmp(argv[1], "ft_atoi") == 0)
	{
		test_ft_atoi();
		return(0);
	}
	else if (strcmp(argv[1], "ft_calloc") == 0)
	{
		test_ft_calloc();
		return(0);
	}
	else if (strcmp(argv[1], "ft_strdup") == 0)
	{
		test_ft_strdup();
		return(0);
	}
	else if (strcmp(argv[1], "ft_substr") == 0)
	{
		test_ft_substr();
		return(0);
	}
	else if (strcmp(argv[1], "ft_strjoin") == 0)
	{
		test_ft_strjoin();
		return(0);
	}
	else if (strcmp(argv[1], "ft_strtrim") == 0)
	{
		test_ft_strtrim();
		return(0);
	}	
	else if (strcmp(argv[1], "ft_putchar_fd") == 0)
	{
		test_ft_putchar_fd();
		return(0);
	}
	else if (strcmp(argv[1], "ft_putstr_fd") == 0)
	{
		test_ft_putstr_fd();
		return(0);
	}
	else if (strcmp(argv[1], "ft_putendl_fd") == 0)
	{
		test_ft_putendl_fd();
		return(0);
	}
	else if (strcmp(argv[1], "ft_putnbr_fd") == 0)
	{
		test_ft_putnbr_fd();
		return(0);
	}
	else if (strcmp(argv[1], "ft_strmapi") == 0)
	{
		test_ft_strmapi();
		return(0);
	}
	else if (strcmp(argv[1], "ft_striteri") == 0)
	{
		test_ft_striteri();
		return(0);
	}
	else if (strcmp(argv[1], "ft_split") == 0)
	{
		test_ft_split();
		return(0);
	}
	else if (strcmp(argv[1], "ft_itoa") == 0)
	{
		test_ft_itoa();
		return(0);
	}
	else
		printf("Funcion '%s' no reconocida.\n",argv[1]);
	return (0);
}
