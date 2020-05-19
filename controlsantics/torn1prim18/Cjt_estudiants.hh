#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include "Estudiant.hh"


class Cjt_estudiants {

private:
 
  // Tipus de modul: dades 
 
  // Descripció del tipus: Representa un conjunt d'estudiants
  // matriculats en una assignatura ordenats per DNI. Es poden
  // consultar i modificar els seus elements (de tipus Estudiant)
  // donat un DNI o per posició en l'ordre. També conté informació
  // relativa als pesos dels diferents exàmens parcials en l'avaluació
  // global de l'assignatura.
    
  vector<Estudiant> vest;
  
  int nest; // nombre d'estudiants del paràmetre implícit
    
  static const int MAX_NEST = 20; // capacitat del paràmetre implícit
  
  int nombre_parcials; // nombre d'exàmens parcials del paràmetre implícit

  vector<double> pesos_parcials; // pesos dels exàmens parcials en la avaluació global de l'assignatura

  /*
    Invariant de la representació:
    I) vest[0..nest-1] està ordenat creixentment per DNI i no conté 
       dos estudiants amb el mateix DNI 
    II) 0 <= nest <= vest.size() = MAX_NEST
    III) pesos_parcials.size() = nombre_parcials
    IV) pesos_parcials[0] + ... + pesos_parcials[nombre_parcials - 1] = 1
    V) Per a tot 0 <= i <nest,
         a) vest [i].consultar_nota_global() == -1, si la suma dels pesos dels exàmens parcials als 
            quals vest[i] no s'ha presentat és més gran que 0.5; o
         b) vest[i].consultar_nota_global() == n, on 0 <= n <= Estudiant::nota_maxima(), n és igual
            a la suma de les contribucions a la nota global dels exàmens parcials als quals vest[i]
            s'ha presentat, i la contribució de cada examen parcial és la que s'indica en el vector
            pesos_parcials.
  */
  
  void ordenar_cjt_estudiants();
  /* Pre: cert */
  /* Post: Els estudiants de vest[0 ... nest - 1] estan ordenats en
     ordre creixent per DNI. */
    
  static int cerca_dicot(const vector<Estudiant>& v, int left, int right, int x);
  /* Pre: v.size() > 0, v[left...right] està ordenat en ordre creixent per DNI, 
     0 <= left <= v.size(), -1 <= right < v.size(), left <= right + 1. */
  /* Post: Si a v[left ... right] hi ha un estudiant amb DNI = x, el
     resultat és la posició que hi ocupa; si no, el resultat és -1. */


  // EXCERCICI
  void avaluacio_global_iesim(int i);
  /* Pre: 1 <= i <= mida(); 
     L'estudiant i-èsim té notes assignades per a tots els
     exàmens parcials de l'assignatura. La nota de cada examen parcial
     pot ser -1, si l'estudiant no s'ha presentat a aquest examen
     parcial, o una nota vàlida en el rang [0...Estudiant::nota_maxima()]. */
  /* Post: L'estudiant i-èsim passa a tenir assignada la seva nota
      global en l'assignatura, que pot ser -1, si es considera que la
      seva qualificació global ha de ser NP (no presentat), o una nota
      vàlida en el rang [0...Estudiant::nota_maxima()] que correspon a
      la suma ponderada de les seves notes en els exàmens parcials de
      l'assignatura als quals s'ha presentat. */

  
public:

  //Constructors

  Cjt_estudiants();
  /* Pre: cert */
  /* Post: Crea un conjunt d'estudiants buit. */

  Cjt_estudiants(int n);
  /* Pre: cert */
  /* Post: Crea un conjunt d'estudiants buit amb n exàmens parcials. */

    
  //Consultors
	
  int mida() const;
  /* Pre: cert */
  /* Post: El resultat és el nombre d'estudiants del paràmetre implícit. */

  static int mida_maxima();
  /* Pre: cert */
  /* Post: El resultat és el nombre màxim d'estudiants que pot arribar
     a tenir el paràmetre implícit. */

  int nombre_ex_parcials() const;
  /* Pre: cert */
  /* Post: El resultat és nombre d'exàmens parcials als quals es poden
     presentar els estudiants del paràmetre implícit. */
  
  double pes_parcial(int i) const;
  /* Pre: 1 <= i <= nombre d'exàmens parcials que conté el paràmetre implícit */
  /* Post: El resultat és el pes de l'i-èsim examen parcial del
     paràmetre implícit. */
  
  pair<bool, int> posicio_estudiant(int dni) const;
  /* Pre: cert */
  /* Post: Si existeix un estudiant al paràmetre implícit amb DNI =
     dni, la primera component del resultat és true i la segona és la
     posició que ocupa aquest estudiant en el paràmetre implícit en
     ordre ascendent per DNI; altrament la primera component del
     resultat és false i la segona -1. */
    
  Estudiant consultar_iesim(int i) const;
  /* Pre: 1 <= i <= nombre d'estudiants que conté el paràmetre implícit */
  /* Post: El resultat és l'estudiant i-èsim del paràmetre implícit en ordre 
     ascendent per DNI. */
    
  
  
    //Modificadors
        
  void modificar_iesim(int i, const Estudiant& e);
  /* Pre: 1 <= i <= nombre d'estudiants del paràmetre implícit, l'element 
     i-èsim del conjunt en ordre ascendent per DNI conté un estudiant amb 
     el mateix DNI que e. */
  /* Post: L'estudiant e ha substituït l'estudiant i-èsim del paràmetre 
     implícit. */



  
  // EXCERCICI
  void parcials_presentats_aprovats() const;
  /* Pre: Tots els estudiants del paràmetre implícit tenen notes
   assignades per a tots els exàmens parcials i també tenen assignada
   la seva nota global en l'assignatura. La nota de cada examen
   parcial pot ser -1, si l'estudiant no s'ha presentat a aquest
   examen parcial, o una nota vàlida en el rang
   [0...Estudiant::nota_maxima()]. */
   /* Post: Al canal de sortida estàndard s'han escrit els
   identificadors dels exàmens parcials als quals s'han presentat tots
   els estudiants que tenen una nota global en l'assignatura més gran o 
   o igual que 5. Els identificadors d'aquests exàmens parcials estan
   ordenats en ordre creixent. */
  

  // Lectura i escriptura
	
  void llegir();
  /* Pre: Estan preparats al canal estàndard d'entrada els pesos dels
     exàmens parcials, un enter entre 0 i la mida màxima permesa, que
     representa el nombre d'estudiants que llegirem, i les dades de tal
     nombre d'estudiants. */
  /* Post: El paràmetre implícit conté el conjunt d'estudiants llegits
     del canal estàndard d'entrada i els pesos dels exàmens parcials. */
    
  void escriure() const;
  /* Pre: cert */
  /* Post: S'han escrit pel canal estàndard de sortida els estudiants del
     paràmetre implícit en ordre ascendent per DNI. */
};
#endif

