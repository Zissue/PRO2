
bool cerca_lineal1(const vector<Estudiant> &vest, int dni)
/* Pre: cert */
/* El resultat indica si l'estudiant amb DNI = dni hi és a vest */
{ 
  bool b = false; 
  int numEst = vest.size();
  int i = 0;
  /* Inv: b = hi ha un estudiant a v[0..i-1] amb DNI = dni;
     0 <= i <= numEst */
  /* Cota: numEst-i */
  while (i < numEst and not b) {
    b = vest[i].consultar_DNI() == dni);
    ++i; 
  } 
  return  b;
} 


bool cerca_lineal2(const vector<Estudiant> &vest, int dni)
/* Pre: cert */
/* El resultat indica si l'estudiant amb DNI = dni hi és a vest */
{ 
  bool b = false; 
  int numEst = vest.size();
  int i = 0;
  /* Inv: no hi ha cap estudiant a v[0..i-1] amb DNI = dni;
     b => vest[i].consultar_DNI() == dni, 0 <= i <= numEst */
  /* Cota: numEst-i-int(b) */
  while (i < numEst and not b) {
    if (vest[i].consultar_DNI() == dni) b = true;
    else ++i; 
  } 
  return  b;
} 
