// preorden version funcion: ineficiente por las copias de las asignaciones

list<int> preordre(Arbre<int>& a)
/* Pre:  a = A */
{ 
  list<int> l; 
  if (not a.es_buit()) { 
    int node=a.arrel(); 
    Arbre<int> a1;
    Arbre<int> a2;
    a.fills(a1,a2);
    l=preordre(a1); 
    list<int> m; 
    m=preordre(a2); 

    // node es la raiz de A, l es el preorden del hi de A, m es el preorden del hd de A
    l.insert(l.begin(),node); 
    // l es la raiz de A, seguida del preorden del hi de A
    l.splice(l.end(),m);
    // l es la raiz de A, seguida del preorden del hi de A,,
    // seguida del preorden del hd de A <=> l es el preorden de A
  return l; 
} 
 
  // esto es ineficiente, por las sucesivas asignaciones de listas; el resto
  // de versiones las haremos void, pasando la lista por referencia

void inordre(Arbre<int>& a, list<int>& l)
/* Pre: a=A, l=L */
/* Post: l conté L seguit dels nodes d'A en inordre */
{
  if (not a.es_buit()){
    int node=a.arrel();
    Arbre<int> a1;
    Arbre<int> a2;
    a.fills(a1,a2);
    inordre(a1,l);
    // l conté L seguit dels nodes del hi de A
    l.insert(l.end(),node);
    // l conté L seguit dels nodes del hi de A, seguits de l'arrel de A
    inordre(a2,l);
    // l conté L seguit dels nodes del hi de A, seguits de l'arrel de A,
    // seguit dels nodes del hd de A
  }
}


void postordre(Arbre<int>& a, list<int>& l)
/* Pre: a=A, l=L */ 
/* Post: l conté L seguit dels nodes d'A en postordre */
{ 
  if (not a.es_buit()) {
    int node=a.arrel();
    Arbre<int> a1; 
    Arbre<int> a2; 
    a.fills(a1,a2); 
    postordre(a1,l);
    postordre(a2,l); 
    l.insert(l.end(),node);
  } 
} 



void nivells(Arbre<int>& a, list<int>& l)
/* Pre: a=A, l és buida */
/* Post: l conté els nodes d'A en ordre creixent respecte al nivell
   al qual es troben, i els de cada nivell en ordre d'esquerra a dreta */
{
  if(not a.es_buit()){
    queue <Arbre<int> > c; 
    int node;
    c.push(a); 
    while(not c.empty()){
      a = c.front(); // copia: ineficient
      node = a.arrel();
      l.insert(l.end(),node);
      Arbre<int> a1;
      Arbre<int> a2; 
      a.fills(a1,a2);
      if (not a1.es_buit()) c.push(a1); // copia: ineficient
      if (not a2.es_buit()) c.push(a2); // copia: ineficient
      c.pop(); 
    }
  } 
} 


void nivells_rec_aux(queue<Arbre<int> >& c, list<int>& l)
/* Pre: c=C, C no conté cap arbre buit , l=L */
/* Post: l és L seguit dels nodes dels arbres de C en ordre creixent
   respecte al nivell al qual es troben; els nodes del mateix nivell,
   si són d'arbres diferents, apareixen a l'ordre al qual hi són a C,
   si són d'un mateix arbre apareixen en ordre d'esquerra a dreta */
{
  if(not c.empty()){
    Arbre<int> a;
    a=c.front();
    c.pop();
    int node=a.arrel();
    Arbre<int> a1; 
    Arbre<int> a2; 
    a.fills(a1,a2); 
    if(not a1.es_buit()) c.push(a1);
    if(not a2.es_buit()) c.push(a2);
    l.insert(l.end(),node);
    nivells_rec_aux(c,l);
  }
} 


void nivells_rec(Arbre<int>& a, list<int>& l) 
/* Pre: a=A, l és buida */ 
/* Post: l conté els nodes d'A en ordre creixent respecte al nivell 
   al qual es troben, i els de cada nivell en ordre d'esquerra a dreta */ 
{ 
  if(not a.es_buit()){
    queue <Arbre<int> > c;
    c.push(a); 
    nivells_rec_aux(c,l);
  } 
} 


void preordre_it(Arbre<int>& a, list<int>& l)
  /* Pre: a = A, l es vacia */
  /* Post: l es el recorrido en preorden de A */ 
{
  stack<Arbre<int> > p; 
  p.push(a);
  while (not p.empty()) {
    a = p.top();
    p.pop();
    int node=a.arrel();
    Arbre<int> a1;
    Arbre<int> a2;
    a.fills(a1,a2);
    l.insert(l.end(), node);
    if (not a2.es_buit()) p.push (a2);
    if (not a1.es_buit()) p.push (a1);
  }
}
