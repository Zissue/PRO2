#include "Estudiant.hh"

class Cjt_estudiants {

  // Representa un conjunt d'estudiants ordenat per DNI.  

  // Es poden consultar i modificar els seus elements per DNI o per
  // posici� a l'ordre.

private:

public:

  //Constructora

  Cjt_estudiants();   // se usa al declarar:  Cjt_estudiants c;
  /* Pre: cert */
  /* Post: el resultat �s un conjunt d'estudiants buit */
  /* Cost temporal: lineal respecte mida_maxima() */

  //Destructora

  ~Cjt_estudiants();
  /* Cost temporal: lineal respecte mida_maxima() */

  //Modificadores

  void afegir_estudiant(const Estudiant &est);
  /* Pre: el par�metre impl�cit no cont� cap estudiant amb el DNI d'est; el 
     nombre d'elements del p.i. �s menor que la mida m�xima permesa */
  /* Post: s'ha afegit l'estudiant est al par�metre impl�cit */
  /* Cost temporal: lineal respecte mida() */

  void modificar_estudiant(const Estudiant &est);
  /* Pre: existeix un estudiant al par�metre impl�cit amb el DNI d'est */
  /* Post: l'estudiant del p.i. amb el dni d'est, ha quedat substitu�t
     per est */
  /* Cost temporal: logaritmic respecte mida() */
		
  void modificar_iessim(int i, const Estudiant &est);
  /* Pre: 1 <= i <= nombre d'estudiants del par�metre impl�cit,
     l'element i-�ssim del p.i. en ordre creixent per DNI cont� un
     estudiant amb el mateix DNI que est */
  /* Post: l'estudiant est ha substitu�t l'estudiant i-�ssim del
     par�metre impl�cit */
  /* Cost temporal: constant */ 

  //Consultores
	
  int mida() const;
  /* Pre: cert */
  /* Post: el resultat �s el nombre d'estudiants del par�metre impl�cit */
  /* Cost temporal: constant */ 

  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat �s el nombre maxim d'estudiants que pot arribar
     a tenir el par�metre impl�cit */
  /* Cost temporal: constant */ 

  bool existeix_estudiant(int dni) const;
  /* Pre: dni > 0 */
  /* Post: el resultat indica si existeix un estudiant al par�metre
     impl�cit amb DNI = dni */
  /* Cost temporal: logaritmic respecte mida() */ 

  Estudiant consultar_estudiant(int dni) const;
  /* Pre: existeix un estudiant al par�metre impl�cit amb DNI = dni */
  /* Post: el resultat �s l'estudiant amb DNI = dni que cont� el
     par�metre impl�cit */
  /* Cost temporal: logaritmic respecte mida() */ 

  Estudiant consultar_iessim(int i) const;
  /* Pre: 1 <= i <= nombre d'estudiants que cont� el par�metre impl�cit */
  /* Post: el resultat �s l'estudiant i-�ssim del p.i. en ordre
     creixent per DNI */
  /* Cost temporal: constant */ 

  // Lectura i escriptura
	
  void llegir();
  /* Pre: cert */
  /* Post: el par�metre impl�cit cont� el conjunt d'estudiants llegits
     del canal est�ndard d'entrada */
  /* Cost temporal: d'ordre n log n on n �s mida() */ 

  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal est�ndard de sortida els estudiants
     del par�metre impl�cit en ordre ascendent per DNI */
  /* Cost temporal: lineal respecte mida() */
};
