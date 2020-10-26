#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int idMarca; // comienza en 1,000
    char descripcion[20];
} eMarca;


#endif // MARCA_H_INCLUDED

/** \brief Reemplaza el ID de la marca por su nombre
 *
 * \param Nombre en donde se guardara la marca
 * \param Array de la Estructura de la marca
 * \param Tamaño del array de la estructura marca
 * \param ID de la marca a reemplazar
 * \return 0 si pudo realizar el reemplazo, 1 si no lo hace
 *
 */
int cargarMarca(char *nombreMarca, eMarca *marca, int tamMarca, int idMarca);

/** \brief Lista las marcas existentes
 *
 * \param Array de la Estructura marca
 * \param Tamaño del array de la estructura marca
 * \return 0 si pudo hacer el listado, 1 si no lo logra
 *
 */
int listarMarcas(eMarca *marca, int tamMarca);
