// ver apuntes de Eficiencia, version nov-13, pag 12
//
// Un arbre binari es diu balancejat si és buit o bé si els seus dos
// fills són balancejats i el valor absolut de la diferència de les
// seves altures no és més gran que 1.

#include "ArbIOint.hpp"

int abs(int n)
/* Pre: cierto */
/* Post:  El resultat es el valor absolut de n */
{
  int res =n;
  if (n<0) res =-n;
  return res;
}

int altura(Arbre<int>& a)
/* Pre: a=A */
/* Post: El resultat es la longitud del camí més llarg de l'arrel a una fulla 
   d'A */
{
  int alt;
  if (a.es_buit()) alt= 0;
  else{
    Arbre<int> a1,a2;
    a.fills(a1,a2);
    int y=altura(a1);
    int z=altura(a2);
    alt= max(y,z)+1;
  }
  return alt;
}

// version ineficiente
bool balancejat(Arbre<int>& a)
/* Pre: a=A */
/* Post: el resultat indica si l'arbre A és balancejat */
{
  bool bal;
  if (a.es_buit()) bal=true;
  else{
    Arbre<int> a1,a2;
    a.fills(a1,a2);
    Arbre<int> b1=a1;
    Arbre<int> b2=a2;
    int y=altura(b1);
    int z=altura(b2);
    /* y es l'altura d'a1, z es l'altura d'a2 */
    if (abs(y-z)>1) bal=false;
    else {
      bal=balancejat(a1);
      /* HI1: bal indica si a1 es balancejat */
      if (bal) bal=balancejat(a2);
      /* HI2: bal indica si a2 es balancejat */
    }
  }
  return bal; 
}


// version eficiente, inmersion por resultados
pair<bool,int> ebalancejat(Arbre<int>& a)
/* Pre: a=A */
/* Post: el resultat conté si l'arbre A es balancejat i l'altura d'A */
{
  pair<bool,int> res;
  if (a.es_buit()) res=make_pair(true,0);
  else{
    Arbre<int> a1,a2;
    a.fills(a1,a2);
    pair<bool,int> ba1=ebalancejat(a1);
    /* HI1: el resultat conté si el fill esq d'A es balancejat i 
       l'altura del fill esq d'A */
    pair<bool,int> ba2=ebalancejat(a2);
    /* HI2: el resultat conté  si el fill dre d'A es balancejat i 
       l'altura del fill dre d'A */
    res= make_pair(abs(ba1.second-ba2.second)<=1 and ba1.first and ba2.first,
		     max(ba1.second,ba2.second)+1);
  }
  return res;
}

// para producir arboles grandes
void generar_nivel(Arbre<int> &a, int n)
  /* Pre: n>=0, a és buit */
  /* Post: a és un arbre complet d'n nivells */
{
  if (n>0){
    Arbre<int> a1,a2;
    generar_nivel(a1,n-1);
    generar_nivel(a2,n-1);
    a.plantar(1,a1,a2);
  }

}


int main(){

  Arbre<int> a;
  //   llegir_arbre_int(a,0);
  int n; 
  cout << "Cuantos niveles ha de tener el arbol: " << endl;
  cin >> n;
  generar_nivel(a,n);

  cout << "Arbre creat" << endl;
  Arbre<int> b(a);
  cout << "Arbre copiat" << endl;
  cout << "Ef: ";
  if (ebalancejat(b).first) cout << "Es balancejat"<< endl;
  else cout << "No es balancejat"<< endl;
  cout << "Inef: ";
  if (balancejat(a)) cout << "Es balancejat"<< endl;
  else cout << "No es balancejat"<< endl;
}

