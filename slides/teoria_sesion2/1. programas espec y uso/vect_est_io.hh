#include "Estudiant.hh"
#include <vector>

// el vector no entra dimensionado; esta versión es más modular pero
// menos eficiente
 
void leerVector(vector <Estudiant> &v)
{
  cout << "Escribe el numero de estudiantes" << endl;
  int numEst;
  cin >> numEst;
  v = vector<Estudiant> (numEst); 
  // una llamada a la constructora por defecto de Estudiant y numEst copias
  
  cout << "Escribe los estudiantes <DNI nota>" << endl;
  for (int i = 0; i < numEst; ++i) 
    v[i].llegir(); 
}

void escribirVector(vector < Estudiant > &v, int numEst)
{
  for (int i = 0; i < numEst; ++i) {
    v[i].escriure();
  }
}

