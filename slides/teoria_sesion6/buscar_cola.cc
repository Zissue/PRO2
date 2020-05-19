
bool cercar_iter_cua_int(queue<int> c, int i)
/* Pre: c=C */
/* Post: El resultat ens diu si i és un element de C o no */
{
  bool ret=false;

  /* Inv: ret = "el element i està a la part tractada de C" i
     c es la part de C que queda per tractar. */
  /* Cota: longitud de c */

  while(not c.empty() and not ret){
    ret = (c.front() == i);
    c.pop();
  }
  return ret;
}
