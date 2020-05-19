// versión 1: contenido particularizado, solo prim y ult;
// el anterior a prim no se puede ocupar, para no confundir la cola vacía 
// con la cola llena (se desaprovecha una posición del vector)

#ifndef QUEUE_INT_HPP
#define QUEUE_INT_HPP

#include "PRO2Excepcio.hh"
#include <vector>

class queue_int {

private:

  static const int MAX_SIZE = 10;
  int prim,ult;  
  // forman la cola los elementos entre prim y ult (mod  MAX_SIZE), incl.
  vector<int> elems;

  /* Inv de la representación: 
     - 0 <= prim, ult <= MAX_SIZE-1
     - prim != (ult+1) % MAX_SIZE 
      (la posición anterior a prim no se puede ocupar)
  */

public:

  //Constructoras

  /* crea una cua buida*/
  queue_int();

  /* crea una cua copia d'original*/
  queue_int(const queue_int& original);

  //Destructora
  ~queue_int();

  //Modificadores 

  /* la cua no és plena: per la impl. amb vector */
  /* afegeix l'element x a la cua */
  void push(const int &elemento);


  /* la cua no es buida */
  /* elimina el primer element afegit a la cua */
  void pop();

  //Cosultores 

  /* la cua no es buida */
  /* retorna el primer element afegit a la cua */
  int front() const;


  /* retorna si la cua es buida o no */
  bool empty() const;

  /* retorna la mida de la cua */ 
  int size() const;

  /* retorna la mida maxima permesa */ 
  static int mida_max();
};

#endif
