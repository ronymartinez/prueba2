#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED
#include "tipo.h"
#include "marca.h"

typedef struct
{
    int idNotebook;
    char modelo [20];
    int idMarca; //Validar
    int idTipo; //Validar
    float precio;
    int libre;
} eNotebook;

#endif // NOTEBOOK_H_INCLUDED

/** \brief Inicializa el array de estructura notebooks
 *
 * \param Array de la Estructura notebook
 * \param Tamaño de la estructura notebook
 * \return 0 si pudo hacer la inicializacion, 1 si no lo hace
 *
 */
int inicializarNotebooks(eNotebook *notebook, int tam);

/** \brief Hardeodea notebooks
 *
 * \param Array de la Estructura notebook
 * \return void
 */
void hardcodearNotebooks(eNotebook *notebook);

/** \brief Muestra una notebook seleccionada
 *
 * \param Indice de la estructura Notebook
 * \param Array de la Estructura tipo
 * \param Tamaño del array de la estructura tipo
 * \param Array de la Estructura marca
 * \param Tamaño del array de la estructura marca
 * \return void
 */
void listarNotebook(eNotebook notebook, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca);

/** \brief Muestra la lista de las notebooks cargadas
 *
 * \param Array de la Estructura Notebook
 * \param Tamaño del array de la estructura notebook
 * \param Array de la Estructura tipo
 * \param Tamaño del array de la estructura tipo
 * \param Array de la Estructura marca
 * \param Tamaño del array de la estructura marca
 * \return 0 si pudo listar, 1 si no lista
 *
 */
int listarNotebooks(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca);

/** \brief Muestra la lista de las notebooks cargadas ordenada por marca y precio
 *
 * \param Array de la Estructura Notebook
 * \param Tamaño del array de la estructura notebook
 * \param Array de la Estructura tipo
 * \param Tamaño del array de la estructura tipo
 * \param Array de la Estructura marca
 * \param Tamaño del array de la estructura marca
 * \return 0 si pudo listar, 1 si no lista
 *
 */
int listarNotebooksOrdenado(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca);

/** \brief Da de baja una Muestra la lista de las notebooks cargadas ordenada por marca y precionotebook cargada
 *
 * \param Array de la Estructura Notebook
 * \param Tamaño del array de la estructura Notebook
 * \param Array de la Estructura Marca
 * \param Tamaño del array de la estructura marca
 * \param Array de la Estructura tipo
 * \param Tamaño del array de la estructura tipo
 * \return 0 si pudo realizar la baja, 1 si no realizo la baja
 *
 */
int bajaNotebook(eNotebook *notebook, int tam, eMarca *marca, int tamMarca, eTipo *tipo, int tamTipo);

/** \brief Busca el indice de una notebook
 *
 * \param Array de la Estructura Notebook
 * \param Tamaño del array de la estructura Notebook
 * \param ID de la notebook a buscar
 * \return  Indice de la notebook buscada o -1 si no lo encuentra
 */
int buscarNotebookID(eNotebook *notebook, int tam, int id);

/** \brief Menu para modificar precios o tipo
 *
 * \return Opcion elegida
 *
 */
int menuModificar();


/** \brief Modica el tipo o precio de una notebook
 *
 * \param Array de la Estructura de la notebook
 * \param Tamaño del array de la estructura notebook
 * \param Array de la Estructura marca
 * \param Tamaño del array de la estructura marca
 * \param Array de la Estructura tipo
 * \param Tamaño del array de la estructura tipo
 * \return 0 si hizo la modificacion, 1 si no lo hizo
 *
 */
int modificarNotebook(eNotebook *notebook, int tam, eMarca *marca, int tamMarca, eTipo *tipo, int tamTipo);

/** \brief Busca el primer indice libre del array
 *
 * \param Array de la Estructura notebook
 * \param Tamaño del array de la estructura notebook
 * \return PTrimer indice libre o -1 si no encontro indice libre
 *
 */
int buscarIndiceLibre(eNotebook *notebook, int tam);

/** \brief Da de alta una notebook
 *
 * \param Array de la Estructura Notebook
 * \param Tamaño del array  de la estructura notebook
 * \param Array de la Estructura tipo
 * \param Tamaño del array de la estructura tipo
 * \param Array Estructura marca
 * \param Tamaño del array de la estructura marca
 * \return 0 si pudo realizar el alta, 1 si no lo realizo
 */
int altaNotebook(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca);















