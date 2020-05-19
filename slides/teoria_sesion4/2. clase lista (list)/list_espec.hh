template <class T> class list {

  // Tipus de mòdul : dades

  // Descripció del tipus: Estructura lineal que conté elements de tipus T,
  // i que admet consultar, modificar, afegir, esborrar elements a
  // qualsevol punt

private:

public:

  // Constructores

  list();
  /* Pre: cert */
  /* Post: El resultat és una llista sense cap element */

  list(const list & original);
  /* Pre: cert */
  /* Post: El resultat és una llista còpia d’original */

  // Destructora: Esborra automàticament els objectes locals en sortir d’un
  // àmbit de visibilitat

  ~list();

  // Modificadores


  void clear();
  /* Pre: cert */
  /* Post: El paràmetre implícit és una llista buida */

  void insert(iterator it, const T& x);
  /* Pre: it referencia algun element existent al paràmetre implícit o és
     igual a l'end() d’aquest */
  /* Post: El paràmetre implícit és com el paràmetre implícit original amb
     x davant de l’element referenciat per it al paràmetre implícit
     original */

  iterator erase(iterator it);
  /* Pre: it referencia algun element existent al paràmetre implícit, que
     no és buit */
  /* Post: El paràmetre implícit és com el paràmetre implícit original
     sense l’element referenciat per l’it original; el resultat referencia
     l’element següent al que referenciava it al paràmetre implícit
     original */

  // Nota: si volem que el propi it passi a referenciar l'element següent
  // al que referenciava al p.i. original d'una llista l, hem de cridar
  // it = l.erase(it)

  void splice(iterator it, list& l); 
  /* Pre: l=L, it referencia algun element del paràmetre implícit (o l'end); 
     el paràmtre implícit i l NO són el mateix objecte */
  /* Post: El paràmetre implícit té els seus elements originals i els d’l
     inserits davant de l’element referenciar per it; l està buida */

  // L1 = 1 2 3 4 5; L2 = 10 11 12;  it ref.al 4
  // tras L1.splice(it,L2)
  // L1 = ? 
  // L2 = ?

  // concatenar L1,L2: L1.splice(L1.end(),L2)

  // L1.splice(it,L1) no es valido (las listas son el mismo objeto)

  // Consultores

  bool empty() const;
  /* Pre: cert */
  /* Post: El resultat indica si el paràmetre implícit te elements o no */

  int size() const;
  /* Pre: cert */
  /* Post: El resultat és el nombre d’elements del paràmetre implícit */

  // Iterators

  iterator begin();
  /* Pre: cert */
  /* Post: El resultat dóna accés de consulta i modificació al primer element 
     del paràmetre implícit, si aquest no és buit; 
     en cas contrari, el resultat n'és l'end() (no constant) */

  const_iterator begin() const;
  /* Pre: cert */
  /* Post: El resultat dóna accés només de consulta al primer element 
     del paràmetre implícit, si aquest no és buit; 
     en cas contrari, el resultat n'és l'end() (constant) */

  // cuando se hace it=l.begin(), se aplica automaticamente una version o
  // la otra dependiendo de como se ha declarado it; si la lista ha sido
  // declarada como const, entonces begin siempre es const; idem para end

  iterator end();
  /* Pre: cert */
  /* Post: El resultat és el teòric element posterior a l'últim del p.i.
     (es pot fer servir per l'insert, però no per l'erase i no pot ser 
     desreferenciat) */

  const_iterator end() const;
  /* Pre: cert */
  /* Post: El resultat és el teòric element posterior a l'últim del p.i.
     (no es pot fer servir per l'insert, ni per l'erase i no pot ser 
     desreferenciat) */

};


/* Operacions amb iterators de llistes:

++it : Avança al següent element, no vàlid a l'end

--it : Retrocedeix a l'anterior element, no vàlid al begin

*it : Designa l'element referenciat per it; no vàlid per a l'end o per a
      iteradors que no referencien res; si la llista d'it ve qualificada 
      com a const o si it és un const_iterator, llavors *it és "read-only"

it1=it2 : Assigna l'iterador it2 a it1; un const_iterator no es pot
assignar a un iterator

it1==it2 : val true si els iteradors it1 i it2 són iguals; false si no 

it1!=it2 : val true si els iteradors it1 i it2 són diferents; false si no

*/
