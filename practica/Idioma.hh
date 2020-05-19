/** @file Idioma.hh
    @brief Especificación de la clase Idioma
*/

#ifndef _IDIOMA_
#define _IDIOMA_

#include "Treecode.hh"

#ifndef NO_DIAGRAM

#include <map>
#include <iostream>

#endif

using namespace std;

/*
 * Clase Idioma
 */

/** @class Idioma
    @brief Representa un idioma con sus atributos y las operaciones asociadas a éste
        
        Tipo de módulo: Datos 
        
        Descripción del tipo: Contiene la tabla de frecuencias, el 
        treecode y los códigos
*/

class Idioma {

    // Descripción: 
    // Contiene las características de un idioma: 
    // tabla de frecuencias, treecode y los códigos del idioma;
    // y sus métodos

private:

    // Campos del parámetro implícito //

/** @brief Tabla de frecuencias del idioma */
    Tabla freqchart;

/** @brief Treecode del idioma */
    Treecode treecode;

/** @brief Códigos del abecedario */
    map<string, string> codigos;


    // Operaciones privadas //

/** @brief Extrae el carácter de <em>s</em> en la posición <em>i</em>; <em>i</em> 
        queda en la posición del siguiente carácter de <em>s</em>
    @pre <em>i >= 0</em> y es una posición válida de <em>s</em>;   
        también <em>s.length() > 0</em>
    @post Devuelve el carácter como <em>string</em> de la posición <em>i</em>; 
        si <em>s[i]</em> es un carácter especial <em>I = i+2</em>, de lo contrario 
        <em>I = i+1</em>
*/
    static string next_symbol(const string& s, int& i);

/** @brief Actualiza los códigos del idioma
    @pre <em>Cierto</em>
    @post Queda actualizado <em>codigos</em> del p.i.
*/
    void update_codigos();

/** @brief Actualiza el treecode del idioma
    @pre <em>Cierto</em>
    @post Se vuelve a contruir el <em>treecode</em> del p.i.
*/
    void update_treecode(Tabla& nueva);


public:

    // Constructoras //

/** @brief Constructora vacía por defecto
    @pre <em>Cierto</em>
    @post Crea un idioma con los atributos privados del p.i. vacíos
*/
    Idioma();

/** @brief Constructora dado una tabla de frecuencias
    @pre <em>chart</em> con al menos dos caracteres y su frecuencia
    @post Crea un idioma con la tabla; asimismo también se 
        construye el treecode y se crean los códigos del idioma
*/
    Idioma(Tabla& chart);


    // Modificadoras //

/** @brief Se suma la nueva tabla con la tabla de p.i.; posteriormente 
        actualiza <em>codigos</em> y <em>treecode</em>
    @pre <em>Cierto</em>
    @post <em>freqchart</em> del p.i. queda sumada; <em>treecode</em> 
        y <em>codigos</em> son generados de nuevo
*/
    void sumar_tablas(Tabla& nueva);


    // Entrada / Salida //


    // Consultoras //

/** @brief <em>text</em> se codificará en el idioma del p.i.
    @pre <em>text</em> perteneciente al idioma del p.i.
    @post Devuelve la codificación de <em>text</em> por el 
        canal de salida estándar
*/
    void cout_codifica(const string& text);

/** @brief Escribe la tabla de frecuencias del idioma del p.i.
    @pre <em>Cierto</em>
    @post Se ha escrito la tabla de frecuencias por el canal 
        de salida estándar
*/
    void escribir_tabla();

/** @brief Escribe el <em>treecode</em> del idioma en preorden 
        e inorden
    @pre <em>Cierto</em>
    @post Se han escrito los nodos en preorden e inorden por 
        el canal de salida estándar
*/
    void escribir_treecode();

/** @brief Escribe todos los códigos correspondientes a cada carácter
    @pre <em>Cierto</em>
    @post Escribe por el canal estándar de salida los códigos
*/
    void escribir_codigos() const;

/** @brief Escribe el código correspondiente al carácter del 
        parámetro
    @pre <em>c</em> pertenece al idioma
    @post Escribe por el canal estándar de salida el código del carácter
*/
    void escribir_char_cod(const string& c) const;

/** @brief Comprueba si un carácter pertenece al idioma
    @pre <em>Cierto</em>
    @post Devuelve <em>cierto</em> si pertenece; <em>false</em> de lo contrario
*/
    bool cons_char(const string& c);

/** @brief Devuelve un par <em>bool</em> <em>string</em>; 
        es <em>true</em> si el texto pertenece al idioma, de lo contrario 
        <em>false</em> y el primer carácter que falla
    @pre <em>text</em> es una <em>string</em> no vacía
    @post El <em>first</em> es <em>true</em> y <em>second</em> es <em>""</em> si se 
        puede codificar el texto; de lo contrario <em>first</em> 
        es <em>false</em> y <em>second</em> es una <em>string</em> 
        del primer carácter no perteneciente al idioma
*/
    pair<bool, string> belong_text(const string& text);

/** @brief Devuelve un par <em>bool</em> <em>int</em>;
        es <em>true</em> si el texto pertenece al idioma y en el parámetro
        <em>decoded</em> queda la decodificación hecha; de lo contrario
        <em>false</em> y la posición del último decodificado correctamente
    @pre <em>decoded</em> string vacía y <em>text</em> string no vacía
    @post El <em>first</em> del par resultante es <em>true</em> y <em>second</em>
        es <em>-1</em> si se ha decodificado con éxito; de lo contrario
        <em>first</em> es <em>false</em> y <em>second</em> es la última posición 
        del texto correspondiente al último carácter decodificado correctamente
*/
    pair<bool, int> belong_and_decode(const string& text, string& decoded) const;


};
#endif