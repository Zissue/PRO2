#include "Cjt_estudiants.hh" 
// se incluye la clase entera (que contiene las nuevas operaciones)

int main() {
  Cjt_estudiants c;
  c.llegir_cjt_estudiants();
  cout << "conj antes de borrar" << endl;
  c.escriure_cjt_estudiants();
  cout << "escribe el dni a borrar" << endl;
  int dni= readint();
  c.esborrar_estudiant(dni); // la op es de la clase
  cout << "conj despues de borrar" << endl;
  c.escriure_cjt_estudiants();
  cout << "estudiante de nota maxima despues de borrar" << endl;
  Estudiant e;
  e= c.estudiant_nota_max(); // la op es de la clase
  e.escriure_estudiant();  
}
