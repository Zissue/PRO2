

bool piles_iguals(stack<int>& p1, stack<int>& p2 )
/* Pre: p1=P1, p2=P2, p1.size() = p2.size() */
/* Post: El resultat ens indica si P1 i P2 són iguals */
{
  bool ret;
  if(p1.empty()) ret = true; // CD1
  else if (p1.top()!=p2.top()) ret = false; // CD2
  else { // Caso recursivo
    p1.pop();
    p2.pop();
    ret = piles_iguals(p1,p2);
    /* HI: ret indica si P1 sense l’últim element afegit i P2 sense l’últim
       element afegit són iguals */
  }
  return ret;
}


// - los casos directos estan claros
// - el segundo caso esta bien planteado porque si p1 no es vacia, p2 tampoco
// - despues de la llamada se cumple la proteccion del else y la HI
// 
// * prot del else: (not p1.empty() and not p2.empty() and p1.top()==p2.top()
// * HI: ret="P1 sense l’últim element afegit i P2 sense l’últim
//          element afegit són dues piles iguals"
//
//   la combinación de las dos implica que "ret" es el resultado correcto
//   para las pilas completas => no hay que hacer nada mas
// 
// Decrecimiento: los parametros de la llamada (P1 y P2 menos sus top) 
// son menores que P1 y P2
