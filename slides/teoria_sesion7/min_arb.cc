#include "ArbIOint.hpp"

int minarb1(Arbre<int> &a)
/* Pre: a=A, A no és buit */
/* Post: el resultat és el valor mínim de A */
{
  int m;
  m = a.arrel();
  Arbre<int> a1;
  Arbre<int> a2;
  a.fills(a1,a2);
  if (not a1.es_buit() and not a2.es_buit()) {
    int m1 =  minarb1(a1);
    int m2 =  minarb1(a2);
  /* HI: m1 és el valor mínim del hi de A;
         m2 és el valor mínim del hd de A; */
    if (m1<m) m=m1;
    if (m2<m) m=m2;
  }
  else  if (not a1.es_buit()) {
    int m1 =  minarb1(a1);
    /* HI: m1 és el valor mínim del hi de A; */
    if (m1<m) m=m1;
  }
  else  if (not a2.es_buit()) {
    int m2 =  minarb1(a2);
    /* HI: m2 és el valor mínim del hd de A; */
    if (m2<m) m=m2;
  }
  return m;
}


void minarb2(Arbre<int>& a, int& m)
/* Pre: a=A, A no és buit, m=M */
/* Post: m és el mínim entre M i el valor mínim de A */
{
 int  maux = a.arrel();
 if (maux<m) m = maux;
 Arbre<int> a1;
 Arbre<int> a2;
 a.fills(a1,a2);
 if (not a1.es_buit()) minarb2(a1,m);
 /* HI1: m es el minimo entre la raiz de A, su hi y M */ 
 if (not a2.es_buit()) minarb2(a2,m);
 /* HI2: m es el minimo entre la raiz de A, su hi, su hd y M  */
}

// - el caso directo esta implicito: si los dos subarboles son vacios,
//   el minimo es el menor entre m y la raiz
//
//   Idea: HI1 y HI2 se cumplen aun si no se entra en los correspondientes ifs!

// - si se entra al primer if, pero no al segundo, el minimo es 
//   el menor entre m, la raiz y el minimo de A1 (que se obtiene
//   con la recursividad)
// 
// - si se entra al segundo if, pero no al primero, el minimo es 
//   el menor entre m, la raiz y el minimo de A2 (que se obtiene
//   con la recursividad)
// 
// - si se entra a los dos ifs, el minimo es el menor entre m, la raiz, 
//   el minimo de A1 y el minimo de A2; el minimo de los 3 primeros 
//   se obtiene con la primera llamada (H1) y pasandolo como parametro
//   de la segunda, el resultado es el definitivo
// 
//
// Decrecimiento: los parametros de las llamadas (cualquiera de los subaboles 
// de A) es menor que A

int main(){

  Arbre<int> a;
  llegir_arbre_int(a,0);
  int n;
  Arbre<int> b;
  b=a;
  cout << "Escrivim b per veure que es igual que a" << endl;
  escriure_arbre_int(b);
  cout << endl;
  int min=a.arrel(); // al loro!!!!!
  //  min=minarb1(b);
  min=a.arrel();
  minarb2(b,min);
  cout << "minim: " <<min  << endl;
  cout << "Escrivim b per veure que s'ha destruït durant l'operació" << endl;
  escriure_arbre_int(b);
  cout << endl;
  cout << "Escrivim a per veure que no s'ha modificat durant l'operació" << endl;
  escriure_arbre_int(a);
  cout << endl;
}
