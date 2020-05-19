// para probar esto conviene implementar ademas operaciones 
// de lectura y escritura de listas


int suma_llista_int(const list<int>& l)
/* Pre: cert */
/* Post: El resultat és la suma dels elements de l */
{
  list<int>::const_iterator it;
  int s=0;
  for (it=l.begin(); it != l.end(); ++it)
    s+=*it;
  
  return s;
}

// alternativas

// for (list<int>::const_iterator it=l.begin(); it != l.end(); ++it)  s+=*it;

// for (auto it=l.begin(); it != l.end(); ++it) s+=*it; solo C++11

// for (const auto& x : l) s+=*x; (!)  solo C++11 


bool pert_llista_int(const list<int>& l, int x)
/* Pre: cert */
/* Post: El resultat indica si x hi és o no a l */
{
  bool b = false;
  list<int>::const_iterator it= l.begin();
  while (it != l.end() and not b){
    if (*it == x) b= true;
    else ++it;
  }
  return b;
}



bool pert_llista_Estudiant(const list<Estudiant>& l, int x)
/* Pre: cert */
/* Post: El resultat ens indica si hi ha algun estudiant amb dni x a l o no */
{
  bool b =false;
  list<Estudiant>::const_iterator it = l.begin();
  b=false;
  while (it != l.end() and not b){
    if (it->consultar_DNI() == x)  b = true;
    // originalment: if ((*it).consultar_DNI() == x) b= true;
    else ++it;
  }
  return b;
}



void suma_llista_k(list<int>& l, int k)
/* Pre: l=L */
/* Post: El valor de cada element d’l és el valor corresponent al d'L més k */
{
  list<int>::iterator it;
  for (it=l.begin(); it != l.end(); ++it){
    *it+=k;
  }
}



// Solució alternativa: funciona, però és molt més dolenta 

void suma_llista_k(list<int>& l, int k)
/* Pre: l=L */
/* Post: El valor de cada element d’l és el valor corresponent a L més k */
{
  list<int>::iterator it= l.begin();
  while (it != l.end()){
    int aux = (*it) + k;
    it = l.erase(it);
    l.insert(it,aux);  // no s'ha de fer ++it !!!!!
  }
}


// retornant una llista nova

list<int> suma_llista_k(const list<int>& l, int k)
/* Pre: cert */
/* Post: Cada element del resultat es la suma de k i l’element d’l1 a la seva
   mateixa posició */
{
  list<int>::const_iterator it=l.begin();
  list<int> l2;
  list<int>::iterator it2=l2.begin();
  while (it != l.end()) {
    l2.insert(it2,*it+k);
    ++it;
  }
  return l2;
}

// compte amb controlar les iteracions amb size()

// aixo no esta malament (encara que es pot fer mes eficient)

int suma_llista_int(const list<int>& l)
/* Pre: cert */
/* Post: El resultat és la suma dels elements de l */
{
  list<int>::const_iterator it=l.begin();
  int s=0;
  for (int i=0; i<.size(); ++i){
    s+=*it;
    ++it;
  }
  return s;
}

// aixo esta malament

void duplicar_llista(list<int>& l)
/* Pre: l=L */
/* Post: l passa a ser L seguida d'L una altra vegada  */
{
  list<int>::iterator it=l.begin();
  for (int i=0; i<l.size(); ++i){
    l.insert(l.end(), *it);
    ++it;
  }
}

// a) que pasa al ejecutar esto

// b) cual seria un codigo correcto con size? 

void duplicar_llista(list<int>& l)
/* Pre: l=L */
/* Post: l passa a ser L seguida d'L una altra vegada  */
{
 
}

// c) cual seria un codigo correcto sin size

void duplicar_llista(list<int>& l)
/* Pre: l=L */
/* Post: l passa a ser L seguida d'L una altra vegada  */
{

}
