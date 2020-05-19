

void arrodonir_vector(vector<Estudiant> &vest)
/* Pre: cert */
/* Post: vest t� les notes dels estudiants arrodonides respecte
   al seu valor inicial */
{
  int numEst = vest.size();
  for (int i=0; i<numEst; ++i) {
    /* mirem si vest[i] t� nota */
    if (vest[i].te_nota()) {
      /* obtenim la nota de vest[i] arrodonida */
      double aux = arrodonir_double(vest[i].consultar_nota());
      /* modifiquem la nota de vest[i] amb la nota arrodonida */
      vest[i].modificar_nota(aux);
    }	
  }
}

double arrodonir_double(double r)
/* Pre: cert */
/* Post: El resultat �s el valor de original de r arrodonit a 
   la d�cima m�s propera (i m�s gran si hi ha empat) */
{  
  return int(10.*(r + 0.05)) / 10.0;
} 

// Ejercicio: obtener otra versi�n de arrodonir_vector, que use la auxiliar
// redondear_e_a del programa red1.cpp en lugar de arrodonir_double


