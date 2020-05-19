//#define NDEBUG
#include <cassert>
#include "Cjt_estudiants.hh"
#include <algorithm>


void Cjt_estudiants::ordenar_cjt_estudiants() {
  sort(vest.begin(), vest.begin() + nest, Estudiant::menor_dni);
}


int Cjt_estudiants::cerca_dicot(const vector<Estudiant>& v,
				int left, int right, int x) {
  if (left <= right) { 
     int i = (left + right)/2;
     if (x < v[i].consultar_DNI()) return cerca_dicot(v, left, i - 1, x);
     if (x > v[i].consultar_DNI()) return cerca_dicot(v, i + 1, right, x); 
     return i;
  }
  return -1;  
}  


Cjt_estudiants::Cjt_estudiants() {
  nest = 0;
  nombre_parcials = 0;
  vest = vector<Estudiant>(MAX_NEST);
}


Cjt_estudiants::Cjt_estudiants(int n) {
  nest = 0;
  nombre_parcials = n;
  vest = vector<Estudiant>(MAX_NEST, Estudiant(nombre_parcials));
}

  
int Cjt_estudiants::mida() const {
  return nest;
}

  
int Cjt_estudiants::mida_maxima() {
  return MAX_NEST;
}


int Cjt_estudiants::nombre_ex_parcials() const {
  return nombre_parcials;
}


double Cjt_estudiants::pes_parcial(int pi) const {
  assert(1 <= pi and pi <= nombre_parcials and "index pi no valid");

  return pesos_parcials[pi - 1]; 
}


pair<bool, int> Cjt_estudiants::posicio_estudiant(int dni) const {
  bool trobat; 
  int i = cerca_dicot(vest, 0, nest-1, dni);
  trobat = (i != -1);
  if (trobat) ++i;
  return make_pair(trobat, i);
}
 

Estudiant Cjt_estudiants::consultar_iesim(int i) const {
  assert(1 <= i and i <= nest and "index i no valid");

  return vest[i-1];
}

    
void Cjt_estudiants::modificar_iesim(int i, const Estudiant& e) {
  assert(1 <= i and i <= nest and "index i no valid");

  vest[i-1] = e;
  avaluacio_global_iesim(i);
}


void Cjt_estudiants::llegir() {
  pesos_parcials = vector<double>(nombre_parcials);
  // Introduir els pesos dels exàmens parcials 
  for (int i = 0; i < nombre_parcials; ++i) cin >> pesos_parcials[i];
  // Introduir el nombre d'estudiants del conjunt
  int n;
  cin >> n;
 
  assert(n <= MAX_NEST and "El nombre d'estudiants no pot ser mes gran que la mida maxima");

  nest = n;

  // Introduir el DNI de cada estudiant seguit de les seves notes en
  // els diferents exàmens parcials (utilitzant -1 per indicar que
  // l'estudiant no s'ha presentat a un parcial determinat).
  for (int i = 0; i < nest; ++i) vest[i].llegir();
  ordenar_cjt_estudiants();
  for (int i = 1; i <= nest; ++i) avaluacio_global_iesim(i); 
}


void Cjt_estudiants::escriure() const {
  for (int i = 0; i < nest; ++i) vest[i].escriure();
}


