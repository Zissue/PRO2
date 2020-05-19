#include "E_Cjt_estudiants.hh" 
// se incluye solo el fichero con las nuevas operaciones

int main() {
  Cjt_estudiants c;
  c.llegir_cjt_estudiants();
  cout << "conj antes de borrar" << endl;
  c.escriure_cjt_estudiants();
  cout << "escribe el dni a borrar" << endl;
  int dni= readint();
  esborrar_estudiant(c,dni); // la op no es de la clase
  cout << "conj despues de borrar" << endl;
  c.escriure_cjt_estudiants();
  cout << "estudiante de nota maxima despues de borrar" << endl;
  Estudiant e;
  e = estudiant_nota_max (c); // la op no es de la clase
  e.escriure_estudiant();  
}
