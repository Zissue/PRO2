// implementació no genérica amb vectors: stack_int.hh
//
// si dimensionem el vector al principi,
// la op push no es pot fer si s'en supera la size

#ifndef STACK_INT_HPP
#define STACK_INT_HPP

using namespace std;
#include <vector>

// si volem fer servir excepcions quan s'incompleixin les pres
// hem d'incloure PRO2Excepcio.hh
 
class stack_int {

private:

  static const int MAX_SIZE = 1000;
  int cur; // primera posició lliure
  vector<int> elems;
  /* Inv de la representació:
     - 0 <= cur <= MAX_SIZE-1    
  */

public:

  //Constructoras

  /* crea una pila buida*/
  stack_int();

  /* crea una pila copia d'original*/
  stack_int(const stack_int& original);

  //Destructora
  ~stack_int();

  //Modificadores 

  /* afegeix l'element x a la pila */
  void push(const int &elemento);


  /* la pila no es buida */
  /* elimina l'ultim element afegit a la pila */
  void pop();

  //Consultores 

  /* la pila no Ã©s buida */
  /* retorna l'ultim element afegit a la pila*/
  int top() const;


  /* retorna si la pila és buida o no */
  bool empty() const;

  /* retorna el nombre d'elements de la pila */
  int size() const;

  /* retorna la mida maxima permesa */ 
  static int mida_max();
};

#endif
