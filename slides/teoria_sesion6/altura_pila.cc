

int altura_pila_int_it(stack<int> p) // se puede pasar por valor
/* Pre: p=P */
/* Post: El resultat és el nombre d'elements de P */
{
  int ret=0;
  /* Inv: ret = "nombre d’elements de la part tractada de P" y
     p = "elements de P que queden per tractar" */
  /* Cota: altura de p */
  while (not p.empty()){
    ++ret;
    p.pop();
  }
  return ret;
}
