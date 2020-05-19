/** @file Tabla.hh
    @brief Especificación de la clase Tabla
*/

#ifndef _TABLA_
#define _TABLA_

#ifndef NO_DIAGRAM 

#include <map>
#include <iostream>

#endif

using namespace std;

/*
 * Clase Tabla
 */

/** @class Tabla
    @brief Representa una tabla de frecuencias cualquiera y sus operaciones
        
        Tipo de módulo: Datos 
        
        Descripción del tipo: Contiene la tabla de frecuencias, el identificador 
        del idioma
*/

class Tabla {

    // Descripción: 
    // Contiene la tabla de frecuencias
    // y sus respectivas operaciones

private:

    // Campos del parámetro implícito //

/** @brief Conjunto de idiomas ordenados crecientemente alfabéticamente por su nombre */
    map<string, int> chart;


    // Operaciones privadas //
    
/** @brief Comprueba si existe un carácter en la tabla del idioma o no
    @pre <em>Cierto</em>
    @post Devuelve <em>true</em> si existe; <em>false</em> de lo contrario
*/
    bool exist_char(const string& s);


public:

    // Constructoras //

/** @brief Constructora vacía por defecto
    @pre <em>Cierto</em>
    @post Crea una tabla de frecuencias vacía en el p.i.
*/
    Tabla();

    // Modificadoras //

/** @brief Mezcla las tablas de frecuencia del p.i. y del parámetro explícito
    @pre <em>Cierto</em>
    @post Fusiona las tablas de frecuencia y queda guardado en el p.i.
*/
    void merge_chart(Tabla& nueva);


    // Entrada / Salida //

/** @brief Lee <em>n</em> pares de caracteres (<em>string</em>) y enteros
    @pre <em>n >= 2</em> (por el enunciadode la práctica)
    @post Los pares quedan guardados como tabla de frecuencias en el p.i.
*/
    void leer();

/** @brief Escribe toda la tabla de frecuencias del p.i.
    @pre  <em>Cierto</em>
    @post Se escribe toda la tabla de frecuencias por el canal de salida estándar
*/
    void escribir();


    // Consultoras //

/** @brief Consulta el par al cual apunta el iterador del parámetro
    @pre <em>it</em> no apunta al <em>end()</em> del p.i.
    @post Devuelve el par al cual apunta el iterador <em>it</em> del p.i.
*/
    pair<string, int> cons_it_esim(map<string, int>::const_iterator it) const;

/** @brief Consulta el iterador que apunta a la primera posición de la tabla
        de frecuencias del p.i.
    @pre <em>Cierto</em>
    @post Devuelve el <em>begin()</em> del p.i.
*/
    map<string, int>::iterator cons_it_begin();

/** @brief Consulta el iterador que apunta a la última posición de la tabla
        de frecuencias del p.i.
    @pre <em>Cierto</em>
    @post Devuelve el <em>end()</em> del p.i.
*/
    map<string, int>::iterator cons_it_end();

/** @brief Consulta el tamaño de la tabla de frecuencias del p.i.
    @pre <em>Cierto</em>
    @post Devuelve el tamaño de la tabla de frecuencias del p.i.
*/
    int size() const;


};
#endif