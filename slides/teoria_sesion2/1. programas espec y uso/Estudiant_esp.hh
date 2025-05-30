class Estudiant {

  // Tipus de m�dul: dades

  // Descripci� del tipus: cont� el DNI d'un estudiant, que �s un enter
  // no negatiu, i pot tenir nota, que seria un double

  // Atenci�: les notes v�lides s�n les de l'interval 0..nota_maxima()

private: // aquesta part s'omplir� a la implementaci�

public:

  //Constructores

  Estudiant();
  /* Pre: cert */ 
  /* Post: el resultat �s un estudiant amb DNI=0 i sense nota */

  Estudiant(int dni);
  /* Pre: dni >= 0 */ 
  /* Post: el resultat �s un estudiant amb DNI=dni i sense nota */

  // Destructora: esborra autom�ticament els objectes locals en sortir 
  // d'un �mbit de visibilitat

  ~Estudiant();

  //Modificadores

  void afegir_nota(double nota)
  /* Pre: el par�metre impl�cit no t� nota, 0 <= "nota" <= nota_maxima() */
  /* Post: la nota del par�metre impl�cit passa a ser "nota" */
   
  void modificar_nota(double nota);
  /* Pre: el par�metre impl�cit t� nota, 0 <= "nota" <= nota_maxima() */
  /* Post: la nota del par�metre impl�cit passa a ser "nota" */
                                    
  //Consultores

  int consultar_dni() const;
  /* Pre: cert  */
  /* Post: el resultat �s el DNI del par�metre impl�cit */

  double consultar_nota() const;
  /* Pre: el par�metre impl�cit t� nota */
  /* Post: el resultat �s la nota del par�metre impl�cit */

  static double nota_maxima();
  /* Pre: cert */
  /* Post: el resultat �s la nota m�xima dels elements de la classe */
 
  bool te_nota()  const;
  /* Pre: cert  */
  /* Post: el resultat indica  si el par�metre impl�cit t� nota o no */

  // Lectura i escriptura

  void llegir();
  /* Pre: hi ha preparats al canal estandar d'entrada un enter no negatiu
     i un double */
  /* Post: el par�metre impl�cit passa a tenir els atributs llegits del
     canal est�ndard d'entrada; si el double no pertany a l'interval 
     [0 .. nota_maxima()], el p.i. es queda sense nota */

  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit els atributs del par�metre impl�cit al canal
     est�ndard de sortida */
};
