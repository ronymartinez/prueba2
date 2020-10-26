#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "notebook.h"
#include "tipo.h"
#include "marca.h"
#include "servicio.h"
#include "trabajo.h"

#endif // INFORMES_H_INCLUDED

/** \brief Menu para todos los informes
 *
 * \param Array de la estructura notebook
 * \param Tamao del array de la estructura Notebook
 * \param Array de la eestructura Tipo
 * \param Tamaño del array de la estructura Tipo
 * \param Array de la estructura Marca
 * \param Tamaño del Array de la estructura marca
 * \param Array de la estructura Trabajo
 * \param Tamaño del array de la estructura Trabajo
 * \param Array de la estructura Servicio
 * \param Tamaño del array de la estructura servicio
 * \return 0 si realizo algun informe, 1 si no lo realizo
 *
 */
int menuInformes(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca, eTrabajo *trabajo, int tamTrab, eServicio *servicio, int tamSer);

/** \brief Muestra la lista de notebook por el tipo seleccionado
 *
 * \param Array de la estructura notebook
 * \param Tamao del array de la estructura Notebook
 * \param Array de la eestructura Tipo
 * \param Tamaño del array de la estructura Tipo
 * \param Array de la estructura Marca
 * \param Tamaño del Array de la estructura marca
 * \return 0 si realizo el informe, 1 si no lo realizo
 *
 */
int mostrarNotebooksPorTipo(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca);

/** \brief Muestra la lista de notebooks por la marca seleccionada
 *
 * \param Array de la estructura notebook
 * \param Tamao del array de la estructura Notebook
 * \param Array de la eestructura Tipo
 * \param Tamaño del array de la estructura Tipo
 * \param Array de la estructura Marca
 * \param Tamaño del Array de la estructura marca
 * \return 0 si realizo el informe, 1 si no lo realizo
 *
 */
int mostrarNotebooksPorMarca(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca);

/** \brief Lista las notebook separadas por marca
 *
 * \param Array de la estructura notebook
 * \param Tamao del array de la estructura Notebook
 * \param Array de la eestructura Tipo
 * \param Tamaño del array de la estructura Tipo
 * \param Array de la estructura Marca
 * \param Tamaño del Array de la estructura marca
 * \return 0 si realizo el informe, 1 si no lo realizo
 *
 */
int mostrarNotebooksBaratas(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca);

/** \brief Muestra y cuenta las notebook mas baratas
 *
 * \param Array de la estructura notebook
 * \param Tamao del array de la estructura Notebook
 * \param Array de la eestructura Tipo
 * \param Tamaño del array de la estructura Tipo
 * \param Array de la estructura Marca
 * \param Tamaño del Array de la estructura marca
 * \return 0 si realizo el informe, 1 si no lo realizo
 *
 */
int notebooksSeparadasPorMarca(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca);

/** \brief Muestra las notebooks del tipo y marca seleccionado
 *
 * \param Array de la estructura notebook
 * \param Tamao del array de la estructura Notebook
 * \param Array de la eestructura Tipo
 * \param Tamaño del array de la estructura Tipo
 * \param Array de la estructura Marca
 * \param Tamaño del Array de la estructura marca
 * \return 0 si realizo el informe, 1 si no lo realizo
 *
 */
int tipoyMarcaSeleccionada(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca);

/** \brief Muestra la marca mas elegida
 *
 * \param Array de la estructura notebook
 * \param Tamao del array de la estructura Notebook
 * \param Array de la eestructura Tipo
 * \param Tamaño del array de la estructura Tipo
 * \param Array de la estructura Marca
 * \param Tamaño del Array de la estructura marca
 * \return 0 si realizo el informe, 1 si no lo realizo
 *
 */
int marcaMasElegida(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca);

/** \brief Muestra todos los trabajos que se le hicieron a la notebook seleccionada
 *
 * \param Array de la estructura notebook
 * \param Tamao del array de la estructura Notebook
 * \param Array de la estructura Tipo
 * \param Tamaño del aray de la estructura Tipo
 * \param Array de la estructura Marca
 * \param Tamaño del Array de la estructura marca
 * \param Array de la estructura Trabajo
 * \param tamTrab inttamMarca inttamMarca int
 * \param Array de la estructura Servicio
 * \param Tamaño del array de la estructura servicio
 * \return 0 si realizo el informe, 1 si no lo realizo
 *
 */
int notebookYTrabajoCargado(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca, eTrabajo *trabajo, int tamTrab, eServicio *servicio, int tamSer);

/** \brief Muestra la suma de los importes de los services que se le hicieron a la notebook seleccionada
 *
 * \param Array de la estructura notebook
 * \param Tamao del array de la estructura Notebook
 * \param Array de la estructura Tipo
 * \param Tamaño del array de la estructura Tipo
 * \param Array de la estructura Marca
 * \param Tamaño del Array de la estructura marca
 * \param Array de la estructura Trabajo
 * \param Tamaño del array de la estructura Trabajo
 * \param Array de la estructura Servicio
 * \param Tamaño del array de la estructura servicio
 * \return 0 si realizo el informe, 1 si no lo realizo
 *
 */
int sumaDeSerViciosEnNotebook(eNotebook *notebook, int tam, eTipo *tipo, int tamTipo, eMarca *marca, int tamMarca, eTrabajo *trabajo, int tamTrab, eServicio *servicio, int tamSer);

/** \brief Muestra las notebooks a las que se realizó el servicio elegido y la fecha
 *
 * \param Array de la estructura Servicio
 * \param Tamaño del array de la estructura servicio
 * \param Array de la estructura Trabajo
 * \param Tamaño del array de la estructura Trabajo
 * \return 0 si realizo el informe, 1 si no lo realizo
 *
 */
int mostrarServicioElegido(eServicio *servicio, int tamSer, eTrabajo *trabajo, int tamTrab);

/** \brief Muestra todos los servicios realizados en la fecha indicada
 *
 * \param Array de la estructura Trabajo
 * \param Tamaño del array de la estructura Trabajo
 * \param Array de la estructura Servicio
 * \param Tamaño del array de la estructura servicio
 * \return 0 si realizo el informe, 1 si no lo realizo
 *
 */
int mostrarServiciosPorFecha(eTrabajo *trabajo, int tamTrab, eServicio *servicio, int tamSer);
