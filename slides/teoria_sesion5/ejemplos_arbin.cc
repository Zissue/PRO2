// para probar esto conviene implementar ademas operaciones 
// de lectura y escritura de arboles

int mida(Arbre<int>& a)
/* Pre: a=A */
/* Post: El resultat és el nombre de nodes de l'arbre A */
{
  int x;
  if (a.es_buit()) x = 0;
  else{
    //  int arrel= a.arrel(); SI NO QUIERO QUE a QUEDE VACIO
    Arbre<int> a1, a2;
    a.fills(a1,a2);
    int y = mida(a1);
    int z = mida(a2);   
    x = y + z + 1;
    //  a.plantar(arrel, a1, a2); SI NO QUIERO QUE a QUEDE VACIO
  }
  return x;
}



int altura(Arbre<int>& a)
/* Pre: a=A */
/* Post: El resultat és la longitud del camí més llarg de l'arrel 
   a una fulla de l'arbre A */
{
  int x;
  if (a.es_buit()) x = 0;
  else{
    Arbre<int> a1, a2;
    a.fills(a1,a2);
    int y = altura(a1);
    int z = altura(a2);
    if (y>=z) x = y + 1;
    else x = z + 1;
  }
  return x;
}


bool cerca(Arbre<int>& a, int x)
/* Pre: a=A */
/* Post: El resultat indica si x és a l'arbre A o no */
{
  // versió expandida             // versió compacta
  bool b;
  if (a.es_buit()) b=false;       if (a.es_buit()) return false;
  else if (a.arrel()==x) b=true;  if (a.arrel()==x) return true;
  else{                           Arbre<int> a1, a2;
    Arbre<int> a1, a2;            a.fills(a1, a2); 
    a.fills(a1, a2);              return cerca(a1,x) or cerca(a2,x);
    b=cerca(a1,x);
    if (not b) b=cerca(a2,x);
  }
  return b;
}


bool iguales(Arbre<int>& a1, Arbre<int>& a2){
/* Pre: a1=A1, a2=A2 */
/* Post: El resultat indica si A1 i A2 són iguals o no */
  { 
    if (a1.es_buit() and a2.es_buit()) return true;
    if (a1.es_buit() and not a2.es_buit()) return false;
    if (not a1.es_buit() and a2.es_buit()) return false;
    if (a1.arrel() != a2.arrel()) return false;
    Arbre<int> a11, a12, a21, a22;            
    a1.fills(a11, a12); 
    a2.fills(a21, a22);
    return iguales(a11,a21) and iguales(a12,a22);
  }
  


void sumak(Arbre<int> &a, int k)
/* Pre: a=A */
/* Post: El valor de cada node d'a és la suma del valor del node 
   corresponent d'A i el valor k */
{
  if (not a.es_buit()){        //         2      k=10         12       
    int n=a.arrel()+k;         //       /   \                /   \     
    Arbre<int> a1,a2;          //     5       4            15     14   
    a.fills(a1, a2);           //    / \    /   \         / \    /   \ 
    sumak(a1,k);               //   6   7  1     8      16   17 11    18
    sumak(a2,k);               //  /                   /              
    a.plantar(n,a1,a2);        // 9                  19                  
  }
}

// a.arrel()+=k MAL


// ahora version con el resultado en arbol nuevo y conservando el
// contenido de a al final
Arbre<int> sumak(Arbre<int> &a, int k)
/* Pre: a=A */
/* Post: El valor de cada node del resultat és la suma del valor del node 
   corresponent d'A i el valor k, a=A */
{
  Arbre<int> b;
  if (not a.es_buit()){
    int n=a.arrel();
    Arbre<int> a1, a2, b1, b2;
    a.fills(a1,a2);
    b1=sumak(a1,k);
    b2=sumak(a2,k);
    b.plantar(n+k,b1,b2);
    a.plantar(n,a1,a2);
    // b1 = vacio , b2 = vacio, a1 = vacio, a2 = vacio   
}
  return b;
}

// lo mismo en modo void
void sumak(Arbre<int> &a, int k, Arbre<int> &b)
/* Pre: a=A, b es vacio */
/* Post: El valor de cada node de b és la suma del valor del node 
   corresponent d'A i el valor k */



Ejercicio: podar un árbol a un nivel determinado (nivel 0 = raíz)

         2      k=2           2       	 
       /   \                /   \     	 
     5       4            5       4   	 
    / \       \          / \       \ 	 
   6   7       8        6   7       8 
 -/-----\--------                           	 
 9       3                             

void podar(Arbre<int> &a, int k)
/* Pre: a=A, k>=0 */
/* Post: a es el árbol formado por los k primeros niveles de A */ 
{
  if (not a.es_buit()){
    int raiz = a.arrel(); 
    Arbre<int> a1, a2;
    if (k==0) { 
      a.a_buit();
      a.plantar(raiz,a1,a2);
    } 
    else {
      a.fills(a1,a2);
      podar(a1,k-1);
      podar(a2,k-1);
      a.plantar(raiz,a1,a2);     
    }
  }
}
 


Arbre<int> podar(Arbre<int> &a, int k)
/* Pre: a=A, k>=0 */
/* Post: el resultado es el árbol formado por los k primeros niveles de A, 
   a=A */ 
{
  Arbre<int> res;
  if (not a.es_buit()){
    int raiz = a.arrel(); 
    Arbre<int> b1,b2;
    if (k==0) res.plantar(raiz,b1,b2);
    else {
      Arbre<int> a1,a2;
      a.fills(a1,a2);
      b1=podar(a1,k-1);
      b2=podar(a2,k-1);
      res.plantar(raiz,b1,b2);
      a.plantar(raiz,a1,a2);
    }
  }
  return res;
}



Ejercicio: mayor profundidad de un arbol "a" a la que se puede llegar con 
cierta energia k, empezando el recorrido por la raiz. Los valores de los nodos 
representan el consumo de energia en el tramo anterior. De la entrada a la 
raiz ya se cuenta un tramo. 

La raiz se considera prof 0; si no se llega ni a la raíz el resultado 
ha de ser -1

     entrada       si 2<=k<=5 llegamos a prof 0;
       |           si 6<=k<=12 llegamos a prof 1;
       2           si 13<=k llegamos a prof 2
     /   \        
   5       4       si k=10 pero en vez de 6 ponemos 3, llegamos a prof 2
  / \       \ 
 6   7       8



  int supervivencia_prof_raiz(Arbre<int> &a, int k)
  /* Pre: k>=0, a=A, todos los elementos de A son >=0 */
  /* Post: el resultado es la profundidad máxima de A a la que
     se puede llegar con energia k, partiendo de la raíz */
    {
      if (a.es_buit()) return -1;
      else if (k<a.arrel())  return -1;
      else {
	Arbre<int> a1, a2;
	a.fills(a1,a2);
        int prof1, prof2;
	prof1 = supervivencia_prof_raiz(a1,k-a.arrel());
	prof2 = supervivencia_prof_raiz(a2,k-a.arrel());
        if (prof1 == -1 and prof2 == -1) return 0;
	else return 1 + max (prof1, prof2);
      }     
    }	 




Ejercicio: menor profundidad de un arbol "a" a la que se puede llegar con 
cierta energia k, empezando por las hojas. Los valores de los nodos 
representan el consumo de energia en el tramo siguiente. De la raiz a la 
salida se cuenta un tramo. 

La raiz se considera prof 0; si se supera el tramo siguiente (salida) el 
resultado ha de ser -1

     salida
       |
       2      
     /   \         k>=8 llegamos a prof -1 (salida);
   5       4       6<=k<=7 llegamos a prof 0
  / \       \      1<=k<=5 llegamos a prof 1
 1   3       5     pero si en vez de 1 ponemos 3, k ha de ser al menos 3


  int supervivencia_prof_hojas(Arbre<int> &a, int k)
  /* Pre: k>=0 a=A */
  /* Post: el resultado es la profundidad minima de A a la que
     se puede llegar con energia k partiendo de las hojas */

