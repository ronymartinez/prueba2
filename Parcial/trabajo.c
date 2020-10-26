#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "trabajo.h"
#include "utn.h"

int inicializarTrabajos(eTrabajo *trabajos, int tamTrab)
{
    int retorno = 1;
    for (int i = 0; i < tamTrab; i++)
    {
        trabajos[i].libre = 0;
        retorno = 0;
    }
    return retorno;
}
void hardcodearTrabajos(eTrabajo *trabajos)
{
    eTrabajo aux1 = {1, 101, 20001, {10, 6,1990}, 1};
    eTrabajo aux2 = {2, 104, 20003, {11,11,2011}, 1};
    eTrabajo aux3 = {3, 103, 20001, { 7, 2,2019}, 1};
    eTrabajo aux4 = {4, 108, 20002, {11, 7,2004}, 1};
    eTrabajo aux5 = {5, 109, 20002, {22, 1,2005}, 1};
    eTrabajo aux6 = {6, 107, 20003, {30,12,2002}, 1};
    eTrabajo aux7 = {7, 102, 20001, {14, 3,1999}, 1};
    eTrabajo aux8 = {8, 101, 20002, {23,06,2010}, 1};
    eTrabajo aux9 = {9, 108, 20003, {20,11,2010}, 1};
    eTrabajo aux10= {10,105, 20001, {10, 6,1990}, 1};

    trabajos[0] = aux1;
    trabajos[1] = aux2;
    trabajos[2] = aux3;
    trabajos[3] = aux4;
    trabajos[4] = aux5;
    trabajos[5] = aux6;
    trabajos[6] = aux7;
    trabajos[7] = aux8;
    trabajos[8] = aux9;
    trabajos[9] = aux10;
}

int listarTrabajos(eTrabajo *trabajo, int tamTrab, eServicio *servicio, int tamSer)
{
    int retorno = 1;
    printf("****************************************************\n");
    printf("               LISTADO DE TRABAJOS                  \n");
    printf("****************************************************\n\n");
    printf("  ID        ID\n");
    printf("TRABAJO   NOTEBOOK       SERVICIO         FECHA\n");
    for(int i = 0; i < tamTrab; i++)
    {
        if(trabajo[i].libre == 1)
        {
            listarTrabajo(trabajo[i], servicio, tamSer);
            retorno = 0;
        }
    }
    if(retorno == 1)
    {
        printf("\n\nNo hay trabajos cargados.\n\n");
    }
    printf("\n\n\n");
    return retorno;
}

int listarTrabajo(eTrabajo trabajo, eServicio *servicio, int tamSer)
{
    int retorno = 1;
    char nombreServicio[20];

    cargarServicio(nombreServicio, servicio, tamSer, trabajo.idServicio);
    printf("\n%4d       %4d   %15s    %02d/%02d/%4d", trabajo.idTrabajo, trabajo.idNotebook, nombreServicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);

    return retorno;
}

int altaTrabajo(eTrabajo *trabajos, int tamTrab, eNotebook *notebook, int tam, eMarca *marca, int tamMarca, eTipo *tipo, int tamTipo, eServicio *servicio, int tamSer)
{
    int retorno = 1;
    int indiceLibre;
    int idServicio;
    int idNotebook;
    int nuevoID;
    int dia;
    int mes;
    int anio;

    indiceLibre = buscarTrabajoLibre(trabajos, tamTrab);

    nuevoID = indiceLibre + 1;

    eTrabajo aux;
    printf("****************************************************\n");
    printf("                    ALTA TRABAJO                    \n");
    listarNotebooks(notebook, tam, tipo, tamTipo, marca, tamMarca);

    if(utn_getNumero(&idNotebook, "Ingrese el ID de la notebook para agregar trabajo: ", "Error. Ha ingresado un dato invalido\n\n", 101, 999, 2) == 0)
      {
        if (buscarNotebookID(notebook, tam, idNotebook) != -1)
        {
        system("clear");
        printf("****************************************************\n");
        printf("                    ALTA TRABAJO                    \n");
        listarServicios(servicio, tamSer);
        if(utn_getNumero(&idServicio, "Ingrese el ID del servicio a realizar: ", "Error. Ha ingresado un dato invalido\n\n", 20001, 20004, 2) == 0)
        {
            system("clear");
            printf("****************************************************\n");
            printf("                    ALTA TRABAJO                    \n");
            printf("****************************************************\n");
            printf("                 FECHA DEL SERVICIO                 \n");
            printf("****************************************************\n\n\n");

            if (utn_getNumero(&dia, "Ingrese el DIA: ", "Error. Ingreso un dato invalido.\n\n", 1, 31, 2) == 0)
            {
                if (utn_getNumero(&mes, "Ingrese el MES: ", "Error. Ingreso un dato invalido.\n\n", 1, 12, 2) == 0)
                {
                    if (utn_getNumero(&anio, "Ingrese el ANIO: ", "Error. Ingreso un dato invalido.\n\n", 1990, 2030, 2) == 0)
                    {
                        aux.libre = 1;
                        aux.idTrabajo = nuevoID;
                        aux.idNotebook = idNotebook;
                        aux.idServicio = idServicio;
                        aux.fecha.dia = dia;
                        aux.fecha.mes = mes;
                        aux.fecha.anio = anio;

                        trabajos[indiceLibre] = aux;
                        retorno = 0;
                        printf("\n\nSe ha dado de alta un trabajo.\n\n");

                    }

                }

            }

        }

        }

      }
    if(retorno == 1)
    {
        printf("\n\nNo se pudo realizar el alta.\n\n");
    }
    return retorno;
}

int buscarTrabajoLibre (eTrabajo *trabajo, int tamTrab)
{
    int retorno = -1;

    for (int i = 0; i < tamTrab; i++)
    {
        if(trabajo[i].libre == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}












