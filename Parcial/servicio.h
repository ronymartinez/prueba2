#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int idServicio; //comienza en 20,000
    char descripcion[25];
    float precio;
} eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief Lista los servicios registrados
 *
 * \param Array de la Estructura Servicio
 * \param Tamaño del array de la estructura servicio
 * \return 0 si pudo listar, 1 si no listo
 *
 */
int listarServicios(eServicio *servicio, int tamSer);

/** \brief Reemplaza el ID del servicio por su descripcion
 *
 * \param Nombre de la descripcion
 * \param Array de la estructura servicio
 * \param Tamaño del array de la estructura servicio
 * \param ID del servicio a reemplazar
 * \return 0 si pudo realizar el reemplazo, 1 si no reemplazo
 *
 */
int cargarServicio(char *nombreServicio, eServicio *servicio, int tamSer, int idServicio);
