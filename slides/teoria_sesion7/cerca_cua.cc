
bool cerca_rec_cua_Estudiant(queue<Estudiant>& c, int i)
/* Pre: i és un dni vàlid i c=C */
/* Post: El resultat ens diu si hi ha algun estudiant amb dni i a C */
{
  bool ret;
  if(c.empty()) ret = false; // CD1
  else if (c.front().consultar_DNI() == i) ret = true; // CD2
  else {// Caso recursivo
    c.pop();
    ret = cerca_rec_cua_Estudiant(c,i);
    /* HI: ret ens diu si hi ha algun estudiant amb dni i a C
       sense el primer element */
  }
  return ret;
}

// - los casos directos estan claros
//
// - despues de la llamada se cumple la proteccion del else y la HI
// 
// * prot del else: (not c.empty() and c.front() != i
// * HI: ret ens diu si hi ha algun estudiant amb dni i a C sense el primer element
//       
//   la combinacion de las dos implica que "ret" es el resultado correcto
//   para la cola completa => no hay que hacer nada mas
//
// Decrecimiento: el parametro de la llamada (C menos su front) es menor que C
