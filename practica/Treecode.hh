/** @file Treecode.hh
@brief Especificación de la clase Treecode 
*/

#ifndef _TREECODE_
#define _TREECODE_

#ifndef NO_DIAGRAM 

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <list>
#include "BinTree.hh"

#endif

#include "Tabla.hh"

using namespace std;

/*
* Clase Treecode
*/

/** @class Treecode
    @brief Representa el treecode y las operaciones aplicadas a éste
    
        Tipo de módulo: Datos 
        
        Descripción del tipo: Representa el treecode y
        contiene lista de nodos en preorden e inorden
*/

class Treecode {

    // Descripción: 
    // Contiene el treecode, y dos listas
    // con los nodos en preorden e inorden

private:

    // Campos del parámetro implícito //

/** @brief Treecode */
    BinTree< pair<string,int> > arbol;

/** @brief Lista que contiene los nodos del treecode recorrido en preorden */
    list< pair<string,int> > lpre;

/** @brief Lista que contiene los nodos del treecode recorrido en inorden */
    list< pair<string,int> > lin;


    // Operaciones privadas //

/** @brief Guarda los nodos en preorden del árbol del parámetro en una lista
    @pre <em>Cierto</em>
    @post La lista resultante contiene los nodos de <em>a</em> en preorden
*/
    static list< pair<string,int> > preorder(const BinTree< pair<string,int> >& a);

/** @brief Guarda los nodos en inorden del árbol del parámetro en una lista
    @pre <em>Cierto</em>
    @post La lista resultante contiene los nodos de <em>a</em> en inorden
*/
    static list< pair<string,int> > inorder(const  BinTree< pair<string,int> >& a);
    
/** @brief Transforma la tabla de frecuencias en nodos hoja y lo guarda en el conjunto
        del parámetro
    @pre <em>Cierto</em>
    @post Quedan guardados los nodos hoja en <em>aux</em> de la tabla <em>t</em>
*/
    static void transformNodes(Tabla& t, set< BinTree< pair<string, int> > >& aux);

/** @brief Suma dos pares <em>string</em> <em>int</em> según el criterio de la 
        práctica
    @pre <em>p1.second</em> y <em>p2.second</em> inicializados 
        (con algún valor)
    @post El <em>first</em> del par resultante es la concatenación 
        en orden lexicográfico de <em>p1</em> y <em>p2</em>; 
        el <em>second</em> es la suma de los enteros de 
        <em>p1</em> y <em>p2</em>
*/
    static pair<string, int> sumPairs(const pair<string, int>& p1, const pair<string, int>& p2);

/** @brief Decodifica un texto con el árbol binario del parámetro; 
        <em>pos</em> es la última posición decodificada correctamente
    @pre <em>0 <= i < text.length()</em> y <em>0 <= pos < text.length()</em>; 
        <em>decoded</em> es la decodificación hasta la posición 
        <em>pos</em>
    @post La decodificación queda en <em>decoded</em>, <em>pos</em> 
        es la última posición decodificada correctamente
*/
    void decodificar(const string& text, int& i, int& pos, string& decoded, const BinTree< pair<string, int> >& a) const;

/** @brief Codifica un carácter (especial o común) con el camino 
        (0 = izquierda, 1 = derecha) del árbol del parámetro 
    @pre <em>x</em> es codificable (carácter existente en algún nodo hoja)
    @post La codificación de <em>x</em> se guarda en <em>s</em> del 
        parámetro
*/
    static string codemaker(const string& x, const BinTree< pair<string, int> >& a, string& s);

/** @brief Comprueba si <em>x</em> del parámetro se encuentra en el 
        <em>first</em> del par de algún nodo hoja del árbol <em>a</em>
    @pre <em>Cierta</em>
    @post Devuelve <em>true</em> si <em>x</em> se encuentra en 
        <em>a</em>; <em>false</em> de lo contrario
*/
    static bool cerca(const BinTree< pair<string, int > >& a, const string& x);


public:

    // Constructoras //

/** @brief Constructora vacía por defecto 
    @pre <em>Cierto</em>
    @post Se genera un <em>treecode</em> vacío
*/
    Treecode();

/** @brief Constructora dado una tabla de frecuencias
    @pre <em>Cierto</em>
    @post Se genera el treecode del p.i. correspondiente a la tabla 
        de frecuencias (<em>tablaf</em>) y las listas preorden e 
        inorden del p.i.
*/
    Treecode(Tabla& nueva);


    // Modificadoras //

/** @brief Construye el <em>treecode</em> del idioma 
    @pre <em>Cierto</em>
    @post Queda construido el <em>treecode</em> en <em>arbol</em> del p.i. 
       a partir de la tabla del parámetro
*/
    void buildTreecode(Tabla& t);

/** @brief Actualiza las listas de los nodos en preorden e inorden
    @pre <em>Cierto</em>
    @post <em>lpre</em> y <em>lin</em> del p.i. quedan actulizados
*/
    void update_orders();


    // Entrada / Salida //

/** @brief Escribe una de las lista del p.i. según el parámetro
    @pre <em>orden</em> del parámetro vale <em>"preorder"</em> 
        o <em>"inorder"</em>
    @post Escribe por el canal estándar de salida los nodos
        en preorden o en inorden
*/
    void writelist(const string& orden);


    // Consultoras //

/** @brief Devuelve un par <em>string</em> <em>int</em>; sirve 
        para consultar la decodificación de un texto y la última posición
        decodificada correctamente
    @pre <em>text</em> no es vacío
    @post Devuelve la decodificación en el <em>first</em> y la última 
        posición decodificación realizada en el <em>second</em>
*/
    pair<string, int> decode(const string& text) const;

/** @brief Codifica un carácter (especial o común) con el árbol del p.i.
    @pre <em>character</em> del parámetro existe en algún nodo hoja 
        del <em>treecode</em>
    @post Devuelve la decodificación del carácter (especial o común) del parámetro
*/
    string code_char(const string& character);
    

};
#endif