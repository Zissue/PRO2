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
  node_llista* sent;
  node_llista* act;
  // especificació i implementació d'operacions privades

  static node_llista* copia_node_llista(node_llista* m, node_llista* s, node_llista* oact, node_llista* &ns, node_llista* &a) 
  /* Pre: s apunta a un sentinella, m i s pertanyen a la mateixa cadena
     de nodes */
  /* Post: si m apunta a s, el resultat, ns i a apunten a una còpia del
     sentinella; en cas contrari, el resultat apunta al primer node
     d'una cadena de nodes que són còpia de la cadena que té el node
     apuntat per m com a primer i acaba en s, ns apunta a la còpia del
     sentinella s, i a apunta al node còpia del node apuntat per oact */
  {
    node_llista* n = new node_llista;
    if (m==s) {n->ant = n; n->seg = n; ns = n; a = n;}
    else {
      n->info = m->info;
      n->seg = copia_node_llista(m->seg, s, oact, ns, a);
      (n->seg)->ant = n; 
      ns->seg = n;
      n->ant = ns;
      if (m == oact) a = n;
    }
    return n;
  }

  static void esborra_node_llista(node_llista* m, node_llista* s)

  /* Pre: s apunta a un sentinella, m i s pertanyen a la mateixa cadena
     de nodes */
  /* Post: si m apunta a s, esborra el sentinella; en cas contrari,
     allibera espai dels nodes de la cadena que té el node apuntat per m
     com a primer i acaba en s */
  {
    if (m != s) {
      esborra_node_llista(m->seg, s);
    }
    delete m;
  }
public:
  // especificació i implementació d'operacions públiques

  // Constructores

  Llista() {
    longitud= 0;
    sent = new node_llista;
    sent->seg = sent;
    sent->ant = sent;
    act = sent;
  }

  Llista(const Llista& original) {
    longitud = original.longitud; 
    copia_node_llista((original.sent)->seg, original.sent, original.act,
		      sent, act);
  }

  // Destructora

  ~Llista() {
    esborra_node_llista(sent->seg, sent);
  }

  // Redefinició de l'assignació

  Llista& operator=(const Llista& original) {
    if (this != &original) {
      longitud = original.longitud;
      esborra_node_llista(sent->seg, sent); 
      copia_node_llista((original.sent)->seg, original.sent, original.act,
			sent, act);
    }
    return *this;
  }

  // Modificadores

  void l_buida() {
    esborra_node_llista(sent->seg, sent);
    // se ha destruit fins i tot el sentinel.la
    longitud = 0;
    sent = new node_llista; 
    sent->seg = sent;
    sent->ant = sent;
    act = sent;
  }
        
  void afegir (const T& x) {
    node_llista* aux;
    aux = new node_llista; // reserva espai pel nou element
    aux->info = x;
    aux->seg = act;
    aux->ant = act->ant;   // basicament coincideix amb l'ultim cas
    (act->ant)->seg = aux; // de l'afegir en llistes normals
    act->ant= aux;
    ++longitud;
  }

  void eliminar() {
    // la pre, juntament a la definicio de sentinella implica act!=sent
    node_llista* aux;  
    aux = act; // conserva l'accés al node actual
    (act->ant)->seg = act->seg; // basicament coincideix amb l'ultim cas
    (act->seg)->ant = act->ant;  // de l'afegir en llistes normals
    act = act->seg; // avança el punt d'interès
    delete aux; // allibera l'espai de l'element esborrat
    --longitud;
  }

  void concat(Llista& l) {
    // esta operacion es un poco mas complicada que la de listas normales
    if (this!=&l) {
      if (l.longitud>0) {  
	if (longitud==0) { // el sent del p.i. pasa a apuntar a los elems de l.
	  sent->seg = (l.sent)->seg;  // (y a ser apuntado por ellos)
	  sent->ant = (l.sent)->ant;
	  (sent->seg)->ant = sent;
	  (sent->ant)->seg = sent;
	  longitud = l.longitud;
	}
	else { 
	  (sent->ant)->seg = (l.sent)->seg; // enlazamos el ultimo del p.i.
	  ((l.sent)->seg)->ant = sent->ant; // con el primero de l
	  sent->ant = (l.sent)->ant;
	  ((l.sent)->ant)->seg = sent;
	  longitud += l.longitud;
	}
	(l.sent)->seg = l.sent;
	(l.sent)->ant = l.sent;
	l.act = l.sent;
	l.longitud = 0;   
      }
      act = sent->seg;
    }
    else throw PRO2Excepcio("Les dues llistes són el mateix objecte");
  }
  // Consultores 

  bool es_buida() const {
    return longitud==0; // nomes es pot fer aixi
  }

  int mida() const {
    return longitud;
  }

  // Noves operacions per a consultar i modificar l'element actual 
 
  T actual() const {   
    // la pre, juntament a la definicio de sentinella implica act!=sent
    return act->info; 
  }

  void modifica_actual(const T &x) {  
    // la pre, juntament a la definicio de sentinella implica act!=sent
    act->info = x; 
  }

  // Noves operacions per a moure el punt d'interès

  void inici() {   
    act = sent->seg;  
  }

  void fi() {
    act = sent;
  }

  void avanca() {
    // la pre, juntament a la definicio de sentinella implica act!=sent
    act = act->seg; 
  }

  void retrocedeix() {
    // la pre, juntament a la definicio de sentinella implica act!=sent->seg
    act = act->ant;
  }

  bool dreta_de_tot() const {
    return act==sent;  
  }

  bool sobre_el_primer() const {
    return act==(sent->seg); 
  }
};
