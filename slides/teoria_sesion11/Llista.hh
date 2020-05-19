#include "PRO2Excepcio.hh"
#include <iostream>

// no se implementan las excepciones asociadas a las pre, salvo la de concat

template <class T> class Llista {
private:
  struct node_llista {
    T info;
    node_llista* seg;
    node_llista* ant;
  }; 
  int longitud;
  node_llista* primer_node;
  node_llista* ultim_node;
  node_llista* act;
  // especificació operacions privades

  static node_llista* copia_node_llista(node_llista* m, node_llista* oact,
					node_llista* &u, node_llista* &a)
  /* Pre: cert */
  /* Post: si m és NULL, el resultat, u i a són NULL; en cas contrari,
     el resultat apunta al primer node d'una cadena de nodes que són
     còpia de la cadena que té el node apuntat per m com a primer, u
     apunta a l'últim node, a és o bé NULL si oact no apunta a cap node
     de la cadena que comença amb m o bé apunta al node còpia del node
     apuntat per oact */
  { 
    node_llista* n;
    if (m==NULL) {n = NULL; u = NULL; a = NULL;}
    else {
      n = new node_llista;
      n->info = m->info;
      n->ant=NULL;
      n->seg = copia_node_llista(m->seg, oact, u, a);
      if (n->seg == NULL) u = n; // si n es el ultimo, ya tenemos u
      else n->seg->ant = n; // si no, falta conectar marcha atrás n->seg y n 
      if (m == oact) a = n; // gestion del act de la copia
    }
    return n;
  }

  static void esborra_node_llista(node_llista* m) 
  /* Pre: cert */
  /* Post: no fa res si m és NULL, en cas contrari, allibera espai dels 
     nodes de la cadena que té el node apuntat per m com a primer */
  {     
    if (m != NULL) {
      esborra_node_llista(m->seg);
      delete m;
    }
  }


public:
  //  operacions públiques

  // Constructora

  Llista() 
  /* Pre: cert */
  /* Post: el resultat és una llista buida */
  {
    longitud = 0;
    primer_node = NULL;
    ultim_node = NULL;
    act = NULL;
  }

  Llista(const Llista &original) 
  /* Pre: cert */
  /* Post: El resultat és una còpia d'original */
  {
    longitud = original.longitud;
    primer_node = copia_node_llista(original.primer_node, original.act,
				    ultim_node, act);  
  }

  // Destructora

  ~Llista() 
  // Destructora: Esborra automàticament els objectes locals en
  // sortir d'un àmbit de visibilitat
  {
    esborra_node_llista(primer_node);
  }

  // Redefinició de la asignació

  Llista& operator=(const Llista& original) 
  /* Pre: cert */
  /* Post: El p.i. passa a ser una còpia d'original i qualsevol
     contingut anterior del p.i. ha estat esborrat 
     (excepte si el p.i. i original ja eren el mateix objecte) */
  {
    if (this != &original) {
      longitud = original.longitud;
      esborra_node_llista_it(primer_node);
      primer_node = copia_node_llista(original.primer_node, original.act,
				      ultim_node, act);
    }
    return *this;
  }

  // Modificadores

  void l_buida() 
  /* Pre: cert */
  /* Post: El p.i. passa a ser una llista sense elements i qualsevol
     contingut anterior del p.i. ha estat esborrat */
  {
    esborra_node_llista(primer_node);
    longitud = 0;
    primer_node = NULL;
    ultim_node = NULL;
    act = NULL;
  }
        
  void afegir (const T& x) 
  /* Pre: cert */
  /* Post: el p.i. és com el seu valor original, però amb x
     afegit a l'esquerra del punt d'interès */
  {
    node_llista* aux;
    aux = new node_llista; // reserva espai pel nou element
    aux->info = x;
    aux->seg = act;
    if (longitud==0) { // anadir en una lista vacia
      aux->ant = NULL;
      primer_node = aux;
      ultim_node = aux;
    }
    else if (act==NULL) { // anadir al final
      aux->ant = ultim_node;
      ultim_node->seg = aux;
      ultim_node = aux;
    }
    else if (act==primer_node) { // anadir al principio
      aux->ant = NULL;
      act->ant = aux;
      primer_node = aux;
    }
    else { // el resto de casos
      aux->ant = act->ant;
      (act->ant)->seg = aux;
      act->ant = aux;
    }
    ++longitud;
  }

  void eliminar()
  /* Pre: el p.i. és una llista no buida i el seu punt d'interès no està a
     la dreta de tot */ 
  /* Post: El p.i. és com el p.i. original sense l'element on estava el
     punt d'interès i amb el nou punt d'interès avançat una posició a la
     dreta */
  {
    node_llista* aux;
    aux = act; // conserva l'accés al node actual per fer delete en acabar
    if (longitud==1) { // el resultado es una lista vacia
      primer_node = NULL;
      ultim_node = NULL;
    }
    else if (act==primer_node) { // borrar el primero 
      primer_node = act->seg;
      primer_node->ant = NULL;
    }
    else if (act==ultim_node) { // borrar el ultimo
      ultim_node = act->ant;
      ultim_node->seg = NULL;
    }
    else { // el resto de casos
      (act->ant)->seg = act->seg;
      (act->seg)->ant = act->ant;
    }
    act = act->seg; // avança el punt d'interès
    delete aux; // allibera l'espai de l'element esborrat
    --longitud;
  }

  void concat(Llista& l) 
  /* Pre: l=L, el p.i. i l no són el mateix objecte: lis.concat(lis) no esta permés */
  /* Post: el p.i. té els seus elements originals seguits pels de
     L, i l és buida; el punt d'interes del p.i. passa a quedar a l'inici */
  {
    if (this!=&l) {
      if (l.longitud>0) {  // si la llista l és buida no cal fer res
	if (longitud==0) { // si el p.i. es vacio, se ha de convertir en l
	  primer_node = l.primer_node;
	  ultim_node = l.ultim_node;
	  longitud = l.longitud;
	}
	else { // si ni el p.i. ni l son vacios, solo hay que enlazar el ultimo 
	  ultim_node->seg = l.primer_node;  // del p.i. con el primero de l
	  (l.primer_node)->ant = ultim_node;
	  // y hacer que el nuevo ultimo sea el ultimo de l
	  ultim_node = l.ultim_node; 
	  longitud += l.longitud;
	}
	l.primer_node = NULL; // convertimos l en vacia
	l.ultim_node = NULL;
	l.act = NULL;
	l.longitud = 0;  
      }    
      act = primer_node;
    }
    else throw PRO2Excepcio("Les dues llistes són el mateix objecte");
  }
  // Consultores 

  bool es_buida() const 
  /* Pre: cert */
  /* Post: El resultat indica si el p.i. és una llista buida o no */
  {
    return primer_node==NULL;
  }

  int mida() const 
  /* Pre: cert */
  /* Post: El resultat és el nombre d'elements de la llista p.i. */
  {
    return longitud;
  }

  // Noves operacions per a consultar i modificar l'element actual 
 
  T actual() const
  /* Pre: el p.i. és una llista no buida i el seu punt d'interès no està a la dreta de tot */
  /* Post: el resultat és l'element actual del p.i. */ 
  { 
    return act->info;// equival a consultar *it si it es un iterador a l'actual
  }

  void modifica_actual(const T &x) 
  /* Pre: el p.i. és una llista no buida i el seu punt d'interès no està a la dreta de tot */
  /* Post: el p.i. és com el seu valor original, però amb x reemplaçant l'element actual */ 
  {
    act->info = x; // equival a fer *it=x; si it is un iterador
  }

  // Noves operacions per a moure el punt d'interès

  void inici()
  /* Pre: cert */
  /* Post: el punt d'interès del p.i. està situat a sobre del primer element de la llista
     o a la dreta de tot si la llista és buida */
  {
    act = primer_node; // equival a fer it=l.begin(); si it es un iterador a l'actual
  }

  void fi()
  /* Pre: cert */
  /* Post: el punt d'interès del p.i. està situat a sobre de l'últim
     element de la llista */
  {
    act = NULL;  // equival a fer it=l.end(); si it es un iterador a l'actual
  }

  void avanca() 
  /* Pre: el punt d'interès del p.i. no està a la dreta de tot */
  /* Post: el punt d'interès del p.i. està situat una posició més a la
     dreta que el valor original del p.i. */ 
  { 
    act = act->seg; // equival a fer ++it; si it es un iterador a l'actual
  }

  void retrocedeix() 
  /* Pre: el punt d'interès del p.i. no està a sobre del primer element de
     la llista*/
  /* Post: el punt d'interès del p.i. està situat una posició més a
     l'esquerra que el valor original del p.i. */ 
  {
    if (act==NULL) act = ultim_node;  
    else act = act->ant; // equival a fer --it; si it es un iterador a l'actual
  }

  bool dreta_de_tot() const
  /* Pre: cert */
  /* Post: el resultat indica si el punt d'interès del p.i. està a la
     dreta de tot */
  {
    return act==NULL; 
    // equival a comparar it==l.end() si it es un iterador a l'actual
  }

  bool sobre_el_primer() const 
  /* Pre: cert */
  /* Post: el resultat indica si el punt d'interès del p.i. està a sobre del 
     primer element del p.i. */
  {
    return act==primer_node; 
    // equival a comparar it==l.begin() si it es un iterador a l'actual
  }

  // Extensión ------------------------------------------------

#include "otra_funcion.hh"

  void invertir ()
  /* Pre: cert */ 
  /* Post: el p.i. té els mateixos elements que a l'inici però amb l'ordre invertit
     i el seu punt d'interés no s'ha mogut */
  {
    node_llista* n = primer_node;
    while (n != ultim_node) {
      /* Inv: els nodes anteriors al que apunta n en la cadena que
	 comença a primer_node han intercanviat els seus punters a
	 l'anterior i al següent node */
      node_llista* aux = n->seg;
      n->seg = n->ant;
      n->ant = aux;
      n = aux;
    }
    if (n!=NULL and n!=primer_node) { // n = ultim i la llista té més d'un element
      n->seg = n->ant;
      n->ant = NULL;
      ultim_node = primer_node;
      primer_node = n;
    }
  }

  void invertir2 ()
  /* Pre: cert */
  /* Post: el p.i. té els mateixos elements que a l’inici però amb
     l’ordre invertit i el seu punt d’interés no s’ha mogut */
  {
    if (longitud > 1) {
      node_llista* n = primer_node;
      while (n != NULL) {
	/* Inv: els nodes anteriors al que apunta n en la cadena que
	   comença a primer_node han intercanviat els seus punters a
	   l’anterior i al següent node */
	node_llista* aux = n->seg;
	swap(n->seg, n->ant);
	n = aux;
      }
      swap(primer_node, ultim_node);
    }
  }
};
