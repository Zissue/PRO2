template <class T> class queue{

  // Tipus de mòdul: dades

  // Descripció del tipus: Estructura lineal que conté elements de tipus T
  // i que permet consultar i eliminar només el primer element afegit


private:

public:

  // Constructores

  queue();
  /* Pre: cert */
  /* Post: El resultat és una cua sense cap element */

  queue(const queue &original);
  /* Pre: cert */
  /* Post: El resultat és una cua còpia d’original */

  // Destructora: Esborra automàticament els objectes locals en sortir d’un
  // àmbit de visibilitat

  ~queue();


  // Modificadores

  void push(const T& x);
  /* Pre: cert */
  /* Post: El paràmetre implícit és com el paràmetre implícit original amb
     x afegit com a darrer element */

  void pop();
  /* Pre: El paràmetre implícit no està buit */
  /* Post: El paràmetre implícit és com el paràmetre implícit original però
     sense el primer element afegit al paràmetre implícit original */

  // Consultores

  T front() const;
  /* Pre: El paràmetre implícit no està buit */
  /* Post: El resultat és el valor més antic afegit al paràmetre implícit */

  // De moment, preferim no fer servir l'altra opció que ofereix l'STL: 
  &T front(); 
  // per no permetre coses desmodularitzadores com ++c.front();

  bool empty() const;
  /* Pre: cert */
  /* Post: El resultat indica si el paràmetre implícit és buit o no */

  int size() const;
  /* Pre: cert */
  /* Post: El resultat és el nombre d'elements del paràmetre implícit */


  // Si volem cues amb mida afitada, s'ha d'afegir una operació per
  // consultar la mida màxima permesa

  static int mida_max();
  /* Pre: cert */
  /* Post: El resultat és el nombre màxim d'elements que por tenir un
     element de la classe */
};
