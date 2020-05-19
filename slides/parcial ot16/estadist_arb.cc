
#include "ArbIOdouble.hpp"
#include <cmath>

// primera version: los tres parametros de inmersion son de puros de salida
// mantenemos la pre original

void i_estadist(Arbre<double>& a, double& suma, double& sumacuadrados, int& tam)
// Pre: a = A es un arbre no buit
// Post: suma = suma dels elements d'A
//       sumacuadrados = suma dels quadrats dels elements d'A
//       tam = nombre dels element d'A
{
  suma = a.arrel();
  sumacuadrados = suma *  suma;
  tam = 1;
  Arbre<double> a1, a2; 
  a.fills(a1,a2);
  double s1, s2, sc1, sc2;
  s1 = s2 = sc1 = sc2 = 0;
  int t1,t2;
  t1 = t2 = 0;
  if (not a1.es_buit()) i_estadist(a1,s1,sc1,t1);
  if (not a2.es_buit()) i_estadist(a2,s2,sc2,t2);
  /* HI : para los subarboles no vacios: s1 = suma de a1; s2 = suma de a2; 
    sc1 = suma de los cuadrados de a1;sc2 = suma de los cuadrados de a2;
    t1 = num. de elem. de a1; t2 = num . de elem. de a2; en caso contrario, son 0 */
  tam += t1 + t2;
  suma += s1 + s2;
  sumacuadrados += sc1 + sc2;
}


// si aplicamos el convenio de que la suma de 0 cosas es 0, la
// inmersion es un poco mas sencilla

void i_estadist2(Arbre<double>& a, double& suma, double& sumacuadrados, int& tam)
// Pre: a = A 
// Post: suma = suma dels elements d'A
//       sumacuadrados = suma dels quadrats dels elements d'A
//       tam = nombre dels element d'A
{
  if (a.es_buit()) {suma = sumacuadrados=0.; tam = 0;}
  else {
    suma = a.arrel();
    sumacuadrados = suma *  suma;
    tam = 1;
    Arbre<double> a1, a2; 
    a.fills(a1,a2);
    double s1, s2, sc1, sc2;
    int t1,t2;
    i_estadist(a1,s1,sc1,t1);
    i_estadist(a2,s2,sc2,t2);
    /* HI :  s1 = suma de a1; s2 = suma de a2; 
       sc1 = suma de los cuadrados de a1; sc2 = suma de los cuadrados de a2;
       t1 = num. de elem. de a1; t2 = num . de elem. de a2 */
    tam += t1 + t2;
    suma += s1 + s2;
    sumacuadrados += sc1 + sc2;
  }
}


// y si aprovechamos los valores de los parametros entre las diversas
// llamadas queda aun mejor, pero la especificacion es mas complicada

void i_estadist3(Arbre<double>& a, double& suma, double& sumacuadrados, int& tam)
// Pre: a = A, suma = S, sumacuadrados = SC, tam = T 
// Post: suma = suma dels elements d'A + S
//       sumacuadrados = suma dels quadrats dels elements d'A + SC
//       tam = nombre dels element d'A + T
{
  if (not a.es_buit()){
    suma += a.arrel();
    sumacuadrados += suma *  suma;
    tam += 1;
    Arbre<double> a1, a2; 
    a.fills(a1,a2);
    double s1, s2, sc1, sc2;
    int t1,t2;
    i_estadist(a1,suma,sumacuadrados,tam);
    i_estadist(a2,suma,sumacuadrados,tam);
    /* HI : suma = S + raiz de A + suma de a1 + suma de a2;
       sumacuadrados = SC + cuadrado de raiz de A + suma de los
       cuadrados de a1 + suma de los cuadrados de a2; tam = T +1 + num. de
       elem. de a1 + num . de elem. de a2 = Post */
  }
}

void estadist(Arbre<double>& a, double& mitjana, double& desviacio)
// Pre: a = A es un arbre no buit
// Post: mitjana representa la mitjana dels elements de l'arbre A,
// desviacio representa la desviacio dels elements de l'arbre A
{

  // para la tercera version hay que dar valores 0 explictamente a los
  // tres parametros de inmersion
  double suma=0, sumacuadrados=0; 
  int tam = 0;
  i_estadist3(a, suma, sumacuadrados, tam);
  mitjana = suma/tam;
  desviacio = sqrt(sumacuadrados/tam - media*media);
}


