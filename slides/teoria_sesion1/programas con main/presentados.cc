#include "vect_est_io.hh"

double presentats (const vector<Estudiant> &vest)
/* Pre: v conté almenys un element <=> vest.size()>0 */
/* Post: el resultat és el percentatge de presentats de vest */
{
  int numEst = vest.size();
  int n = 0;
  for (int i=0; i<numEst; ++i) if(vest[i].te_nota()) ++n;
  /* n és el nombre d'estudiants amb nota de vest */
  double p = n*100./numEst;
  return p;
}

int main()
{
  Estudiant est;
  vector < Estudiant > v;
  leerVector(v);
  cout << "Vector antes del calculo" << endl;
  escribirVector(v,v.size());
  
  double x =presentats(v);
 
  cout << "Vector original despues de redondear" << endl;
  escribirVector(v,v.size());
  cout << "Presentados :" << x << endl;
}

