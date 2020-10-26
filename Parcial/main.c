#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "string.h"
#include "utn.h"
#include "trabajo.h"
#include "servicio.h"
#include "notebook.h"
#include "tipo.h"
#include "marca.h"
#include "informes.h"

#define TAM 1000
#define TAMMARCA 4
#define TAMTIPO 4
#define TAMSER 4
#define TAMTRAB 1000

char menuPrincipal();

int main()
{
    eMarca marca[TAMMARCA] = {{1001, "Compaq"}, {1002, "Asus"}, {1003, "Acer"}, {1004, "HP"}};
    eTipo tipo[TAMTIPO] = {{5001, "Gamer"},{5002, "Disenio"},{5003, "Ultrabook"}, {5004, "Normalita"}};
    eServicio servicio[TAMSER] = {{20001, "Bateria", 250}, {20002, "Antivirus", 300}, {20003, "Actualizacion", 400}, {20004, "Fuente", 600}};
    eNotebook notebook[TAM];
    inicializarNotebooks(notebook, TAM);
    hardcodearNotebooks(notebook);
    eTrabajo trabajo[TAMTRAB];
    inicializarTrabajos(trabajo, TAMTRAB);
    hardcodearTrabajos(trabajo);

    int llaveNotebook = 0; // INICIO HARCODEADO, HABILITO TODAS LAS OPCIONES DEL PRIMER MENU
    int llaveTrabajo = 0;; // INICIO HARCODEADO, HABILITO LOS INFORMES

    char seguir = 's';

    while(seguir == 's')
    {
        system("clear");

        switch (menuPrincipal())
        {
            case 'a':
                system("clear");
                if (altaNotebook(notebook, TAM, tipo, TAMTIPO, marca, TAMMARCA) == 0)
                {
                    llaveNotebook = 0; // HABILITA LAS DEMAS OPCIONES
                }
                break;

            case 'b':
                system("clear");
                if(llaveNotebook == 0) // INICIO CON LLAVE ABIERTA
                {
                    modificarNotebook(notebook, TAM, marca, TAMMARCA, tipo, TAMTIPO);
                }else
                    {
                        printf("\n\nNo puede realizar modificaciones si no ingreso una notebook.\n\n");
                    }
                break;

            case 'c':
                system("clear");
                if(llaveNotebook == 0) // INICIO CON LLAVE ABIERTA
                {
                    bajaNotebook(notebook, TAM, marca, TAMMARCA, tipo, TAMTIPO);
                }
                    else
                    {
                        printf("\n\nNo puede dar de baja si no ingreso una notebook.\n\n");
                    }
                break;

            case 'd':
                system("clear");
                if(llaveNotebook == 0)// INICIO CON LLAVE ABIERTA
                {
                    listarNotebooksOrdenado(notebook, TAM, tipo, TAMTIPO, marca, TAMMARCA);
                }
                    else
                    {
                        printf("\n\nNo puede listar si no ingreso una notebook.\n\n");
                    }
                break;

            case 'e':
                system("clear");
                listarMarcas(marca, TAMMARCA);
                break;

            case 'f':
                system("clear");
                listarTipos(tipo, TAMTIPO);
                break;

            case 'g':
                system("clear");
                listarServicios(servicio, TAMSER);
                break;

            case 'h':
                system("clear");
                if (altaTrabajo(trabajo, TAMTRAB, notebook, TAM, marca, TAMMARCA, tipo, TAMTIPO, servicio, TAMSER) == 0)
                {
                        llaveTrabajo = 0;
                }
                break;

            case 'i':
                system("clear");
                if(llaveTrabajo == 0) // INICIO CON LLAVE ABIERTA
                {
                    listarTrabajos(trabajo, TAMTRAB, servicio, TAMSER);
                }
                else
                    {
                        printf("\n\nNo se puede listar si no ingreso un trabajo.\n\n");
                    }
                break;

            case 'j':
                if(llaveTrabajo == 0) // INICIO CON LLAVE ABIERTA
                {
                        menuInformes(notebook, TAM, tipo, TAMTIPO, marca, TAMMARCA, trabajo, TAMTRAB, servicio, TAMSER);
                }
                else
                    {
                        printf("\n\nNo se puede informar si no ingreso un trabajo o notebook.\n\n");
                    }
                break;

            case 'k':
                printf("\n\nHa finalizado el programa.\n\n");
                seguir = 'n';
                break;
        }
        system("read -p'Presiona Enter para continuar...' var");
    }

    return 0;
}

char menuPrincipal()
{
    char opcion;

    system("clear");
    printf("**************************\n");
    printf("      MENU PRINCIPAL      \n");
    printf("**************************\n");
    printf("\na) Alta Notebook\nb) Modificar Notebook\nc) Baja Notebook\nd) Listar Notebooks\ne) Listar Marcas\nf) Listar Tipos\ng) Listar Servicios\nh) Alta Trabajo\ni) Listar Trabajos\nj) Informes\nk) Salir\n\n\n");

    utn_getCaracter(&opcion,"Ingrese la opcion: ","Error. Ingreso un dato invalido.\n\n", 'a', 'k', 3);
    __fpurge(stdin);

    return opcion;
}










