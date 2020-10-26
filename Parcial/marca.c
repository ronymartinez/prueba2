#include "marca.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "string.h"

int cargarMarca(char *nombreMarca, eMarca *marca, int tamMarca, int idMarca)
{
    int retorno = 1;
    for (int i = 0; i < tamMarca; i++)
    {
        if(marca[i].idMarca == idMarca)
        {
            strcpy(nombreMarca, marca[i].descripcion);
            retorno = 1;
        }
    }

    return retorno;
}

int listarMarcas(eMarca *marca, int tamMarca)
{
    int retorno = 1;
    printf("****************************************************\n");
    printf("                 LISTADO DE MARCAS                  \n");
    printf("****************************************************\n\n");

    printf("   ID   DESCRIPCION\n\n");
    for (int i=0; i < tamMarca; i++)
    {
        printf(" %4d    %10s\n", marca[i].idMarca, marca[i].descripcion);
        retorno = 0;
    }
    printf("\n\n");

    return retorno;
}
