// si es vol fer genèrica, s'ha de fer servir un template i
// convé que la implementació estigui tota al hh

#ifndef STACK_HPP
#define STACK_HPP

#include "PRO2Excepcio.hh"
#include <vector>

template <class T> class stack {

private:

  static const int MAX_SIZE = 1000;
  int cur; // primera posicio lliure
  vector<T> elems; // T representa el tipus del contingut; pot ser qualsevol

public:

  //Constructoras

  /* crea una pila buida*/
  stack(){
    elems=vector<T>(MAX_SIZE);
    cur = 0;
  }

  /* crea una pila copia d'original*/
  stack(const stack& original){
    cur=original.cur;
    elems=original.elems;
  }

  //Destructora
  ~stack(){}

  //Modificadores 


  /* afegeix l'element x a la pila */
  void push(const T &elemento) {
    if (cur == MAX_SIZE) throw PRO2Excepcio("Pila llena");
    elems[cur]=elemento;
    ++cur;
  }


  /* la pila no es buida */
  /* elimina l'ultim element afegit a la pila */
  void pop(){
    if (cur == 0) throw PRO2Excepcio("Pila vacia");
    --cur;
  }

  //Cosultores 

  /* la pila no es buida */
  /* retorna l'ultim element afegit a la pila*/
  T top() const {
    if (cur == 0) throw PRO2Excepcio("Pila vacia");
    return elems[cur-1];
  }


  /* retorna si la pila es buida o no */
  bool empty() const {
    return (cur==0);
  }

  /* retorna la mida de la pila */
  int size() const{
    return cur;
  }

 /* retorna la mida màxima dels elements de la classe */
  int mida_max(){
    return MAX_SIZE;
  }

  // així és com s'afegeix una operació nova
  void invertir() {
    for (int i=0; i<cur/2; ++i)
      swap(elems[i],elems[cur-i-1]);
  }

  void sumar_k(const T& k){ // solo se puede usar si T tiene el operador +
    for (int i=0; i<cur; ++i) elems[i]+=k;
  }
};

#endif


// stack<int> p;  declaració d'una pila d'enters nova, buida

// stack<int> q(p); declaració d'una pila d'enters nova, còpia de p

// stack<Estudiant>

// p[i]=14; NOOOOOOOOO!!!!!!!!

// vector<T> volcar_elementos(const stack<T> &p);  NOOOOOOO!!!!!!
