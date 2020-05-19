// VERSION 1: BUCLE HACIA ADELANTE

void arrodonir_vector(vector<Estudiant> &vest)
/* Pre: cert */
/* Post: vest t� les notes dels estudiants arrodonides respecte
   al seu valor inicial */
{
  int numEst = vest.size(); int i=0;
  /* Inv: vest[0..i-1] t� les notes dels estudiants arrodonides
     respecte al seu valor inicial, 0 <= i <= numEst */
  /* Cota: numEst-i */
  while ( i<numEst) {
    /* mirem si vest[i] t� nota */
    if (vest[i].te_nota()) {
      /* obtenim la nota de vest[i] arrodonida */
      double aux = arrodonir(vest[i].consultar_nota());
      /* modifiquem la nota de vest[i] amb la nota arrodonida */
      vest[i].modificar_nota(aux);
    }
    ++i;
  }
}

double arrodonir(double r)
/* Pre: cert */
/* Post: El resultat �s el valor de original de r arrodonit a 
    la d�cima m�s propera (i m�s gran si hi ha empat) */
{  
  return int(10.*(r + 0.05)) / 10.0;
} 


// VERSION 1: BUCLE HACIA ATRAS

void arrodonir_vector2(vector<Estudiant> &vest)
/* Pre: cert */
/* Post: vest t� les notes dels estudiants arrodonides respecte
   al seu valor inicial */
{
  int i = vest.size()-1;
  /* Inv: vest[i+1..vest.size()-1] t� les notes dels estudiants arrodonides
     respecte al seu valor inicial, -1 =< i <= vest.size()-1 */
  /* Cota: i+1 */
  while ( i>=0) {
    /* mirem si vest[i] t� nota */
    if (vest[i].te_nota()) {
      /* obtenim la nota de vest[i] arrodonida */
      double aux = arrodonir(vest[i].consultar_nota());
      /* modifiquem la nota de vest[i] amb la nota arrodonida */
      vest[i].modificar_nota(aux);
    }
    --i;
  }
}
