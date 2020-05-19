

void arrodonir_vector(vector<Estudiant> &vest)
/* Pre: cert */
/* Post: vest té les notes dels estudiants arrodonides respecte
   al seu valor inicial */
{
  int numEst = vest.size();
  for (int i=0; i<numEst; ++i) {
    /* mirem si vest[i] té nota */
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
/* Post: El resultat és el valor de original de r arrodonit a 
   la dècima més propera (i més gran si hi ha empat) */
{  
  return int(10.*(r + 0.05)) / 10.0;
} 

// Ejercicio: obtener otra versión de arrodonir_vector, que use la auxiliar
// redondear_e_a del programa red1.cpp en lugar de arrodonir_double


