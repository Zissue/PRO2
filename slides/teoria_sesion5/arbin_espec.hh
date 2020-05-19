template <class T> class Arbre{

  // Tipus de mòdul: dades

  // Descripció del tipus: Arbre genèric que o bé és buit o bé tot
  // subarbre seu té exactament 2 fills

private:

public:

  // Constructores

  Arbre();
  /* Pre: cert */
  /* Post: El resultat és un arbre sense cap element */

  Arbre(const Arbre &original);
  /* Pre: cert */
  /* Post: El resultat és un arbre còpia d’original */


  // Destructora: Esborra automàticament els objectes locals en sortir
  // d'un àmbit de visibilitat

  ~Arbre();

  // Modificadores

  void a_buit();
  /* Pre: cert */
  /* Post: El paràmetre implícit no té cap element */

  void plantar(const T& x, Arbre& a1, Arbre& a2);
  /* Pre: El paràmetre implícit és buit, a1 = A1, a2 = A2, el p.i. és
     buit però no és el mateix objecte que a1 ni a2 */
  /* Post: El paràmetre implícit té x com a arrel, A1 com a fill esquerre
     i A2 com a fill dret; a1 i a2 són buits; si A1 i A2 són el mateix objecte,
     el fill dret n'és una còpia  */ 

  // a.plantar(x,a,b); NO
  // a.plantar(x,b,b); SI

  void fills(Arbre& fe, Arbre& fd);
  /* Pre: El paràmetre implícit no està buit; fe, fd són buits i no
     són el matex objecte */
  /* Post: fe és el fill esquerre del paràmetre implícit original; fd és
     el fill dret del paràmetre implícit original, el paràmetre implícit
     és buit */

  // a.fills(b,b); NO

  // Consultores

  T arrel() const;
  /* Pre: El paràmetre implícit no està buit */
  /* Post: El resultat és l'arrel del paràmetre implícit */

  //   ++a.arrel(); NO

  bool es_buit() const;
  /* Pre: cert */
  /* Post: El resultat indica si el paràmetre implícit està buit o no */
};
