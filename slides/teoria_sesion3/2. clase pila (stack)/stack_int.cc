// implementació no genérica amb vectors: stack_int.cc
//
// si dimensionem el vector al principi,
// la op push no es pot fer si s'en supera la size

#include "stack_int.hpp"

//Constructoras

/* crea una pila buida*/
stack_int::stack_int(){
  elems=vector<int>(MAX_SIZE);
  cur = 0;
}

/* crea una pila copia d'original*/
stack_int::stack_int(const stack_int& original){
  cur=original.cur;
  elems=vector<int>(original.elems);
}

//Destructora
stack_int::~stack_int(){}

//Modificadores 

/* la pila no és plena: per la impl. amb vector */
/* afegeix l'element x a la pila */
void stack_int::push(const int &elemento) {
  elems[cur]=elemento;
  ++cur;
}

/* la pila no es buida */
/* elimina l'ultim element afegit a la pila */
void stack_int::pop(){
  --cur;
}


//Consultores 

/* la pila no es buida */
/* retorna l'ultim element afegit a la pila*/
int stack_int::top() const {
  return elems[cur-1];
}


/* retorna si la pila es buida o no */
bool stack_int::empty() const {
  return (cur==0);
}

int stack_int::size() const {
  return cur;
}

int stack_int::mida_max(){
  return MAX_SIZE;
}
