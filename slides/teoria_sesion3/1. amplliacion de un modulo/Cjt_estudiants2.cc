#include "Cjt_estudiants.hh"
#include <algorithm>

// només mostrem les operacions noves, però quasi bé totes han de 
// modificar-se una mica per adaptar-se al nou camp imax

...

void Cjt_estudiants::esborrar_estudiant(int dni)
/* Pre: existeix un estudiant al paràmetre implícit amb DNI = dni */
/* Post: el paràmetre implícit conté els mateixos estudiants que
   l'original menys l'estudiant amb DNI = dni */
{
  int i = 0;
  while (dni != vest[i].consultar_DNI())  ++i;
 
  // per la pre, segur que trobarem a Cest un estudiant amb DNI = dni;
  // en aquest punt del programa, aquest estudiant és vest[i];
  // ara desplacem els elements següents per ocupar el lloc de vest[i],
  // actualitzem la mida i mirem si s'ha d'actualitzar imax
 
  for (int j = i; j < nest - 1; ++j) vest[j] = vest[j + 1];
  --nest; 
  if (i == imax) recalcular_posicio_imax();
  else if (imax > i) --imax;
}
 
Estudiant Cjt_estudiants::estudiant_nota_max( ) const
/* Pre: el paràmetre implícit conté almenys un estudiant amb nota */
/* Post: el resultat és l'estudiant del paràmetre implícit amb nota
   màxima; si en té més d'un, és el de DNI més petit */
{
  return vest[imax];
}

// Exercici: implementar recalcular_posicio_imax() i les altres
// operacions auxiliars, i modifiqueu la resta d'operacions per
// inicialitzar i mantenir actualitzat l†¢atribut imax.
