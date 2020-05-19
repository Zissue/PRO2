#include "Cjt_estudiants.hh"

void esborrar_estudiant(Cjt_estudiants &cj_est, int dni);
/* Pre: cj_est cont� un estudiant amb DNI = dni */
/* Post: cj_est cont� els mateixos estudiants que el 
   par�metre original menys l'estudiant amb DNI dni*/
  
Estudiant estudiant_nota_max(const Cjt_estudiants &cj_est);
/* Pre: cj_est cont� almenys un estudiant amb nota */
/* Post: El resultat �s l'estudiant de cj_est amb nota m�xima */
