#include "utils.PRO2"



//e^x = suma_{i=0}^n x^i/i!
//e^x = x^0/0! + x^1/1! + x^2/2! + x^3/3! + ....

double fact(int n)
//Pre: n>=0
//Post: el resultado es n!
{
  double f = 1;
  while (n>0){
    f*=n;
    --n;
  }
  return f;
}




double pot (double a, int b)
//Pre: a>0; b>=0
//Post: el resultado es a^b
{
  double p=1;
  while (b>0) {
    p*=a;
    --b;
  }
  return p;
}



double taylore(double x, int n)
//Pre: n>=0; 
//Post: el resultado es la suma hasta n de la serie de Taylor para e^x
{
  if (x==0) return 1;
  // x!=0
  double t=1;
  int i=1;
  //Inv: t = suma hasta i-1 de la serie de Taylor para e^x
  while (i<=n) {
    t+=pot(x,i)/fact(i);
    ++i;
  }
  return t;
}



double etaylore(double x, int n)
//Pre: n>=0
//Post: el resultado es la suma hasta n de la serie de Taylor para e^x
{
  if (x==0) return 1;
  double t=1;
  double f=1;
  double p=1;
  int i=1;
  //Inv: t = suma hasta i-1 de la serie de Taylor para e^x
  //     p = x^(i-1) ; f=(i-1)!; 
  while (i<=n){
    p*=x; //p=x^i
    f*=i; //f=i!
    t+=p/f;
    ++i;
  }
  return t;
}










double eetaylore(double x, int n)
//Pre: n>=0
//Post: el resultado es la suma hasta n de la serie de Taylor para e^x
{
  if (x==0) return 1;
  double t=1;
  double pf=1;
  int i=1;
  //Inv: t = suma hasta i-1 de la serie de Taylor para e^x
  //     pf = x^(i-1)/(i-1)!; 
  while (i<=n){
    pf*=x;  //pf = x^i/(i-1)!
    pf/=i; //pf=x^i/i!
    t+=pf;
    ++i;
  }
  return t;
}


int main(){

  //cout.setf(ios::fixed);
  cout.precision(15);
  // los métodos que no controlan la precision, aunque sean ef., llegan a NaN antes de que se note la inef.
  int n;
  double x;
  cin >> x >> n; 
  cout << etaylore(x, n) << endl;
  cout << eetaylore(x, n) << endl;
  cout << taylore(x, n) << endl;
}
