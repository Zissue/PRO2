#include "Conj_estudiants.hh"

double nota_max_conj (const Cjt_estudiants &c){
  /* Pre: al menos hay un estudiante de c con nota */
  /* Post: el resultado es la nota maxima de los estudiantes de c */
  int i = 1; 
  while (not c.consultar_iessim(i).te_nota()) ++i;
  double  nota_max = c.consultar_iessim(i).consultar_nota();
  for (int j=i+1; j<=c.mida(); ++j){
    if (c.consultar_iessim(j).te_nota()){
      double nota_est = c.consultar_iessim(j).consultar_nota();
      if (nota_max< nota_est) nota_max = nota_est;
    }
  }
  return nota_max;
}
