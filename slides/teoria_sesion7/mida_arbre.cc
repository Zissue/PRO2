int mida(Arbre<int> &a)
/* Pre: a=A */
/* Post: El resultat és el nombre de nodes de l’arbre inicial A */
{
  int x;
  if (a.es_buit()) x = 0;
  else{
    Arbre<int> a1;
    Arbre<int> a2;
    a.fills(a1,a2);
    int y = mida(a1);
    int z = mida(a2);
    /* HI: y="nombre de nodes del fill esquerre d’A" i
       z="nombre de nodes del fill dret d’A" */
    x = y+z+1;
  }
  return x;
}

// - el caso directo esta claro
//
// - despues de las llamadas se cumple la proteccion del else y la HI
// 
// * prot del else: (not a.es_buit())
// * HI: ver comentario
//       
//   como el tamaño de un arbol no vacio es la suma de los tamaños de sus 
//   subarboles más 1, la combinacion de las dos implica que x es el resultado 
//   correcto
//
// Decrecimiento: los parametros de las llamadas (cualquiera de los subaboles 
// de A) es menor que A
