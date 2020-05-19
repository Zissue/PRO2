#include "Estudiant.hh"

// Redondear la nota de un Estudiant, versión función

Estudiant redondear_e_f(const Estudiant & est)
/* Pre: est tiene nota */
/* Post: el resultado es un estudiante como "est" pero con la nota
   redondeada */
{
  Estudiant est2(est.consultar_DNI());  // constructora con parámetro
  double notaR = ((int) (10.0 * (est.consultar_nota() + 0.05))) / 10.0;
  est2.afegir_nota(notaR);
  return est2;
}

// Redondear la nota de un Estudiant, versión acción

void redondear_e_a(Estudiant & est)
/* Pre: est tiene nota */
/* Post: est pasa a tener su nota original redondeada */
{
  est.modificar_nota(((int) (10. * (est.consultar_nota() + 0.05))) / 10.0);
}

// en el main usamos las dos, pero si se puede prescindir del
// estudiante original, es mejor la versión acción

int main()
{
  Estudiant est; // constructora por defecto
  cout << "Escribe un estudiante <DNI nota>" << endl;
  est.llegir();
  if (est.te_nota()) { // comprobamos la precondicion
    // est=redondear_e_f(est);	// version funcion
    redondear_e_a(est);    // version accion 
  }
  cout << "El estudiante con la nota redondeada, o NP: " <<endl;
  est.escriure();
}
