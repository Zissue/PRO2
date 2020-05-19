// Per provar això conve implementar a més operacions de lectura i
// escriptura de piles

#include "queue.hh"

int suma_cua_int_rec(queue<int>& c)
/* Pre: c=C */
/* Post: El resultat és la suma dels elements de C */
{
  int ret;                                 //  version compacta: 
  if (c.empty()) ret = 0;    	    	   //  if(c.empty()) return 0;	   
  else{			     	    	   //  int aux = c.front();	   
    int aux = c.front();     	    	   //  c.pop();   		   
    c.pop();		     	    	   //  return suma_cua_int_rec(c)+aux;
    ret = suma_cua_int_rec(c);                 
    // en este momento, ret es la suma de C
    // menos el primer elemento
    ret+= aux;           
  }				    
  return ret;			    	   
}				     





int suma_cua_int_it(queue<int> c)
/* Pre: c=C */
/* Post: El resultat és la suma dels elements de C */
{
  int ret=0;
  while(not c.empty()){
    ret += c.front();
    c.pop();
  }
  return ret;
}




// amb cues d'estudiants 


bool cerca_cua_Estudiant_rec(queue<Estudiant>& c, int x)
/* Pre: c=C */
/* Post: El resultat ens diu si x és un element de C o no */
{
  bool ret;
  if(c.empty()) ret=false;
  else if (c.front().consultar_DNI() == x) ret = true;
  else {
    c.pop();
    ret = cerca_cua_Estudiant_rec(c,x);
  }
  return ret;
}



bool cerca_cua_Estudiant_it(queue<Estudiant> c, int x)
/* Pre: c=C */
/* Post: El resultat ens diu si x és un element de C o no */
{
  bool ret=false;
  while(not c.empty() and not ret){
    if (c.front().consultar_DNI() == x) ret = true;
    else c.pop();
  }
  return ret;
}



bool cues_iguals_rec(stack<int>& c1, stack<int>& c2)
/* Pre: c1=C1, c2=C2 */
/* Post: El resultat ens indica si C1 i C2 són iguals */
{
  bool ret;
  if(c1.empty() and c2.empty()) ret = true;
  else if (c1.empty() and not c2.empty()) ret = false;
  else if (not c1.empty() and c2.empty()) ret = false;
  else if (c1.front() != c2.front()) ret = false;
  else {
    c1.pop();
    c2.pop();
    ret = cues_iguals_rec(c1,c2);
  }
  return ret;
}


bool cues_iguals_rec(stack<int>& c1, stack<int>& c2)
/* Pre: c1=C1, c2=C2, c1.size() = c2.size() */
/* Post: El resultat ens indica si C1 i C2 són iguals */
{
  if (c1.empty() and c2.empty()) return true;  // versio compacta
  if (c1.front() != c2.front()) return false;
  c1.pop();
  c2.pop();
  return cues_iguals_rec(c1,c2);
}

bool cues_iguals_it(stack<int> c1, stack<int> c2)
/* Pre: c1=C1, c2=C2 */
/* Post: El resultat ens indica si C1 i C2 són iguals */
{
  if (c1.size() != c2.size() ) return false;  // versio compacta
  while (not c1.empty()){
    if (c1.front()!=c2.front()) return false;
    c1.pop();
    c2.pop();
  }
  return true;
}


void sumar_k_cua_it(queue<int>& c, int k)
/* Pre: c=C */
/* Post: Cada element de c és la suma de l’element de C a la mateixa posició
   i el valor k */
{
  queue<int> c_aux;
  while (not c.empty()){
    int aux= c.front();          //c.front()+=k noooo!
    aux+=k;
    c.pop();
    c_aux.push(aux);
  }
  c=c_aux; // això indica que la solució és dolenta
}



void sumar_k_cua_it2(queue<int>& c, int k)
/* Pre: c=C  */ 
/* Post: Cada element de c és la suma de l'element de C 
   a la mateixa posició i el valor k */
{ 

}

/*
c = 1 2 3 4 5   k = 100

c = 2 3 4 5 101 <-- tras la primera vuelta

c = 3 4 5 101 102  <-- tras la segunda vuelta
...

c = 101 102 103 104 105
*/

// Si queremos que los elementos sumados vayan a una cola nueva
// (version función) no hay problema

queue<int> suma_k_cua_fun_it(queue<int> c, int k)
/* Pre: c=C */
/* Post: Cada element del resultat és la suma de l'element de C a la 
   mateixa posició i el valor k */
{
  queue<int> res;
  while (not c.empty()){
    int aux= c.front();
    aux+=k;
    c.pop();
    res.push(aux);
  }
  return res;
}


// En cualquier caso, la versión recursiva "natural" de la acción no
// es interesante, ya que colocar un elemento al principio de la cola es caro;
// si que se podría obtener la cola sumada invertida e invertirla despues

// Se puede hacer bien por inmersion, pero simplemente es una version
// iterativa disfrazada

void sumar_k_rec2(queue<int> &s, int k)
/* Pre: s = S */
/* Post: s es S on s'ha sumat k tots els elements */
{
  sumark_rec2_aux(s,k,s.size());
}
 
void sumark_rec2_aux(queue<int> &s, int k, int i)
/* Pre: s = S, 0<=i<=s.size() */
/* Post: s es S on s'ha sumat k als i primers elements i aquests
   s'han mogut al final, al mateix ordre */
{
  if (i>0){ // implica que c no es vacia
    s.push(s.front()+k);
    s.pop();
    sumark_rec2_aux(s,k,i-1);
  }
}

// c = 1 2 3 4 5   k = 100 i=5

// despues del primer push y del primer pop y con la i ya restada

// c = 2 3 4 5 101 k=100 i=4

// tras 4 "fases" mas

// c = 101 102 103 104 105
