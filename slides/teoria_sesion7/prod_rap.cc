// version 1

int prod(int x, int y)
/* Pre: y >= 0 */
/* Post: el resultat es x*y */
{
  int p;
  if (y == 0) p = 0; // C. Directo
  else {
    if (y%2 == 0) {// C. Recursivo 1
      p = prod(x,y/2); 
      /* HI1: p = x(y/2) */ 
      p = 2*p;
    }
    else { // C. Recursivo 2
      p = prod(x,y - 1);
      /* HI2: p = x*(y-1) */
      p += x;
    }
  }
  return p;
}
// CD: si y=0 => x*y=0
// CR1: si y>0 + es par => y = 2*(y/2)  =>  x*y = 2*(x*(y/2))
//      =>  x*(y/2) se obtiene con la recursividad
//      =>  para el producto total solo falta un *2
// CR2: si y>0 => x*y = x*(y-1)+x (además y-1 < y) 
//      =>  x*(y-1) se obtiene con la recursividad
//      =>  para el producto total solo falta un +x
// Decrecimento: y es más pequeño tras cada llamada

// version 2

int prod(int x, int y)
/* Pre: y >= 0 */
/* Post: el resultat es x*y */
{
  int p;
  if (y == 0) p = 0; // C. Directo
  else {
    if (y%2 == 0) p = prod(x*2,y/2); // C. Recursivo 1
    /* HI1: p = x*2*(y/2) */ 
    else {
      p = prod(x,y - 1); // C. Recursivo 2
      /* HI2: p = x*(y-1) */
      p += x;
    }
  }
  return p;
}

// CD: si y=0 => x*y=0
// CR1: si y>0 + es par => y = 2*(y/2)  =>  x*y = x*2*(y/2) 
//      se obtiene con la recursividad y no hay que hacer nada mas
// CR2: si y>0 => x*y = x*(y-1)+x, se sigue igual que la anterior version
// Decrecimento: y es más pequeño tras cada llamada


// versiones compactas de las anteriores

int prod(int x, int y)
/* Pre: y >= 0 */
/* Post: el resultat es x*y */       
{
  if (y == 0) return 0;
  if (y%2 == 0) return prod(x,y/2)*2;   
  return prod(x,y - 1) + x;
}


int prod(int x, int y)
/* Pre: y >= 0 */
/* Post: el resultat es x*y */       
{
  if (y == 0) return 0;
  if (y%2 == 0) return prod(x*2,y/2);   
  return prod(x,y - 1) + x;
}

int prod2(int x, int y, int p) // intentarlo con recursividad final
