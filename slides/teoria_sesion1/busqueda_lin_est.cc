
bool busqueda_lineal(const vector<Estudiant> &v, int dni)
/* Pre: cert */
/* Post: el resultat indica si l'estudiant amb DNI = "dni" hi és a v */   
{
  bool b = false;
  int numEst = v.size();
  int i = 0;
  while (i < numEst and not b) {
    if (v[i].consultar_DNI() == dni) b = true;
    else ++i;
  }
  return  b;
}

// forma compacta ...
