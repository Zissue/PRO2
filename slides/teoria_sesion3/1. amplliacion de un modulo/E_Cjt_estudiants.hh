#include "Cjt_estudiants.hh"

void esborrar_estudiant(Cjt_estudiants &cj_est, int dni);
/* Pre: cj_est conté un estudiant amb DNI = dni */
/* Post: cj_est conté els mateixos estudiants que el 
   paràmetre original menys l'estudiant amb DNI dni*/
  
Estudiant estudiant_nota_max(const Cjt_estudiants &cj_est);
/* Pre: cj_est conté almenys un estudiant amb nota */
/* Post: El resultat és l'estudiant de cj_est amb nota màxima */
