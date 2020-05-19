// ver apuntes de Eficiencia, version nov-13, pag 7
//
// Sucesion de Fibonacci:
//      fib(0)= 0
//      fib(1)= 1
// n>1: fib(n) = fib(n-1)+ fib(n-2)


#include "utils.PRO2"
#include <vector>

// imersion por resultados
pair<double,double> fib1 (int n) 
/* Pre: n és un enter >0 */
/* Post: el primer component del resultat és fib(n); el segon és fib(n-1) */
{
  pair<double, double>  y;
  if (n==1)  {y.first=1; y.second=0;}
  else {
    y = fib1(n-1);
    /* HI: y.first=fib(n-1), y.second=fib(n-2) */
    double aux;
    aux=y.first;
    y.first=y.first+y.second;
    y.second=aux;
  }
  return y;
}

// original eficiente, que usa la anterior
double fib_ef (int n)
/* Pre: n és un enter >=0 */
/* Post: el resultat és fib(n) */
{
  double res;
  if (n==0) res=0;
  else {
    pair<double, double> y;
    y=fib1 (n);
    res=y.first;
  }
  return res;
}

// imersion por datos
double fib_param(int n, int i, double f1, double f2)
/* Pre: 0<i<=n, f1=fib(i-1), f2=fib(i) */
/* Post: el resultat és fib(n) */
{
  double f;
  if (i==n)   f=f2;
  else f=fib_param(n,i+1,f2,f1+f2);
  return f;
}

// original eficiente segunda version, que usa la anterior
double fib_ef_param (int n)
/* Pre: n és un enter >=0 */
/* Post: el resultat és fib(n) */
{
  double res;
  if (n==0) res=0;
  else res=fib_param (n,1,0,1);
  return res;
}

/// original ineficiente
double fib (int n){
  double res;
  if (n<2) res = n;
  else res=fib(n-1)+fib(n-2);
  return res;
}

/*
fib(10)= fib(9) + fib(8) = (fib(8) + fib(7)) + (fib(7) + fib(6)) = 
  ((fib(7)+fib(6)) + (fib(6)+fib(5)) + ((fib(6)+fib(5)) + (fib(5)+fib(4)))
...

se ve como cada vez hay mas calculos repetidos
*/

/* Otra version, aun mejor: si calculamos la potencia n-1 de la matriz

0 1
1 1

la posicion inferior derecha del resultado contiene fib(n)

 */

typedef vector <vector<double> > Matriz;

void producte_Matriz(const Matriz& m1, const Matriz& m2, Matriz& prod)
/* Pre: m1 y m2 son multiplicables */
/* Post: prod = m1*m2 */
 
void pot_mat(const Matriz& m, int n, Matriz& res, int& numprod){
  /* Pre: n>0 */
  /* Post: res = m^n; numprod = numero de productos realizados (comprobacion de eficiencia) */
  res = Matriz (m.size(), vector<double>( m[0].size(),0));
  if (n==1) {res = m; numprod=0;}
  else 
    if (n%2==0) {// usamos el cuadrado si la potencia es par
      Matriz res2(m.size(), vector<double>( m[0].size(),0));
      pot_mat(m,n/2,res2,numprod); ++numprod;
      producte_Matriz(res2,res2,res);
    }
    else {
      Matriz res2(m.size(), vector<double>( m[0].size(),0));
      pot_mat(m,n-1,res2,numprod); ++numprod;
      producte_Matriz(res2,m,res);
  }
} 
// si en vez de usar el producto normal, cableamos el de
// matrices 2x2, queda mejor y si aprovechamos el hecho de que
// todas las matrices que aparecen son de la forma 
// a b
// b a+b , el cuadrado se puede programar aun mejor,


double fib_log(int n){
  /* */
  if (n<2) return n;
  else {
    Matriz aux(2, vector<double>(2,0));
    aux[0][0]=0;  aux[0][1]=1;   aux[1][0]=1;  aux[1][1]=1; 
    Matriz res; //(2, vector<double>(2,0));
    int np;
    pot_mat(aux,n-1,res,np);
    cout << "(num. prod. )" << np <<endl;
    return res[1][1];
  }
}

int
main ()
{
  int n; cout << "numero" << endl; 
  cin >> n;
  //cout.precision(50); // no da mas de 32
  cout << "la fib ultrarapida es " <<  fib_log(n) << endl;
  cout << "la fib rapida es " <<  fib_ef(n) << endl;
  cout << "la otra fib rapida es " <<  fib_ef_param(n) << endl;
  
  cout << "la fib lenta es " << fib(n) << endl;
}
