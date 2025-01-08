#include "libft.h"

int main()
{
    char str[] = "ajo ave ale";
    char del = ' ';
    char **tab = ft_split(str, del);
    int i = 0;
    
    while (tab[i] != NULL)
    {
        printf("%s\n", tab[i]);  // Añadí \n para mejor visualización
        i++;
    }
    
    // Liberar cada string individual
    i = 0;
    while (tab[i] != NULL)
    {
        free(tab[i]);
        i++;
    }
    // Luego liberar el array de punteros
    free(tab);
    
    return 0;
}
