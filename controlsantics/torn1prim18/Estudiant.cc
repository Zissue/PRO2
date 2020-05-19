//#define NDEBUG
#include "Estudiant.hh"
#include <cassert>


Estudiant::Estudiant() {
  dni = 0;
  nota_global = -1;
}


Estudiant::Estudiant(int n) {
  assert(n >= 0 and "n ha de ser un enter positiu");

  dni = 0;
  notes_parcials = vector<double>(n,-1);
  nota_global = -1;
}


void Estudiant::modificar_nota_parcial(int i, double n) {
  assert(1 <= i and i <= notes_parcials.size() and "index i no valid");
  assert((n == -1.0 or (0 <= n and n <= MAX_NOTA)) and "nota n no valida");

  notes_parcials[i-1] = n;
}


void Estudiant::assignar_nota_global(double n) {
  assert((n == -1.0 or (0 <= n and n <= MAX_NOTA)) and "nota n no valida");

  nota_global = n;
}


int Estudiant::consultar_DNI() const {
  return dni;
}


double Estudiant::consultar_nota_parcial(int i) const {
  assert(1 <= i and i <= notes_parcials.size() and "index i no valido");

  return notes_parcials[i-1];
}

double Estudiant::consultar_nota_global() const {
  return nota_global;
}


double Estudiant::nota_maxima() {
  return MAX_NOTA;
}


int Estudiant::nombre_notes_parcials() const {
  return notes_parcials.size();
}


bool Estudiant::menor_dni(const Estudiant& e1, const Estudiant& e2) {
  return e1.dni < e2.dni;
}


void Estudiant::llegir() {
  int d; 
  cin >> d;

  assert(d >= 0 and "DNI ha de ser un enter positiu");

  dni = d;
  for (int i = 0; i < notes_parcials.size(); ++i) {
     double x;
     cin >> x;
     if (0 <= x and x <= MAX_NOTA) notes_parcials[i] = x; 
  }
}


void Estudiant::escriure() const {
  cout << dni << "   nota global: ";
  if (nota_global == -1) cout << "  NP";
  else cout << nota_global;
  cout << "   notes parcials:";
  for (int i = 0; i < notes_parcials.size(); ++i) {
     if (notes_parcials[i] == -1) cout << "    NP";  
     else cout << "  " << notes_parcials[i];
  }
  cout << endl;
}
