// ver apuntes de Eficiencia, version nov-13, pag 7
//
// Un elemento de una pila de numeros se dice dominador si es mayor o igual
// que la suma de los elementos que tiene por debajo (los mas antiguos que el).
// Obtener el dominador mas alto de una pila de naturales (el mas reciente)

#include "stackIOint.hpp"

int suma(stack<int> p)
/* Pre: p=P */
/* Post: el resultado es la suma de los elementos de P */
{
  int s=0;
  while (not p.empty()){
    s+=p.top();
    p.pop();
  } 
  return s;
}




int dom(stack<int> & p)
/* Pre: p no es vacía y esta formada por naturales, p=P */
/* Post: el resultado es el dominador mas alto de P */
{ 
  int res=p.top();
  p.pop();
  if (not p.empty()){
    if (res<suma(p)) res=dom(p); 
    /* HI: res es el dominador mas alto de p (P despues de hacer P.pop()) */
    // si res<suma(p) coincide con el dominador mas alto de P
    // en caso contrario el dominador mas alto es el top
  }
  return res;
}


pair<int,int> dom_ef(stack<int>& p)
/* Pre: p no es vacía y esta formada por naturales, p=P */
/* Post: El first del resultado es el dominador mas alto de P; el second
   del resultado es la suma de P */
{
  pair<int,int> res;
  res.first=res.second=p.top();
  p.pop();
  if (not p.empty()){
    pair<int,int> aux = dom_ef(p); 
    /* HI: aux.first es el dominador mas alto de p (P despues de hacer P.pop())
       aux.second es la suma de p */
    if (res.first<aux.second) res.first=aux.first;
    res.second+=aux.second;
  }
  return res;
}



int dom_ef_param(stack<int>& p, int& s)
/* Pre: P no es vacía y esta formada por naturales, p=P; 
   s es la suma de P despues de hacer P.pop() */
/* Post: El resultado es el dominador mas alto de P */
{
  int res;

  res=p.top();
  if (res<s) {
    p.pop();
    if (not p.empty()){
      s-=p.top(); 
      /* p es P despues de hacer P.pop(), s es la suma de p despues de hacer p.pop() */
      res = dom_ef_param(p,s);
      /* HI: El resultat es el dominador mas alto de P despues de hacer P.pop() */
      // en las condiciones de los if, coincide con el dominador mas alto de P
    }
  }
  return res;
}



int main(){

  stack<int> p;
  cout << "Entra pila naturals (acabada per -1): " << endl;
  llegir_stack_int(p,-1);

  int n; 
  cout << "Cuantos elementos mas ha de tener la pila: " << endl;
  cin >> n;

  for (int i=0; i<n; ++i) p.push(i);
  cout << "Le hemos anadido " << n << " elementos: " << endl;  

  stack<int> q(p);
  cout << "Pila copiada." << endl;  
  pair<int,int> davef = dom_ef(q) ;
  cout << "Dominador mas alto (ef) y suma: " <<  davef.first << " " << davef.second << endl;
  q=p;
  cout << "Pila copiada." << endl;  
  int s = suma(p)-p.top(); 
  cout << "Dominador mas alto (ef2): " <<  dom_ef_param(q,s) << endl;
  
  cout << "Dominador mas alto inef: " << dom(p) << endl;
}
