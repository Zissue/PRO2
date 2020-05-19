



int cerca_dicot(const vector<int> &v, int x)
/* Pre: v.size()>0, v està ordenat de menor a major DNI */
/* Post: Si x es troba a v, llavors el resultat és una posició que el conté;
   si no, el resultat és -1. */
{
  return cerca_dicot_aux(v,x,0,v.size()-1);
}


int cerca_dicot_aux(const vector<Estudiant> &v, int esq, int dre, int x)
/* Pre:  v[esq..dre] està ordenat de menor a major DNI, 
         0 <= esq <= v.size(), -1 <= dre < v.size(), esq <= dre+1 */
/* Post: si x es troba com a DNI a v[esq..dre], llavors el resultat és
   una posició que el conté; si no, el resultat és -1 */

// Forma compacta:

{
  if (esq > dre) return -1;
  int mig = (esq + dre)/2; // mig = index mig entre esq i dre
  if (x < v[mig].consultar_DNI()) return cerca_dicot_aux(v, x, esq, mig - 1);
  if (x > v[mig].consultar_DNI()) return cerca_dicot_aux(v, x, mig + 1, dre);
  return mig;
}

// Forma expandida

{
int i; 
 if (esq > dre) i = -1;  // v[esq..dre] és buit;
 else {
  int mig = (esq + dre)/2;
  if (v[mig]==x) i = mig;
  else if (x < v[mig].consultar_DNI()) i = cerca_dicot_aux(x, v, esq, mig - 1);
  /* HI: si n es troba com a DNI a v[esq..mig-1], i és una posició que el conté;
     si no, el resultat és -1 */
  else i = cerca_dicot_aux(x, v, mig + 1, dre);
  /* HI: si n es troba com a DNI a v[mig+1..dre], i és una posició que el conté;
     si no, el resultat és -1 */
 }
return i;
}

-----------------------------------------------------------------------------

Justificacion: ver pag 28 de los apuntes (edicion mar-12)

  A partir de Pre + esq<=dre + mig=(esq + dre)/2 hay que demostar:

1) que los accesos a las posiciones del vector son correctos: 0<=mig<v.size()

2) que se cumplen las precondiciones de las llamadas: 

0 <= mig+1 <= v.size(), -1 <= mig-1 < v.size(), mig <= dre, esq <= mig

3) que los parámetros decrecen en cada llamada: usamos la expresión dre+1-esq

dre+1-(mig+1) < dre+1-esq, (mig-1)+1-esq < dre+1-esq 

(por artimetica, es lo mismo que esq < mig+1, mig-1 < dre, que ya esta cubierto por el apartado anterior)


