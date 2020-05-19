



void mergesort(vector<double>& v)
/* Pre: cert */
/* Post: els elements de v són els inicials però ordenats creixentment */
{
  ordena_per_fusio(v,0,v.size()-1);
}









void ordena_per_fusio(vector<double>& v, int e, int d) 
/* Pre: 0 <= e <= d < v.size() */
/* Post: els elements de v[e..d] son els inicials, pero ordenats creixentment */
{
  if (e < d) {
    int m = (e + d)/2;
    ordena_per_fusio(v, e, m);
    /* HI: els elements de v[e..m] son els inicials, pero ordenats creixentment */
    ordena_per_fusio(v, m + 1, d);
    /* HI: els elements de v[m+1..d] son els inicials, pero ordenats creixentment */
    fusiona(v, e, m, d);
  }
}


void fusiona(vector<double>& v, int e, int m, int d)
/* Pre: 0<= e <= m <= d < v.size() i v[e..m] i v[m+1..d], per separat, 
   son ordenats creixentment */
/* Post: els elements de v[e..d] son els inicials, però ordenats creixentment
   i la resta de v no ha canviat */



-----------------------------------------------------------------------------

  Justificacion: similar a la de la busqueda dicotomica; ver pag 28 de los 
  apuntes (edicion mar-12)

  A partir de Pre + e<d + m=(e + d)/2 hay que demostrar

1) que se cumplen las precondiciones de las llamadas: 

   0<=e<=m<v.size(), 0<=m+1<=d<v.size(),

2) que los parámetros decrecen en cada llamada: usamos la expresión d+1-e

   m+1-e < d+1-e, d+1-(m+1) < d+1-e (por artimetica, es lo mismo que
   m<d, e<m+1, que ya esta cubierto por el apartado anterior)

// Hay que descomponer en dos casos: e+d par y e+d impar.

3) que se cumple la precondición de fusiona:
 
   0<= e <= m <= d < v.size() (tambien cubierto por el apartado 1)
