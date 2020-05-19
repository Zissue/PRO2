// NOTA; la version de laboratorio contiene excepciones para controlar
// las situaciones de error

#include "PRO2Excepcio.hh"
#include <vector>

template <class T> class ArbreNari { 
private:     
  struct node_arbreNari {
    T info;
    vector<node_arbreNari*> seg;
  };
  int N;
  node_arbreNari* primer_node;
  // especificació operacions privades
 
  static node_arbreNari* copia_node_arbreNari(node_arbreNari* m) { 
    /* Pre: cert */
    /* Post: el resultat és NULL si m és NULL; en cas contrari, el resultat
       apunta al node arrel d'una jerarquia de nodes que és una còpia de la
       jerarquia de nodes que té el node apuntat per m com a arrel */
    node_arbreNari* n;
    if (m==NULL) n = NULL;
    else {
      n = new node_arbreNari;
      n->info = m->info;
      int ari = m->seg.size();
      n->seg = vector<node_arbreNari*>(ari);
      for (int i=0; i<ari; ++i) 
	n->seg[i] = copia_node_arbreNari(m->seg[i]);
    }
    return n;
  }

  static void esborra_node_arbreNari(node_arbreNari* m) {  
    /* Pre: cert */
    /* Post no fa res si m és NULL; en cas contrari, allibera espai de tots
       els nodes de la jerarquia que té el node apuntat per m com a arrel */
    if (m != NULL) {
      int ari = m->seg.size();
      for (int i=0; i<ari; ++i) 
	esborra_node_arbreNari(m->seg[i]);
      delete m;
    }
  }

public:
  // especificació operacions públiques

  ArbreNari(int n) {
    /* Pre: n > 0 */
    /* Post: el p.i. és un arbre buit d'aritat n */
    N = n;
    primer_node= NULL;
  }

  ArbreNari(const T &x, int n)
  /* Pre: n >0  */
  /* Post: el p.i. és un arbre amb arrel x i n fills buits */
  {
    N = n;
    primer_node= new node_arbreNari;
    primer_node->info = x;
    primer_node->seg = vector<node_arbreNari*>(N,NULL);
    // MEJOR QUE 
    // for (int i=0; i<N; ++i)
    //   primer_node->seg[i] = NULL;
  }

  ArbreNari(const ArbreNari& original) {
    /* Pre: cert */
    /* Post: el p.i. és una còpia d'original */
    N = original.N;
    primer_node = copia_node_arbreNari(original.primer_node);
  }

  // Destructora: Esborra automàticament els objectes locals en
  // sortir d'un àmbit de visibilitat
  ~ArbreNari() {
    esborra_node_arbreNari(primer_node);
  }

  ArbreNari& operator=(const ArbreNari& original) 
  /* Pre: cert */
  /* Post: El p.i. passa a ser una còpia d'original i qualsevol
     contingut anterior del p.i. ha estat esborrat
     (excepte si el p.i. i original ja eren el mateix objecte) */
  {
    if (this != &original) {
      esborra_node_arbreNari(primer_node);
      N = original.N;
      primer_node = copia_node_arbreNari(original.primer_node);
    }
    return *this;
  }

  void a_buit() {
    /* Pre: cert */
    /* Post: el p.i. és un arbre buit */
    esborra_node_arbreNari(primer_node);
    primer_node = NULL;
  }        

  void plantar(const T &x, vector<ArbreNari> &v) {
    /* Pre:  el p.i. és buit i la longitud de v és igual a l'aritat del p.i.     
       tots els components de v tenen la mateixa aritat que el p.i.
       i cap d'ells es el mateix objecte que el p.i. */
    /* Post: el p.i. té x com a arrel i els N elements originals  
       de v com a fills, v passa a contenir arbres buits */
    node_arbreNari* aux = new node_arbreNari;
    aux->info = x;
    aux->seg = vector<node_arbreNari*>(N);
    for (int i=0; i<N; ++i) {
      aux->seg[i] = v[i].primer_node;
      v[i].primer_node = NULL;
    }
    primer_node = aux;
  }

  void fills(vector<ArbreNari> &v) {
    /* Pre:  el p.i. no és buit i li diem A, v és buit */
    /* Post: el p.i. és buit, v passa a contenir els N fills de l'arbre A  */
    node_arbreNari* aux = primer_node;
    v = vector<ArbreNari> (N,ArbreNari(N)); // el usuario no ha de dimensionar v
    for (int i=0; i<N; ++i) 
      v[i].primer_node = aux->seg[i];  
    primer_node = NULL;
    delete aux;
  }

  T arrel() const {
    /* Pre: el p.i. no és buit */
    /* Post: el resultat és l'arrel del p.i. */
    return primer_node->info;
  }

  bool es_buit() const 
  /* Pre: cert */
  /* Post: el resultat indica si el p.i. és un arbre buit */
  {
    return (primer_node==NULL);
  }

  int aritat() const
  /* Pre: cert */
  /* Post: el resultat és l'aritat del p.i. */
  {
    return N;
  }

  // Extension

  void inc_arbreNari (const T &k)
  /* Pre: A és el valor inicial del p.i. */ 
  /* Post: el p.i. és com A però havent sumat k a tots els seus elements */
  {
    inc_nodeNari(primer_node, k);
  }

  static void inc_nodeNari (node_arbreNari* n, const T &k)
  /* Pre: cert */ 
  /* Post: el node apuntat per n i tots els seus següents tenen al seu camp
     info la suma de k i el seu valor original */
  {
    if (n!=NULL) {
      n->info += k;
      int s = (n->seg).size();
      for (int i=0; i<s; ++i) 
	inc_nodeNari(n->seg[i], k);
    }
  }

};
