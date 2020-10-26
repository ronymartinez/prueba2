#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "servicio.h"
#include "notebook.h"
#include "marca.h"
#include "tipo.h"

typedef struct
{
    int idTrabajo;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int libre;
} eTrabajo;


#endif // TRABAJO_H_INCLUDED

/** \brief Inicializa el array de estructura Trabajo
 *
 * \param Array de la Estructura trabajo
 * \param Tamaño del array de la estructura trabajo
 * \return 0 si pudo hacer la inicializacion, 1 si no lo hace
 */
int inicializarTrabajos(eTrabajo *trabajos, int tamTrab);

/** \brief Harcodea trabajos
 *
 * \param Array de la Estructura trabajo
 * \return void
 */
void hardcodearTrabajos(eTrabajo *trabajos);

/** \brief Lista los trabajos cargados
 *
 * \param Array de la Estructura trabajo
 * \param Tamaño del array de la estructura trabajo
 * \param Array de la Estructura servicio
 * \param Tamaño del array de la estructura servicio
 * \return 0 si pudo listar, 1 si no listo
 */
int listarTrabajos(eTrabajo *trabajo, int tamTrab, eServicio *servicio, int tamSer);

/** \brief Lista un trabajo
 *
 * \param Indice de la Estructura trabajo
 * \param Array de la Estructura servicio
 * \param Tamaño del array de la estructura servicio
 * \return 0 si pudo listar, 1 si no listo
 */
int listarTrabajo(eTrabajo trabajo, eServicio *servicio, int tamSer);

/** \brief Da de alta un trabajo
 *
 * \param Array de la estructura Trabajo
 * \param Tamaño del array de la estructura Trabajo
 * \param Array de la estructura Notebook
 * \param Tamaño del array de la estructura Notebook
 * \param Array de la estructura Marca
 * \param Tamaño del array de la estructura Marca
 * \param Array de la estructura Tipo
 * \param Tamaño del Array de la estructura Tipo
 * \param Array de la estructura Servicio
 * \param Tamaño del array de la estructura Tipo
 * \return int
 *
 */
int altaTrabajo(eTrabajo *trabajos, int tamTrab, eNotebook *notebook, int tam, eMarca *marca, int tamMarca, eTipo *tipo, int tamTipo, eServicio *servicio, int tamSer);

/** \brief Busca el primer indice libre del array Trabajo
 *
 * \param Array de la estructura Trabajo
 * \param amaño del array de la estructura Notebook
 * \return Primer indice libre, -1 si no encuentra indice
 *
 */
int buscarTrabajoLibre (eTrabajo *trabajo, int tamTrab);
