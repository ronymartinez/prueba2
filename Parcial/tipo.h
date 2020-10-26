#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int idTipo; // comienza en 5,000
    char descripcion[20];
} eTipo;

#endif // TIPO_H_INCLUDED

/** \brief Reemmplaza el ID del tipo por su descripcion
 *
 * \param Nombre de la descripcion
 * \param Array de la estructura Tipo
 * \param Tamaño del Array de la estructura Tipo
 * \param ID del tipo a reemplazar
 * \return 0 si realizo el reemplazo, 1 si no reemplazo
 *
 */
int cargarTipo (char *nombreTipo, eTipo *tipo, int tamTipo, int idTipo);

/** \brief Lista todos los tipos cargados
 *
 * \param Array de la estructura Tipo
 * \param Tamaño del Array de la estructura Tipo
 * \return 0 si pudo listar, 1 si no lo hizo
 *
 */
int listarTipos(eTipo *tipo, int tamTipo);


