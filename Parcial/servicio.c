#include "servicio.h"

int listarServicios(eServicio *servicio, int tamSer)
{
    int retorno = 1;

    printf("****************************************************\n");
    printf("               LISTADO DE SERVICIOS                  \n");
    printf("****************************************************\n\n");
    printf("    ID       DESCRIPCION      PRECIO\n\n");

    for(int i = 0; i < tamSer; i++)
    {
        printf(" %5d   %15s    %8.2f\n", servicio[i].idServicio, servicio[i].descripcion, servicio[i].precio);
        retorno = 0;
    }
    printf("\n\n");

    return retorno;
}
int cargarServicio(char *nombreServicio, eServicio *servicio, int tamSer, int idServicio)
{
    int retorno = 1;

    for (int i = 0; i < tamSer; i++)
    {
        if(servicio[i].idServicio == idServicio)
        {
            strcpy(nombreServicio, servicio[i].descripcion);
            retorno = 0;
        }
    }
    return retorno;
}


