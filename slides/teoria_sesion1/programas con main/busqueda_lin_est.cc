#include "vect_est_io.hh"

bool busqueda_lineal(const vector<Estudiant> &v, int dni)
/* Pre: cert */
/* Post: el resultat indica si l'estudiant amb DNI = dni hi és a v */
{
  bool b = false;
  int numEst = v.size();
  int i = 0;
  while (i < numEst and not b) {
    if (v[i].consultar_DNI() == dni) b = true;
    else ++i;
  }
  return  b;
}

int main()
{
  vector < Estudiant > v;
  leerVector(v);

  int dni;
  cout << "Cual es el DNI del estudiante que quieres buscar? " << endl;
  cin >> dni;
 
  bool b = busqueda_lineal(v, dni);
  if (b)
    cout << "El estudiante esta en el vector"   << endl;
  else
    cout << "El estudiante no esta en el vector" << endl;	
}
