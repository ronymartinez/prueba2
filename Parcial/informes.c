#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "informes.h"
#include "utn.h"

#define TAM 1000
#define TAMMARCA 4
#define TAMTIPO 4
#define TAMSER 4
#define TAMTRAB 1000

int menuInformes(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca, eTrabajo *trabajo, int tamTrab, eServicio *servicio, int tamSer)
{
    int retorno = 1;
    int opcion;
    char seguir = 's';

    system("clear");
    printf("****************************************************\n");
    printf("                 MENU INFORMES\n");
    printf("****************************************************\n");
    printf("\n1) Mostrar las notebooks del tipo seleccionado.");
    printf("\n2) Mostrar notebooks de una marca seleccionada.");
    printf("\n3) Informar la o las notebooks más baratas.");
    printf("\n4) Mostrar un listado de las notebooks separadas por marca.");
    printf("\n5) Mostrar notebooks por tipo y marca seleccionados.");
    printf("\n6) Mostrar la o las marcas más elegidas por los clientes.");
    printf("\n7) Pedir una notebook y mostrar los trabajos que se le hicieron.");
    printf("\n8) Pedir un notebook e informar la suma de los importes de los services.");
    printf("\n9) Pedir un servicio y mostrar las notebooks a las que se realizó ese servicio y la fecha.");
    printf("\n10)Pedir una fecha y mostrar todos los servicios realizados en la misma.");
    printf("\n11) Salir.\n\n\n");


    utn_getNumero(&opcion, "Ingrese la opcion: ", "Error. Ingreso un dato invalido.\n\n", 1, 11,2);
    __fpurge(stdin);

    while(seguir == 's')
    {
        system("clear");

        switch (opcion)
        {
            case 1:
                mostrarNotebooksPorTipo(notebook, TAM, tipo, TAMTIPO, marca, TAMMARCA);
                break;

            case 2:
                mostrarNotebooksPorMarca(notebook, TAM, tipo, TAMTIPO, marca, TAMMARCA);
                break;

            case 3:
                mostrarNotebooksBaratas(notebook, TAM, tipo, TAMTIPO, marca, TAMMARCA);
                break;

            case 4:
                notebooksSeparadasPorMarca(notebook, TAM, tipo, TAMTIPO, marca, TAMMARCA);
                break;

            case 5:
                tipoyMarcaSeleccionada(notebook, TAM, tipo, TAMTIPO, marca, TAMMARCA);
                break;

            case 6:
                marcaMasElegida(notebook, TAM, tipo, TAMTIPO, marca, TAMMARCA);
                break;

            case 7:
                notebookYTrabajoCargado(notebook, TAM, tipo, TAMTIPO, marca, TAMMARCA, trabajo, TAMTRAB, servicio, TAMSER);
                break;

            case 8:
                sumaDeSerViciosEnNotebook(notebook, TAM, tipo, TAMTIPO, marca, TAMMARCA, trabajo, TAMTRAB, servicio, TAMSER);
                break;

            case 9:
                mostrarServicioElegido(servicio, TAMSER, trabajo, tamTrab);
                break;

            case 10:
                mostrarServiciosPorFecha(trabajo, TAMTRAB, servicio, TAMSER);
                break;

            case 11:
                printf("\n\nHa finalizado el programa.\n\n");
                seguir = 'n';
                break;
        }
        retorno = 0;
        seguir = 'n';
    }

   return retorno;
}

int mostrarNotebooksPorTipo(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca)
{
    int idTipo;
    int retorno = 1;
    system("clear");
    printf("****************************************************\n");
    printf("             MOSTRAR NOTEBOOKS POR TIPO\n");
    printf("****************************************************\n");

    listarTipos(tipo, tamTipo);

    if (utn_getNumero(&idTipo, "Ingrese el ID del tipo: ", "Error. Ingreso un dato invalido.\n\n", 5001, 5004, 2) == 0 )
    {
        system("clear");
        printf("****************************************************\n");
        printf("     LISTADO DE NOTEBOOKS POR TIPO SELECCIONADO\n");
        printf("****************************************************\n");
        printf("  ID      MODELO      MARCA        TIPO      PRECIO\n");

        for( int i = 0; i < tam; i++)
        {
            if(idTipo == notebook[i].idTipo)
            {
                listarNotebook(notebook[i], tipo, tamTipo, marca, tamMarca);
                retorno = 0;
            }
        }
        printf("\n\n\n");
    }
    if (retorno == 1)
    {
        printf("\n\nNo se encontraron notebooks con el ID seleccionado.\n\n");
    }

    return retorno;
}

int mostrarNotebooksPorMarca(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca)
{
    int idMarca;
    int retorno = 1;
    system("clear");
    printf("****************************************************\n");
    printf("             MOSTRAR NOTEBOOKS POR MARCA\n");
    printf("****************************************************\n");

    listarMarcas(marca, tamMarca);

    if (utn_getNumero(&idMarca, "Ingrese el ID de la Marca: ", "Error. Ingreso un dato invalido.\n\n", 1001, 1004, 2) == 0 )
    {
        system("clear");
        printf("****************************************************\n");
        printf("     LISTADO DE NOTEBOOKS POR MARCA SELECCIONADA\n");
        printf("****************************************************\n");
        printf("  ID      MODELO      MARCA        TIPO      PRECIO\n");

        for( int i = 0; i < tam; i++)
        {
            if(idMarca == notebook[i].idMarca)
            {
                listarNotebook(notebook[i], tipo, tamTipo, marca, tamMarca);
                retorno = 0;
            }
        }
        printf("\n\n\n");
    }
    if (retorno == 1)
    {
        printf("\n\nNo se encontraron notebooks con el ID seleccionado.\n\n");
    }

    return retorno;
}

int mostrarNotebooksBaratas(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca)
{
    int retorno = 1;
    int contador = 0;
    float minimo;

    system("clear");
    printf("****************************************************\n");
    printf("            MOSTRAR NOTEBOOKS MAS BARATA\n");
    printf("****************************************************\n");

    for(int i = 0; i < tam; i++)
    {
        if ((notebook[i].precio < minimo && notebook[i].libre == 1) || contador == 0 )
        {
            minimo = notebook[i].precio;
            contador++;
            retorno = 0;
        }
     }

    if(retorno == 0)
    {
        printf("  ID      MODELO      MARCA        TIPO      PRECIO\n");
        for( int i = 0; i < tam; i++)
        {
            if(minimo == notebook[i].precio && notebook[i].libre == 1)
            {
                listarNotebook(notebook[i], tipo, tamTipo, marca, tamMarca);
                retorno = 2;
            }
        }
    }

    if(retorno == 1)
    {
        printf("\n\nNo se encontraron notebooks cargadas.\n\n");
    }

    printf("\n\n\n");

    return retorno;
}

int notebooksSeparadasPorMarca(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca)
{
    int retorno = 1;
    int flagCompaq = 0;
    int flagAsus = 0;
    int flagAcer = 0;
    int flagHP = 0;

    system("clear");
    printf("****************************************************\n");
    printf("                LISTADO POR MARCA\n");
    printf("****************************************************\n");
    printf("                      COMPAQ\n\n");
    printf("  ID      MODELO      MARCA        TIPO      PRECIO\n");


    for(int i = 0; i < tam; i++)
    {
        if(notebook[i].idMarca == 1001 && notebook[i].libre == 1)
        {
            listarNotebook(notebook[i], tipo, tamTipo, marca, tamMarca);
            flagCompaq++;
            retorno = 0;
        }
    }
    printf("\n");
    if(flagCompaq == 0)
    {
        printf("\nNo hay notebooks con esta marca.\n");
    }

    printf("****************************************************\n");
    printf("                      ASUS\n\n");
    printf("  ID      MODELO      MARCA        TIPO      PRECIO\n");

    for(int i = 0; i < tam; i++)
    {
        if(notebook[i].idMarca == 1002 && notebook[i].libre == 1)
        {
            listarNotebook(notebook[i], tipo, tamTipo, marca, tamMarca);
            flagAsus++;
            retorno = 0;
        }
    }
    printf("\n");
    if(flagAsus == 0)
    {
        printf("\nNo hay notebooks con esta marca.\n");
    }

    printf("****************************************************\n");
    printf("                      ACER\n\n");
    printf("  ID      MODELO      MARCA        TIPO      PRECIO\n");


    for(int i = 0; i < tam; i++)
    {
        if(notebook[i].idMarca == 1003 && notebook[i].libre == 1)
        {
            listarNotebook(notebook[i], tipo, tamTipo, marca, tamMarca);
            flagAcer++;
            retorno = 0;
        }
    }
    printf("\n");
    if(flagAcer == 0)
    {
        printf("\nNo hay notebooks con esta marca.\n");
    }

    printf("****************************************************\n");
    printf("                       HP\n\n");
    printf("  ID      MODELO      MARCA        TIPO      PRECIO\n");


    for(int i = 0; i < tam; i++)
    {
        if(notebook[i].idMarca == 1004 && notebook[i].libre == 1)
        {
            listarNotebook(notebook[i], tipo, tamTipo, marca, tamMarca);
            flagHP++;
            retorno = 0;
        }
    }
    printf("\n");retorno = 0;
    if(flagHP == 0)
    {
        printf("\nNo hay notebooks con esta marca.\n");
    }
    printf("\n****************************************************\n");

    printf("\n\n");

    return retorno;
}

int tipoyMarcaSeleccionada(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca)
{
    int retorno = 1;
    int idTipo;
    int idMarca;
    int contador = 0;

    printf("****************************************************\n");
    printf("           LISTADO POR TIPO Y MARCA\n");
    printf("****************************************************\n");

    listarTipos(tipo, tamTipo);
    if (utn_getNumero(&idTipo, "Ingrese el ID del tipo: ", "Error. Ingreso un dato invalido.\n\n", 5001, 5004, 2) == 0 )
    {
      listarMarcas(marca, tamMarca);
      if (utn_getNumero(&idMarca, "Ingrese el ID de la Marca: ", "Error. Ingreso un dato invalido.\n\n", 1001, 1004, 2) == 0 )
        {

        system("clear");
        printf("****************************************************\n");
        printf("           LISTADO POR TIPO Y MARCA\n");
        printf("****************************************************\n");
        printf("  ID      MODELO      MARCA        TIPO      PRECIO\n");

            for(int i = 0; i < tam; i++)
            {
                if(notebook[i].idMarca == idMarca && notebook[i].idTipo == idTipo && notebook[i].libre == 1)
                {
                    listarNotebook(notebook[i], tipo, tamTipo, marca, tamMarca);
                    contador++;
                    retorno = 0;
                }
            }
        }
        else
            {
                printf("\n\n-No se pudo realizar la operacion.\n\n");
                retorno = -1;
            }
    }
    else
        {
            printf("\n\n-No se pudo realizar la operacion.\n\n");
            retorno = -1;
        }

    if(contador > 0)
    {
        printf("\n\n\n-Hay %d notebooks con ese tipo y marca.\n\n\n", contador);
    }
    if(retorno == 1 && contador == 0)
    {
        printf("\n\n\nNo se encontraron notebooks con ese tipo y marca.\n\n");
        //getchar();
    }

  return retorno;
}

int marcaMasElegida(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca)
{
    int retorno = 1;
    int contadorCompag = 0;
    int contadorAsus = 0;
    int contadorAcer = 0;
    int contadorHP = 0;
    int contadorMayor = 0;
    char nombreMarca [20];
    int idMarcaMayor;

     for(int i = 0; i < tam; i++)
    {
        if (notebook[i].idMarca == 1001 && notebook[i].libre == 1)
        {
            contadorCompag++;
        }
        if (notebook[i].idMarca == 1002 && notebook[i].libre == 1)
        {
            contadorAsus++;
        }
        if (notebook[i].idMarca == 1003 && notebook[i].libre == 1)
        {
            contadorAcer++;
        }
        if (notebook[i].idMarca == 1004 && notebook[i].libre == 1)
        {
            contadorHP++;
        }
//********************************
        if(contadorMayor < contadorCompag)
           {
               idMarcaMayor = notebook[i].idMarca;
               contadorMayor = contadorCompag;
           }
        if(contadorMayor < contadorAsus)
           {
               idMarcaMayor = notebook[i].idMarca;
               contadorMayor = contadorAsus;
           }
        if(contadorMayor < contadorAcer)
           {
               idMarcaMayor = notebook[i].idMarca;
               contadorMayor = contadorAcer;
           }
        if(contadorMayor < contadorHP)
           {
               idMarcaMayor = notebook[i].idMarca;
               contadorMayor = contadorHP;
           }

        retorno = 0;
    }
    printf("****************************************************\n");
    printf("                MARCA MAS ELEGIDA\n");
    printf("****************************************************\n");

    cargarMarca(nombreMarca, marca, tamMarca, idMarcaMayor);
    printf("\n\nLa marca mas elegida es la %s.\n\n\n", nombreMarca);

    return retorno;
}

int notebookYTrabajoCargado(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca, eTrabajo *trabajo, int tamTrab, eServicio *servicio, int tamSer)
{
    int retorno = 1;
    int idNotebook;

    printf("****************************************************\n");
    printf("        TRABAJOS REALIZADOS EN UNA NOTEBOOK\n");
   // printf("****************************************************\n");

    listarNotebooks(notebook, tam, tipo, tamTipo, marca, tamMarca);
    //listarTrabajos(trabajo, tamTrab, servicio, tamSer);
    printf("\n\n");

    if(utn_getNumero(&idNotebook, "Ingrese el ID de la notebook: ", "Error. Ingreso un dato invalido.\n\n", 100, 999, 2) == 0)
    {
        system("clear");
        printf("****************************************************\n");
        printf("        TRABAJOS REALIZADOS EN UNA NOTEBOOK\n");
        printf("****************************************************\n");
        printf("  ID        ID\n");
        printf("TRABAJO   NOTEBOOK       SERVICIO         FECHA\n");

        for(int i = 0; i < tamTrab; i++)
        {
           if(trabajo[i].idNotebook == idNotebook && trabajo[i].libre == 1)
           {
                listarTrabajo(trabajo[i], servicio, tamSer);
                retorno = 0;
           }
        }
    }
    printf("\n\n\n");

    if(retorno == 1)
    {
        printf("No hay trabajos cargados con el ID ingresado.\n\n");
    }


    return retorno;
}

int sumaDeSerViciosEnNotebook(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca, eTrabajo *trabajo, int tamTrab, eServicio *servicio, int tamSer)
{
    int retorno = 1;
    int idNotebook;
    float acumulador = 0;
    int idServicio;

    printf("****************************************************\n");
    printf("        SUMA DE LOS SERVICIOS A UNA NOTEBOOK\n");

    listarNotebooks(notebook, tam, tipo, tamTipo, marca, tamMarca);
    printf("\n\n");

    if(utn_getNumero(&idNotebook, "Ingrese el ID de la notebook: ", "Error. Ingreso un dato invalido.\n\n", 100, 999, 2) == 0)
    {
        for(int i = 0; i < tamTrab; i++)
        {
            if(trabajo[i].idNotebook == idNotebook && trabajo[i].libre == 1)
            {
               idServicio = trabajo[i].idServicio;

               for(int j = 0; j < tamSer; j++)
                {
                    if(idServicio == servicio[j].idServicio)
                    {
                        acumulador = acumulador + servicio[j].precio;
                        retorno = 0;
                    }
                }
            }
        }

    }
    system("clear");
    printf("****************************************************\n");
    printf("        SUMA DE LOS SERVICIOS A UNA NOTEBOOK\n");
    printf("****************************************************\n");

    printf("\nEl total de importes de los servicios realizados es de %.2f\n\n\n", acumulador);

    if(retorno == 1)
    {
        printf("No hay trabajos cargados con el ID ingresado.\n\n");
    }


    return retorno;
}

int mostrarServicioElegido(eServicio *servicio, int tamSer, eTrabajo *trabajo, int tamTrab)
{
    int retorno = 0;
    int idServicio;

    system("clear");
    printf("****************************************************\n");
    printf("      LISTADO DE NOTEBOOKS POR SERVICIO ELEGIDO\n");
    //printf("****************************************************\n");

    listarServicios(servicio, tamSer);
    if (utn_getNumero(&idServicio, "ingrese el ID del servicio elegido: ", "Error. No ingreso un dato valido.\n\n", 20001, 20004,2) == 0)
    {
        system("clear");
        printf("****************************************************\n");
        printf("      LISTADO DE NOTEBOOKS POR SERVICIO ELEGIDO\n");
        printf("****************************************************\n");
        printf("  ID        ID\n");
        printf("TRABAJO   NOTEBOOK       SERVICIO         FECHA\n");

        for(int i = 0; i < tamTrab; i++)
        {
            if(idServicio == trabajo[i].idServicio && trabajo[i].libre == 1)
            {
                listarTrabajo(trabajo[i], servicio, tamSer);
                retorno = 0;
            }
        }
    }
    printf("\n\n\n");
    if(retorno == 1)
    {
        printf("\n\nNo se encontraron servicios para el ID seleccionado.");
    }
    return retorno;
}

int mostrarServiciosPorFecha(eTrabajo *trabajo, int tamTrab, eServicio *servicio, int tamSer)
{
    int retorno = 1;
    int dia;
    int mes;
    int anio;

    printf("****************************************************\n");
    printf("          LISTADO DE SERVICIOS POR FECHA\n");
    printf("****************************************************\n");

    if (utn_getNumero(&dia, "Ingrese el DIA: ", "Error. Ingreso un dato invalido.\n\n", 1, 31, 2) == 0)
    {
        if (utn_getNumero(&mes, "Ingrese el MES: ", "Error. Ingreso un dato invalido.\n\n", 1, 12, 2) == 0)
        {
            if (utn_getNumero(&anio, "Ingrese el ANIO: ", "Error. Ingreso un dato invalido.\n\n", 1990, 2030, 2) == 0)
            {
            system("clear");
            printf("****************************************************\n");
            printf("          LISTADO DE SERVICIOS POR FECHA\n");
            printf("****************************************************\n");
            printf("  ID        ID\n");
            printf("TRABAJO   NOTEBOOK       SERVICIO         FECHA\n");
            retorno = 0;
                for(int i = 0; i < tamTrab; i ++)
                {

                    if(trabajo[i].fecha.dia == dia && trabajo[i].fecha.mes == mes && trabajo[i].fecha.anio == anio)
                    {
                        listarTrabajo(trabajo[i], servicio, tamSer);
                        retorno = 2;
                    }
                }
            }
        }
    }

    if(retorno == 0)
    {
        printf("\n\nNo hay trabajos realizados en la fecha indicada.\n\n");
    }
    printf("\n\n\n");

    return retorno;
}





