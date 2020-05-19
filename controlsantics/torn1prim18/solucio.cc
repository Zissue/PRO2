//#define NDEBUG
#include <cassert>
#include "Cjt_estudiants.hh"


// NOMÉS PODEU MODIFICAR AQUEST FITXER.
// AQUEST ÉS L'ÚNIC FITXER QUE S'UTILITZARÀ PER AVALUAR EL VOSTRE LLIURAMENT.

// SÓLO PODËIS MODIFICAR ESTE ARCHIVO.
// ESTE ARCHIVO ES EL ÚNICO QUE SE UTILIZARÄ PARA EVALUAR VUESTRA ENTREGA.



// Aquest mètode forma part de la implementació de la classe Cjt_estudiants.
// L'especificació d'aquest mètode és al fitxer Cjt_estudiants.hh

void Cjt_estudiants::avaluacio_global_iesim(int i) {
   Estudiant std = consultar_iesim(i);
   
   double mitja = 0.0, sum = 0.0;
   int nparcials = nombre_ex_parcials();

   for (int j = 1; j <= nparcials; j++) {
      if (std.consultar_nota_parcial(j) == -1.0) sum += pes_parcial(j);
      else mitja += pes_parcial(j) * std.consultar_nota_parcial(j);
   }

   if (sum > 0.5) std.assignar_nota_global(-1.0);
   else std.assignar_nota_global(mitja);

   vest[i-1] = std;
}

// Aquest mètode forma part de la implementació de la classe Cjt_estudiants.
// L'especificació d'aquest mètode és al fitxer Cjt_estudiants.hh

// La part de la implementació donada és correcta, però incompleta.
// Podeu completar la part que falta de la implementació en
// l'espai indicat pel comentari 

void Cjt_estudiants::parcials_presentats_aprovats() const {
  
   vector<bool> ppa(nombre_parcials,true);
   
   for (int i = 0; i < nest; i++) {
      if (vest[i].consultar_nota_global() >= 5.0) {
         for (int j = 0; j < nombre_parcials; j++) {
            if (vest[i].consultar_nota_parcial(j+1) == -1.0) ppa[j] = false;
         }
      }
   }

   cout << endl << "Examens parcials presentats per tots els estudiants aprovats: ";

   for (int i = 0; i < nombre_parcials; i++) {
      if (ppa[i]) cout << " " << i+1;
   }
   cout << endl;
}
