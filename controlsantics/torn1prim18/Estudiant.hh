#ifndef ESTUDIANT_HH
#define ESTUDIANT_HH

#include <iostream>
#include <vector>
using namespace std;


class Estudiant {

  // Tipus de mòdul: dades
  // Descripció del tipus: Permet representar el DNI d'un estudiant,
  // les seves notes en els exàmens parcials d'una assignatura, i la
  // seva nota global en aquesta assignatura.

  // La nota global i les notes dels exàmens parcials poden ser -1,
  // per indicar que la qualificació global de l'estudiant en
  // l'assignatura és NP (no presentat) o que l'estudiant no s'ha
  // presentat a un examen parcial, o un nombre real en el rang 
  // [0 ... nota_maxima()].
  

private:    
  int dni;
  vector<double> notes_parcials;
  double nota_global; 
  const static int MAX_NOTA = 10;

  /* 
     Invariant de la representació: 
     I) 0 <= dni
     II) nota_global == -1 o 0 <= nota_gobal <= MAX_NOTA 
     III) Si 0 <= j < notes_parcials.size(), llavors notes_parcials[j] == -1 o 0 <= notes_parcials[j] <= MAX_NOTA 
  */
  
    
public:

  //Constructors

  Estudiant();
  /* Pre: cert */ 
  /* Post: Crea un objecte de la classe Estudiant amb DNI = 0 i sense
     notes. */

  Estudiant(int n);
  /* Pre: n >= 0 */  
  /* Post: Crea un objecte de la classe Estudiant amb DNI = 0 i amb
     capacitat per a emmagatzemar les notes de n exàmens parcials. */



  // Modificadors

  void modificar_nota_parcial(int i, double n);
  /* Pre: 1 <= i <= nombre_notes_parcials() 
     n == -1 o 0 <= n <= nota_maxima() */
  /* Post: La nota del i-èsim examen parcial del paràmetre implícit
     passa a ser n. */
   
  void assignar_nota_global(double n);
  /* Pre: n == -1 o 0 <= n <= nota_maxima() */
  /* Post: La nota global del paràmetre implícit passa a ser n. */
                                    

  
  // Consultors

  int consultar_DNI() const;
  /* Pre: cert  */
  /* Post: El resultat és el DNI del paràmetre implícit. */

  double consultar_nota_parcial(int i) const;
  /* Pre: 1 <= i <= nombre_notes_parcials() */
  /* Post: El resultat és la nota de l'i-èsim examen parcial del
     paràmetre implícit. Si el resultat és -1, significa que
     l'estudiant que representa el paràmetre implícit no s'ha 
     presentat a l'i-èsim examen parcial de l'assignatura. */

  double consultar_nota_global() const;
  /* Pre: cert */
  /* Post: El resultat és la nota global del paràmetre implícit. Si el
     resultat és -1, significa que la qualificació gloabl de
     l'estudiant en la assignatura és NP (no presentat). */

  static double nota_maxima();
  /* Pre: cert */
  /* Post: El resultat és el valor màxim permès per a les notes dels
     exàmens parcials i la nota global dels elements de la classe. */

  int nombre_notes_parcials() const;
  /* Pre: cert  */  
  /* Post: El resultat és el nombre de notes d'exàmens parcials que
     pot emmagatzemar el paràmetre implícit. */

  static bool menor_dni(const Estudiant& e1, const Estudiant& e2);
  /* Pre: cert  */
  /* Post: El resultat és cert si el dni d'e1 és menor que el dni
     d'e2. */
  


  // Lectura i escriptura

  void llegir();
  /* Pre: Hi ha preparats al canal estandar d'entrada un enter no negatiu 
     i nombre_notes_parcials() doubles. */
  /* Post: El paràmetre implícit passa a tenir els atributs llegits
     del canal estàndard d'entrada. Si el i-èsim double no pertany a
     l'interval [0..nota_maxima ()], la nota del i-èsim parcial del
     paràmetre implícit passa a ser -1. */

  void escriure() const;
  /* Pre: cert */
  /* Post: S'han escrit els atributs del paràmetre implícit al canal
     estàndard de sortida. Si la nota global o la nota de l'examen
     parcial i-èsim del paràmetre implícit és -1, escriu "NP" per
     indicar-ho. */
};
#endif
