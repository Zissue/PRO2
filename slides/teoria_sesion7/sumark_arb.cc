void sum_k(Arbre<int> &a, int k)
/* Pre: a=A */
/* Post: a �s un arbre com A per� amb k sumat a tots els nodes */
{
  if (not a.es_buit()){
    int x = a.arrel()+k;
    Arbre<int> a1;
    Arbre<int> a2;
    a.fills(a1,a2);
    sum_k(a1,k);
    sum_k(a2,k);
    /* HI: a1 �s un arbre com el f.e. d'A per� amb k sumat a tots els nodes
           a2 �s un arbre com el f.d. d'A per� amb k sumat a tots els nodes */
    a.plantar(x,a1,a2);
  }
}

          1                                 11
        /   \                             /    \
 a=    2     4      sum_k con k= 10      12     14
        \                                  \ 
         3                                  13
