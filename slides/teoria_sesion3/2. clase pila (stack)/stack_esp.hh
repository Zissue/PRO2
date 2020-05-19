template <class T> class stack{ 

  // Declaració d'objectes: stack<int> p; stack<Estudiant> p_est;

  // Tipus de mòdul: dades

  // Descripció del tipus: Estructura lineal que conté elements de tipus T
  // i que permet consultar i eliminar només l'últim element afegit
 
private:
 
public:
 
  // Constructores

  stack(); 
  /* Pre: cert */ 
  /* Post: El resultat és una pila sense cap element */ 
 
  stack(const stack & original); // stack<int> nueva(antigua);
  /* Pre: cert */
  /* Post: El resultat és una còpia d'original */
 
  // Destructora: Esborra automàticament els objectes locals en sortir
  // d'un àmbit de visibilitat
 
  ~stack();
 
  // Modificadores

  void push(const T& x); 
  /* Pre: cert */
  /* Post: El paràmetre implícit és com el paràmetre implícit original amb
     x afegit com a darrer element */ 
 
  void pop(); 
  /* Pre:  El paràmetre implícit no està buit */
  /* Post: El paràmetre implícit és com el paràmetre implícit original
     però sense el darrer element afegit al paràmetre implícit original */
 
  // Consultores 
 
  T top() const; 
  /* Pre: El paràmetre implícit no està buit */
  /* Post: El resultat és el darrer valor afegit al paràmetre implicit */
 
  // De moment, preferim no fer servir l'altra opció que ofereix l'STL: 
  &T top(); 
  // per no permetre coses desmodularitzadores com ++p.top();

  bool empty() const;
  /* Pre: cert */
  /* Post: El resultat indica si el paràmetre implícit és buit o no */
 
  int size() const;
  /* Pre: cert */
  /* Post: El resultat és el nombre d'elements del paràmetre implícit */

  // Si volem piles amb mida afitada, hem d'afegir una operació per
  // consultar la mida màxima permesa

  static int mida_max();
  /* Pre: cert */
  /* Post: El resultat és el nombre màxim d'elements que por tenir un
     element de la classe */
};
