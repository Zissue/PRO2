template <class T> class stack{ 

  // Declaraci� d'objectes: stack<int> p; stack<Estudiant> p_est;

  // Tipus de m�dul: dades

  // Descripci� del tipus: Estructura lineal que cont� elements de tipus T
  // i que permet consultar i eliminar nom�s l'�ltim element afegit
 
private:
 
public:
 
  // Constructores

  stack(); 
  /* Pre: cert */ 
  /* Post: El resultat �s una pila sense cap element */ 
 
  stack(const stack & original); // stack<int> nueva(antigua);
  /* Pre: cert */
  /* Post: El resultat �s una c�pia d'original */
 
  // Destructora: Esborra autom�ticament els objectes locals en sortir
  // d'un �mbit de visibilitat
 
  ~stack();
 
  // Modificadores

  void push(const T& x); 
  /* Pre: cert */
  /* Post: El par�metre impl�cit �s com el par�metre impl�cit original amb
     x afegit com a darrer element */ 
 
  void pop(); 
  /* Pre:  El par�metre impl�cit no est� buit */
  /* Post: El par�metre impl�cit �s com el par�metre impl�cit original
     per� sense el darrer element afegit al par�metre impl�cit original */
 
  // Consultores 
 
  T top() const; 
  /* Pre: El par�metre impl�cit no est� buit */
  /* Post: El resultat �s el darrer valor afegit al par�metre implicit */
 
  // De moment, preferim no fer servir l'altra opci� que ofereix l'STL: 
  &T top(); 
  // per no permetre coses desmodularitzadores com ++p.top();

  bool empty() const;
  /* Pre: cert */
  /* Post: El resultat indica si el par�metre impl�cit �s buit o no */
 
  int size() const;
  /* Pre: cert */
  /* Post: El resultat �s el nombre d'elements del par�metre impl�cit */

  // Si volem piles amb mida afitada, hem d'afegir una operaci� per
  // consultar la mida m�xima permesa

  static int mida_max();
  /* Pre: cert */
  /* Post: El resultat �s el nombre m�xim d'elements que por tenir un
     element de la classe */
};
