#include "vect_est_io.hh"

/* Auxiliar: redondea un double */

double arrodonir(double r)
/* Pre: cert */
/* Post: El resultat �s el valor de original de r arrodonit a 
   la d�cima m�s propera (i m�s gran si hi ha empat) */
{  
  return int(10.*(r + 0.05)) / 10.0;
} 

/* Redondear vector, version acci�n */

void arrodonir_vector(vector<Estudiant> &vest)
/* Pre: cert */
/* Post: vest t� les notes dels estudiants arrodonides respecte
       al seu valor inicial */
{
  int numEst = vest.size();
  for (int i=0; i<numEst; ++i) {
      /*mirem si vest[i] t� nota*/
      if (vest[i].te_nota()) {
         /* obtenim la nota de vest[i] arrodonida */
         double aux = arrodonir(vest[i].consultar_nota());
         /* modifiquem la nota de vest[i] amb la nota arrodonida */
         vest[i].modificar_nota(aux);
      }	
  }
}

int main()
{
  Estudiant est;
  vector < Estudiant > v;
  leerVector(v);
  cout << "Vector antes de redondear" << endl;
  escribirVector(v,v.size());
  
  arrodonir_vector(v);
 
  cout << "Vector  despues de redondear" << endl;
  escribirVector(v,v.size());
}

