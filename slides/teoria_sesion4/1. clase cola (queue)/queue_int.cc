#include "queue_int.hpp"

//Constructoras

/* crea una cua buida*/
queue_int::queue_int(){
  elems=vector<int>(MAX_SIZE);
  prim = 0;
  ult = MAX_SIZE-1;
  // para que se cumpla la condicion de vacia y que el primero en entrar 
  // se ponga en el 0
}

/* crea una cua copia d'original*/
queue_int::queue_int(const queue_int& original){
  prim=original.prim;
  ult=original.ult;
  elems=original.elems;
}

//Destructora
queue_int::~queue_int(){}

//Modificadores 

/* afegeix l'element x a la cua */
void queue_int::push(const int &elemento) {
  if (prim == (ult+2) % MAX_SIZE) throw PRO2Excepcio("llena!");
  ult = (ult+1) % MAX_SIZE; 
  elems[ult]=elemento;
}


/* la cua no es buida */
/* elimina el primer element afegit a la cua */
void queue_int::pop(){
  if (prim == (ult+1) % MAX_SIZE) throw PRO2Excepcio("vacia!");
  prim = (prim + 1) % MAX_SIZE; 
}


//Consultores 

/* la cua no es buida */
/* retorna el primer element afegit a la cua*/
int queue_int::front() const {
  if (prim == (ult+1) % MAX_SIZE) throw PRO2Excepcio("vacia!");
  return elems[prim];
}


/* retorna si la cua es buida o no */
bool queue_int::empty() const {
  return (prim == (ult+1) % MAX_SIZE);
}

  /* retorna la mida de la cua */ 
int queue_int::size() const{
  if (ult>=prim) return ult-prim+1;
  else return ult-prim+1+MAX_SIZE;
}

 /* retorna la mida maxima permesa */ 
int queue_int::mida_max(){
  return MAX_SIZE;
}
