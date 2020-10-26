#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "utn.h"
#include "string.h"
#include "notebook.h"

int inicializarNotebooks(eNotebook *notebook, int tam)
{
    int retorno = 1;
    for (int i = 0; i < tam; i++)
    {
        notebook[i].libre = 0;
        retorno = 0;
    }

    return retorno;
}

void hardcodearNotebooks(eNotebook *notebook)
{    printf("****************************************************\n");
    printf("              LISTADO DE NOTEBOOKS                  \n");
    printf("           (Ordenado por Marca y Precio)            \n");
    printf("****************************************************\n");
    printf("  ID      MODELO      MARCA        TIPO      PRECIO\n");
    eNotebook aux1 = {101, "Spectre"  , 1001, 5001, 20000, 1};
    eNotebook aux2 = {102, "XPS"      , 1002, 5003, 30000, 1};
    eNotebook aux3 = {103, "MateBook" , 1004, 5003, 25000, 1};
    eNotebook aux4 = {104, "Pro"      , 1003, 5002, 15000, 1};
    eNotebook aux5 = {105, "PixelBook", 1002, 5001, 40000, 1};
    eNotebook aux6 = {106, "Surface"  , 1002, 5002, 60000, 1};
    eNotebook aux7 = {107, "Zenbook"  , 1004, 5004, 33000, 1};
    eNotebook aux8 = {108, "VivoBook" , 1003, 5002, 22000, 1};
    eNotebook aux9 = {109, "Switch"   , 1001, 5004, 28000, 1};
    eNotebook aux10= {110, "IdeaPad"  , 1002, 5001, 55000, 1};

    notebook[0] = aux1;
    notebook[1] = aux2;
    notebook[2] = aux3;
    notebook[3] = aux4;
    notebook[4] = aux5;
    notebook[5] = aux6;
    notebook[6] = aux7;
    notebook[7] = aux8;
    notebook[8] = aux9;
    notebook[9] = aux10;
}

void listarNotebook(eNotebook notebook, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca)
{
    char nombreMarca[20];
    char nombreTipo[20];

    cargarMarca(nombreMarca, marca, tamMarca, notebook.idMarca);
    cargarTipo(nombreTipo, tipo, tamTipo, notebook.idTipo);
    printf("\n%4d  %10s %10s  %10s    %6.2f", notebook.idNotebook, notebook.modelo, nombreMarca, nombreTipo, notebook.precio);
}

int listarNotebooks(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca)
{
    int retorno = 1;

    printf("****************************************************\n");
    printf("              LISTADO DE NOTEBOOKS                  \n");
    printf("           (Ordenado por Marca y Precio)            \n");
    printf("****************************************************\n");
    printf("  ID      MODELO      MARCA        TIPO      PRECIO\n");

    for(int i = 0; i < tam; i++)
    {
        if(notebook[i].libre == 1)
        {
           listarNotebook(notebook[i], tipo, tamTipo, marca, tamMarca);
           retorno = 0;
        }
    }
    printf("\n\n\n");
    return retorno;
}

int listarNotebooksOrdenado(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca)
{
    int retorno = 1;
    char nombreMarca1[20];
    char nombreMarca2[20];
    eNotebook aux;

    for(int i = 0; i < tam -1; i++)
    {
        for( int j = i +1; j < tam; j++)
        {
            cargarMarca(nombreMarca1, marca, tamMarca, notebook[i].idMarca);
            cargarMarca(nombreMarca2, marca, tamMarca, notebook[j].idMarca);

            if (strcmp(nombreMarca1, nombreMarca2) > 0)
            {
                aux = notebook[i];
                notebook[i] = notebook[j];
                notebook[j] = aux;
            }
            else if((strcmp(nombreMarca1, nombreMarca2) == 0) && (notebook[i].precio > notebook[j].precio))
            {
                aux = notebook[i];
                notebook[i] = notebook[j];
                notebook[j] = aux;
            }

        }
    }

        listarNotebooks(notebook, tam, tipo, tamTipo, marca, tamMarca);

    printf("\n\n\n");

    return retorno;
}

void listarModelos()
{
    printf("****************************************************\n");
    printf("                LISTADO DE MODELOS                  \n");
    printf("****************************************************\n\n");
    printf("  ID   DESCRIPCION\n");
    printf("\n   1       Spectre");
    printf("\n   2           XPS");
    printf("\n   3      Matebook");
    printf("\n   4           Pro");
    printf("\n   5     PixelBook");
    printf("\n   6       Surface");
    printf("\n   7       ZenBook");
    printf("\n   8      VivoBook");
    printf("\n   9        Switch");
    printf("\n  10      IdealPad");
    printf("\n\n");
}

int altaNotebook(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca)
{
    int retorno = 1;
    int idModelo;
    int idMarca;
    int idTipo;
    float precio;
    int nuevoID;
    eNotebook aux;
    int indiceLibre = buscarIndiceLibre(notebook, tam);
    nuevoID = indiceLibre + 101;

    if(indiceLibre != -1)
    {
    printf("****************************************************\n");
    printf("                   ALTA NOTEBOOK                    \n");

    listarModelos();

        if(utn_getNumero(&idModelo, "Ingrese el ID del Modelo: ", "Error. Ingreso un dato invalido.\n\n",1, 10, 2) == 0)
        {
            switch(idModelo)
            {
                case 1:
                    strcpy(aux.modelo, "Spectre");
                    break;

                case 2:
                    strcpy(aux.modelo, "XPS");
                    break;

                case 3:
                    strcpy(aux.modelo, "MateBook");
                    break;

                case 4:
                    strcpy(aux.modelo, "Pro");
                    break;

                case 5:
                    strcpy(aux.modelo, "PixelBook");
                    break;

                case 6:
                    strcpy(aux.modelo, "Surface");
                    break;

                case 7:
                    strcpy(aux.modelo, "ZenBook");
                    break;

                case 8:
                    strcpy(aux.modelo, "VivoBook");
                    break;

                case 9:
                    strcpy(aux.modelo, "Switch");
                    break;

                case 10:
                    strcpy(aux.modelo, "IdealPad");
                    break;
            }

            system("clear");
            printf("****************************************************\n");
            printf("                   ALTA NOTEBOOK                    \n");
            listarTipos(tipo, tamTipo);

                if (utn_getNumero(&idTipo, "Ingrese el ID del Tipo: ", "Error. Ingreso un dato invalido\n\n", 5001, 5004, 2) == 0)
                {
                    aux.idTipo = idTipo;

                    system("clear");
                    printf("****************************************************\n");
                    printf("                   ALTA NOTEBOOK                    \n");
                    listarMarcas(marca, tamMarca);

                    if (utn_getNumero(&idMarca, "Ingrese el ID del marca: ", "Error. Ingreso un dato invalido\n\n", 1001, 1004, 2) == 0)
                    {
                        aux.idMarca = idMarca;

                        system("clear");
                        printf("****************************************************\n");
                        printf("                   ALTA NOTEBOOK                    \n");
                        printf("****************************************************\n");
                        printf("                      PRECIO                        \n");
                        printf("****************************************************\n\n");
                        if (utn_getNumeroFlotante(&precio, "Ingrese el precio de la notebook: ", "Error. Ingreso un dato invalido\n\n", 0, 9999999, 2) == 0)
                        {
                            aux.precio = precio;
                            aux.idNotebook = nuevoID;
                            aux.libre = 1;
                            notebook[indiceLibre] = aux;
                            printf("\n\nSe ha cargado correctamente la notebook.\n\n");
                            retorno = 0;
                        }
                    }
                }
            }
        }

    if(retorno == 1)
    {
        printf("\n\nNo se pudo completar el alta.\n\n");
    }

    return retorno;
}

int buscarIndiceLibre(eNotebook *notebook, int tam)
{
    int retorno = -1;

    for(int i = 0; i < tam; i++)
    {
        if(notebook[i].libre == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int modificarNotebook(eNotebook *notebook, int tam, eMarca *marca, int tamMarca, eTipo *tipo, int tamTipo)
{
    int retorno;
    int ID;
    int indice;
    int nuevoTipo;
    float nuevoPrecio;
    printf("****************************************************\n");
    printf("                    MODIFICAR                     \n");
    listarNotebooks(notebook, tam, tipo, tamTipo, marca, tamMarca);

    if(utn_getNumero(&ID, "Ingrese el ID de la notebook a modificar: ", "Error. Ha ingresado un dato invalido\n\n", 101, 999, 2) == 0)
     {
        indice = buscarNotebookID(notebook, tam, ID);
        if (indice >= 0)
        {
        system("clear");
        printf("****************************************************\n");
        printf("                     MODIFICAR                     \n");
        printf("****************************************************\n");
        printf("  ID      MODELO      MARCA        TIPO      PRECIO\n");
        listarNotebook(notebook[indice], tipo, tamTipo, marca, tamMarca);
        printf("\n****************************************************\n");
        switch (menuModificar())
            {
            case 1:
                system("clear");
                printf("****************************************************\n");
                printf("                   MODIFICAR TIPO                    \n");
                printf("****************************************************\n");
                printf("  ID      MODELO      MARCA        TIPO      PRECIO\n");
                listarNotebook(notebook[indice], tipo, tamTipo, marca, tamMarca);
                printf("\n");
                listarTipos(tipo, tamTipo);
                if (utn_getNumero(&nuevoTipo, "Ingrese el ID del nuevo tipo: ", "Error. Ingreso un dato invalido.\n\n",5001, 5004, 2) == 0)
                {
                notebook[indice].idTipo = nuevoTipo;
                printf("\n\nSe ha realizado la modificacion.\n\n");
                }
                else
                    {
                    printf("\n\nNo se pudo completar la modificacion.\n\n");
                    retorno = 0;
                    }
                break;

            case 2:
                system("clear");
                printf("****************************************************\n");
                printf("                  MODIFICAR PRECIO                  \n");
                printf("****************************************************\n");
                printf("  ID      MODELO      MARCA        TIPO      PRECIO\n");
                listarNotebook(notebook[indice], tipo, tamTipo, marca, tamMarca);
                printf("\n****************************************************\n");
                printf("\n\n\n");
                if (utn_getNumeroFlotante(&nuevoPrecio, "Ingrese el nuevo Precio: ", "Error. Ingreso un dato invalido.\n\n",0, 999999, 2) == 0)
                {
                    notebook[indice].precio = nuevoPrecio;
                    printf("\n\nSe ha realizado la modificacion.\n\n");
                    retorno = 0;
                }
                else
                    {
                    printf("\n\nNo se pudo completar la modificacion.\n\n");
                    }
                break;
            }
        }
     }
    return retorno;
}

int menuModificar()
{
    int retorno = 0;
    int opcion;
    printf("                    OPCIONES                      \n");
    printf("****************************************************\n\n");
    if(utn_getNumero(&opcion, "1.     Modificar Tipo\n2.     Modificar Precio\n\n\nIngrese la opcion: ","Error. Ingreso un dato invalido.\n\n", 1, 2, 2) == 0)
    {
        retorno = opcion;
    }
    __fpurge(stdin);

    return retorno;
}

int buscarNotebookID(eNotebook *notebook, int tam, int id)
{
    int retorno = -1;

    for(int i = 0; i < tam; i++)
    {
        if(notebook[i].idNotebook == id && notebook[i].libre == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int bajaNotebook(eNotebook *notebook, int tam, eMarca *marca, int tamMarca, eTipo *tipo, int tamTipo)
{
    int retorno = 1;
    int ID;
    int indice;
    char confirma = 'n';

    listarNotebooks(notebook, tam, tipo, tamTipo, marca, tamMarca);
    if(utn_getNumero(&ID, "Ingrese el ID de la notebook a dar de baja: ", "Error. Ha ingresado un dato invalido\n\n", 101, 999, 2) == 0)
    {
        system("clear");

        printf("****************************************************\n");
        printf("                   BAJA NOTEBOOK                    \n");
        printf("****************************************************\n");
        indice = buscarNotebookID(notebook, tam, ID);

        if (indice >= 0)
        {
            printf("  ID      MODELO      MARCA        TIPO      PRECIO\n");
            listarNotebook(notebook[indice], tipo, tamTipo, marca, tamMarca);
            printf("\n\n\nIngrese 's' para confirmar baja: ");
            scanf("%c", &confirma);
            __fpurge(stdin);
            if(confirma == 's')
            {
                notebook[indice].libre = 0;
                retorno = 0;
                printf("\n\nSe ha realizado la baja.\n\n");
            }
        }
    }
    if (retorno == 1)
    {
        printf("\n\nNo se pudo completar la baja.\n\n");
    }

     return retorno;
}







