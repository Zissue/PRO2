/** @file Cjt_idiomas.hh
    @brief Especificación de la clase Cjt_idiomas
*/

#ifndef _CJT_IDIOMAS_
#define _CJT_IDIOMAS_

#include "Idioma.hh"

#ifndef NO_DIAGRAM

#include <map>
#include <iostream>

#endif

using namespace std;

/*
 * Clase Cjt_idiomas
 */

/** @class Cjt_idiomas
    @brief Representa un conjunto de idiomas con sus respectivos métodos/operaciones

        Tipo de módulo: Datos 
        
        Descripción del tipo: Contiene el conjunto de idiomas

*/

class Cjt_idiomas {

    // Descripción: 
    // Contiene un conjunto de idiomas
    // y sus respectivas operaciones

private:
    
    // Campos del parámetro implícito //
    
/** @brief Conjunto de idiomas ordenados de manera alfabéticamente creciente por su nombre */
    map<string, Idioma> cidiomas;
    

    // Operaciones privadas //

/** @brief Modifica un idioma sumando la nueva tabla de frecuencias leída
    @pre <em>lang</em> ya existente en <em>cidiomas</em> del p.i.
    @post El idioma <em>lang</em> queda modificado con la suma de las tablas de 
        frecuencias
*/
    void mod_idioma(const string& lang);

/** @brief Lee una tabla de frecuencias, se construye un idioma a partir de él; el idioma 
        queda añadido al map del p.i. con el nombre del parámetro de llave
    @pre <em>Cierto</em>
    @post El idioma <em>lang</em> queda añadido en <em>cidiomas</em> del p.i.
*/
    void add_idioma(const string& lang);

/** @brief Se busca por el nombre de idioma si éste se encuentra en el map del p.i.
    @pre <em>Cierto</em>
    @post Devuelve <em>true</em> si el idioma <em>id</em> pertenece al <em>cidiomas</em>
*/
    bool exist_idioma(const string& lang);


public: 

    // Constructoras //
    
/** @brief Constructora vacía por defecto
    @pre <em>Cierto</em>
    @post Crea un conjunto vacío de idiomas
*/
    Cjt_idiomas();


    // Modificadoras //
    
/** @brief Actualiza el conjunto de idiomas; modifica o añade un idioma según 
        la existencia del idioma
    @pre <em>Cierto</em>
    @post El idioma <em>lang</em> queda modificado o añadido al <em>cidiomas</em> del p.i.
*/
    void update_cjt(const string& lang);
    

    // Entrada / Salida //

/** @brief Lee por el canal de entrada estándar <em>n</em> idiomas 
        y los añade al conjunto de idiomas del p.i.
    @pre <em>n</em> > 0
    @post Los <em>n</em> idiomas quedan añadidos al <em>cidiomas</em> del p.i.
*/
    void leer(int n);


    // Consultoras //
    
/** @brief Si el texto pertenece al idioma del parámetro y al conjunto, se obtendra 
        su codificació; en otro caso se avisa por el canal de salida estándar 
        (no existe el idioma o el primer carácter que falla)
    @pre <em>Cierto</em>
    @post Si se codifica correctamente se escribe la codificación por el canal de 
        salida estándar; contrariamente avisa por el canal de salida estándar 
        si el texto no pertenece al idioma o el primer carácter que falla
*/
    void codifica(const string& lang, const string& text);

/** @brief Si el texto pertenece al idioma del parámetro y al conjunto, se obtendra 
        su decodificación; de lo contrario se avisa por el canal de salida estándar 
        (no existe el idioma o la última posición decodificada correctamente)
    @pre <em>Cierto</em>
    @post Si se decodifica correctamente, escribe la decodificación por el canal de 
        salida estándar; de lo contrario avisa por el canal de salida estándar 
        si el texto no pertenece al idioma o la última posición decodificada 
        correctamente
*/
    void decodifica(const string& lang, const string& text);

/** @brief Si el idioma <em>lang</em> existe, escribe por el canal de salida estándar 
        la tabla de frecuencias de <em>lang</em>; 
        en otro caso se avisa por el canal de salida estándar 
    @pre <em>Cierto</em>
    @post Escribe la tabla de frecuencias por el canal de salida estándar; 
        si no existe <em>lang</em> se avisa por el canal estándar de salida
*/
    void cons_chart(const string& lang);

/** @brief Si el idioma existe, consulta su treecode; contrariamente
        se avisa por el canal de salida estándar 
    @pre <em>Cierto</em>
    @post Escribe el treecode por el canal estándar de salida en preorden e inorden; 
        si no existe <em>lang</em> se avisa por el canal estándar de salida
*/
    void cons_treecode(const string& lang);

/** @brief Consulta los códigos (todos o únicamente un solo carácter) del idioma 
        <em>lang</em>; si no existe el idioma se avisa por el canal 
        de salida estándar 
    @pre <em>Cierto</em>
    @post Escribe los códigos de <em>lang</em> por el canal estándar de salida; 
        si no existe <em>lang</em> se avisa por el canal estándar de salida
*/
    void cons_codigos(const string& lang);


};
#endif