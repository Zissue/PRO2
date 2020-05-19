/** @mainpage Práctica PRO2:  Codificación y decodificación de palabras en varios idiomas. Documentación.
 
	Este es un programa modular que permite codificar y decodificar palabras en varios idiomas. 
	Se introducen las clases <em>Treecode</em>, <em>Tabla</em>, <em>Idioma</em> y <em>Cjt_idiomas</em>.

	La codificación que se utilizará estará compuesta <b>exclusivamente</b> por ceros y unos.
	En lo que afecta a este trabajo, un idioma se define por un <b>identificador</b> (<em>string</em>) y 
	una <b>tabla de frecuencias</b> (una colección de caracteres o sı́mbolos, cada uno de ellos con su 
	correspondiente frecuencia en el idioma).
	El método propuesto se basa en asignar un pequeño código (en concreto, una <em>string</em> formada
	por ceros y unos) a cada carácter del idioma correspondiente, de forma que bajo ciertas condiciones
	dicha asignación sea reversible, es decir, que si se detecta dicho código en una <em>string</em> 
	más grande se pueda obtener el carácter original.
	
	Se documentan elementos públicos y privados.
*/

/** @file program.cc
 * 
	@brief <b>Programa principal</b> para todo el repertorio
	de funcionalidades (<em>codificación</em>, <em>decodificación</em>, etc).
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
		

#include "Cjt_idiomas.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

/** @brief Programa principal para todo el repertorio 
	de funcionalidades (<em>codificación</em>, <em>decodificación</em>,etc).
*/

int main () 
{
	
	// n es el num de idiomas que leera
	int n;
	cin >> n;
	
	// se construye un conjunto que contiene los n idiomas
	Cjt_idiomas cid;
	cid.leer(n);
	
	string op;		// op es la operacion que se quiera hacer
	
	while (cin >> op and op != "fin") 	// si op es el codigo de "acabar", termina el programa
	{

		// anadir/modificar idioma
		if (op == "anadir/modificar") 
		{
			string id;
			cin >> id;

			cid.update_cjt(id);
		}

		// codifica
		else if (op == "codifica") 
		{
			string texto, id;
			cin >> id >> texto;

			cid.codifica(id, texto);
		}

		// decodifica
		else if (op == "decodifica") 
		{
			string texto, id;
			cin >> id >> texto;

			cid.decodifica(id, texto);
		}

		// consultar tabla de frecuencias
		else if (op == "tabla_frec") 
		{
			string id;
			cin >> id;

			cid.cons_chart(id);
		}

		// consultar treecode
		else if (op == "treecode") 
		{
			string id;
			cin >> id;

			cid.cons_treecode(id);
		}

		// consultar codigos
		else if (op == "codigos") 
		{
			string id;
			cin >> id;

			cid.cons_codigos(id);
		}
	}
}
