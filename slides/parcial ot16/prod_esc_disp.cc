// nota: el que las listas sean representaciones dispersas de vectores
// implica que estan ordenadas por "first", que no hay ningun "second"
// igual a 0 y que todas las "first" son mayores o iguales que 0

int prod_escalar(const list<pair<int,int> >& t1, const list<pair<int,int> >& t2)
/* Pre: t1 i t2 son les representacions disperses (*) de dos vectors
v1 i v2 de la mateixa longitud */
/* Post: el resultat es el producte escalar de v1 i v2 */
{
  int prod = 0;
  list<pair<int,int> >::const_iterator it1, it2;
  it1 = t1.begin();
  it2 = t2.begin();
  // Inv: si it1!=t1.end() y it1!=t1.end()) y pos = max (it1->first,
  // it2->first), entonces prod = producto escalar parcial de v1[0..pos-1] y
  // v2[0..pos-1]; en caso contrario prod es el producto escalar
  // total de v1 y v2; t1.begin() <= it1 <= t1.end(), idem it2/t2
  while (it1!=t1.end() and it1!=t1.end()){
    if (it1->first == it2->first) {
      prod += it1->second *  it2->second;
      ++it1; ++it2;
    }
    else if  (it1->first < it2->first) ++it1;
    else if  (it1->first > it2->first) ++it2;
  }
  return prod; 
}


// una version alternativa, aunque peor, consiste en introducir "pos"
// en el codigo, de forma que el bucle avance respecto a "pos"; es mas
// lenta, porque en muchas vueltas no avanzan los iteradores
 
int prod_escalar2(const list<pair<int,int> >& t1, const list<pair<int,int> >& t2)
/* Pre: t1 i t2 son les representacions disperses de dos vectors v1 i
v2 de la mateixa longitud */
/* Post: el resultat es el producte escalar de v1 i v2 */
{
  int prod = 0;
  int pos = 0;
  list<pair<int,int> >::const_iterator it1, it2;
  it1 = t1.begin();
  it2 = t2.begin();
  // Inv: prod = producto escalar parcial de v1[0..pos-1] y
  // v2[0..pos-1]; los elem de t1 anteriores a it1 son exactamente
  // aquellos cuyo first es menor que pos; los elem de t2 anteriores a
  // it2 son exactamente aquellos cuyo first es menor que pos,
  // t1.begin()<=it1<=t1.end(), t2.begin()<=it2<=t2.end() 0<=pos<=k, con
  // k = 0 si alguna de las listas es vacia y min(ultimo first de t1,
  // ultimo first de t2)+1 si no
  while (it1!=t1.end() and it1!=t1.end()){
    if (it1->first = pos and it2->first = pos) {
      prod += it1->second *  it2->second;
      ++it1; ++it2;
    }
    else if  (it1->first == pos) ++it1;
    else if  (it2->first == pos) ++it2;
    ++pos;
  }
  return prod; 
}
