#include "tipo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "string.h"

int cargarTipo (char *nombreTipo, eTipo *tipo, int tamTipo, int idTipo)
{
    int retorno = 1;

    for(int i = 0; i < tamTipo; i++)
    {
        if(tipo[i].idTipo == idTipo)
        {
            strcpy(nombreTipo, tipo[i].descripcion);
            retorno = 0;
        }
    }
    return retorno;
}

int listarTipos(eTipo *tipo, int tamTipo)
{
    int retorno = 1;
    printf("****************************************************\n");
    printf("                  LISTADO DE TIPOS                  \n");
    printf("****************************************************\n\n");
    printf("   ID   DESCRIPCION\n\n");

    for (int i=0; i < tamTipo; i++)
    {
        printf(" %4d    %10s\n", tipo[i].idTipo, tipo[i].descripcion);
        retorno = 0;
    }
    printf("\n\n");
    return retorno;
}

