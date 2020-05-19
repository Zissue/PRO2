// Versión 2: genérica y con prim, ult y longitud; 
// se aprovecha todo el vector

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "PRO2Excepcio.hh"
#include <vector>

template <class T> class queue {

private:

  static const int MAX_SIZE = 10;
  int prim,ult,longitud; 
  // forman la cola los elementos entre prim y ult (mod  MAX_SIZE), incl.  
  // ha de haber "longitud" elementos
  vector<T> elems;

  /* Inv de la representación:
     - 0 <= prim, ult <= MAX_SIZE-1
     - 0 <= longitud <= MAX_SIZE
     - si prim <= ult => longitud = ult-prim+1;
       si no, si ult+1 != prim, longitud = ult-prim+MAX_SIZE+1;
       si no (ult+1=prim), longitud = 0 (cola vacia) o longitud = MAX_SIZE (cola llena)
  */
public:

  //Constructoras

  /* crea una cua buida*/
  queue(){
    elems=vector<T>(MAX_SIZE);
    longitud = 0;
    prim = 0;
    ult = MAX_SIZE-1;
  }

  /* crea una pila copia d'original*/
  queue(const queue& original){
    longitud=original.longitud;
    prim=original.prim;
    ult=original.ult;
    elems=original.elems;
  }

  //Destructora
  ~queue(){}

  //Modificadores 


  /* la cua no és plena */
  /* afegeix l'element x a la cua */
  void push(const T &elemento) {
    if (longitud==MAX_SIZE) throw PRO2Excepcio("Llena!"); 
    ult=(ult+1) % MAX_SIZE; 
    elems[ult]=elemento;
    ++longitud;
  }


  /* la cua no es buida */
  /* elimina el primer element afegit a la cua */
  void pop(){
    if (longitud==0) throw PRO2Excepcio("Vacia!");
    prim=(prim + 1) % MAX_SIZE;
    --longitud; 
  }

  //Consultores 

  /* la cua no es buida */
  /* retorna el primer element afegit a la cua*/
  T front() const {
    if (longitud==0) throw PRO2Excepcio("Vacia!");
    return elems[prim];
  }


  /* retorna si la cua es buida o no */
  bool empty() const {
    return (longitud==0);
  }

  /* retorna la mida de la cua */ 
  int size() const{
    return longitud;
  }

 /* retorna la mida maxima permesa */ 
  static int mida_max(){
    return MAX_SIZE;
  }

  // AQUI Es PODRIAN AFEGIR OPERACIONS NOVAS

};

#endif
