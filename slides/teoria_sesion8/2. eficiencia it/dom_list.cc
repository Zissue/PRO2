#include "listIOint.hpp"

int suma(const list<int>& L, list<int>::const_iterator it)
/* Pre: it fa referencia a un element de L o L.end() */
/* Post: El resultat �s la suma dels elements d'L des del begin fins 
   a l'anterior al referenciat per it */
{
  int s=0;
  for(list<int>::const_iterator it2= L.begin();it2 != it; ++it2)
    s+=(*it2);
  return s;
}


int dom(const list<int>& L)
/* Pre: L no �s buida  i est� formada per naturals */
/* Post: El resultat �s el dominador m�s avancat de L */
{
  list<int>::const_iterator it= L.begin();
  int s=(*it); ++it;
  // Inv: s �s l'element dominador m�s avan�at de L fins l'anterior a it
  while (it != L.end()){
    if (suma(L,it)<=(*it)) s=(*it);
    ++it;
  }
  return s;
}

int dom_ef(const list<int>& L)
/* Pre: L no �s buida i est� formada per naturals */
/* Post: El resultat �s el dominador m�s avancat de L */
{
  list<int>::const_iterator it= L.begin();
  int s,aux;
  s=aux=(*it); ++it; 
  // Inv: s �s l'element dominador m�s avan�at d'L fins l'anterior a it;
  //      aux �s la suma dels elements d'L fins l'anterior a it
  while (it != L.end()){
    if (aux<=(*it)) s=(*it);
    aux+=(*it);
    ++it;
  }
  return s;
}


int main(){

  list<int> l;
  cout << "Entra llista naturals (acabada per -1): " << endl;
  llegir_llista_int(l,-1);
  int n; 
  cout << "Quants elements mes ha de tener la llista: " << endl;
  cin >> n;
 
  for (int i=0; i<n; ++i) l.insert(l.end(),i);
  cout << "Li hem afegit " << n << " elements: " <<  endl;
  
  int davef = dom_ef(l) ;
  cout << "Dominador ef m�s avancat: " <<  davef << endl;
  int dav = dom(l) ;
  cout << "Dominador m�s avancat: " <<  dav << endl;
}
