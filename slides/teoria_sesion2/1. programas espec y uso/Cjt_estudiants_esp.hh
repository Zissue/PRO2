#include "Estudiant.hh"

class Cjt_estudiants {

  // Representa un conjunt d'estudiants ordenat per DNI.  

  // Es poden consultar i modificar els seus elements per DNI o per
  // posició a l'ordre.

private:

public:

  //Constructora

  Cjt_estudiants();   // se usa al declarar:  Cjt_estudiants c;
  /* Pre: cert */
  /* Post: el resultat és un conjunt d'estudiants buit */
  /* Cost temporal: lineal respecte mida_maxima() */

  //Destructora

  ~Cjt_estudiants();
  /* Cost temporal: lineal respecte mida_maxima() */

  //Modificadores

  void afegir_estudiant(const Estudiant &est);
  /* Pre: el paràmetre implícit no conté cap estudiant amb el DNI d'est; el 
     nombre d'elements del p.i. és menor que la mida màxima permesa */
  /* Post: s'ha afegit l'estudiant est al paràmetre implícit */
  /* Cost temporal: lineal respecte mida() */

  void modificar_estudiant(const Estudiant &est);
  /* Pre: existeix un estudiant al paràmetre implícit amb el DNI d'est */
  /* Post: l'estudiant del p.i. amb el dni d'est, ha quedat substituït
     per est */
  /* Cost temporal: logaritmic respecte mida() */
		
  void modificar_iessim(int i, const Estudiant &est);
  /* Pre: 1 <= i <= nombre d'estudiants del paràmetre implícit,
     l'element i-èssim del p.i. en ordre creixent per DNI conté un
     estudiant amb el mateix DNI que est */
  /* Post: l'estudiant est ha substituït l'estudiant i-èssim del
     paràmetre implícit */
  /* Cost temporal: constant */ 

  //Consultores
	
  int mida() const;
  /* Pre: cert */
  /* Post: el resultat és el nombre d'estudiants del paràmetre implícit */
  /* Cost temporal: constant */ 

  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat és el nombre maxim d'estudiants que pot arribar
     a tenir el paràmetre implícit */
  /* Cost temporal: constant */ 

  bool existeix_estudiant(int dni) const;
  /* Pre: dni > 0 */
  /* Post: el resultat indica si existeix un estudiant al paràmetre
     implícit amb DNI = dni */
  /* Cost temporal: logaritmic respecte mida() */ 

  Estudiant consultar_estudiant(int dni) const;
  /* Pre: existeix un estudiant al paràmetre implícit amb DNI = dni */
  /* Post: el resultat és l'estudiant amb DNI = dni que conté el
     paràmetre implícit */
  /* Cost temporal: logaritmic respecte mida() */ 

  Estudiant consultar_iessim(int i) const;
  /* Pre: 1 <= i <= nombre d'estudiants que conté el paràmetre implícit */
  /* Post: el resultat és l'estudiant i-èssim del p.i. en ordre
     creixent per DNI */
  /* Cost temporal: constant */ 

  // Lectura i escriptura
	
  void llegir();
  /* Pre: cert */
  /* Post: el paràmetre implícit conté el conjunt d'estudiants llegits
     del canal estàndard d'entrada */
  /* Cost temporal: d'ordre n log n on n és mida() */ 

  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal estàndard de sortida els estudiants
     del paràmetre implícit en ordre ascendent per DNI */
  /* Cost temporal: lineal respecte mida() */
};
