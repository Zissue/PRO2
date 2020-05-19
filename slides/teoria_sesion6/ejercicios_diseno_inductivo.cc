int solitaris (const vector<Estudiant> &vest)
/* Pre: vest.size()>0 */
/* Post: el resultat es el nombre de solitaris de vest */
{
  int n = 0;
  int i = 1;
  bool b = true;
  // Inv: n = nombre de solitaria en vest[0..i-2], 1<=i<=vest.size(),
  //      b = indica si vest[i-1] es diferent del seu anterior
  while (){

  }
  // A: n = nombre de solitaria en vest[0..vest.size()-2],
  //    b = indica si vest[vest.size()-1] es diferent del seu anterior


  return n;
}

// otro: suma maxima de subvectores de tam k

int long_pref_suma_max(const list<double>& l)
/* Pre: cert */
/* Post: el resultat indica la longitud del prefix mes curt de l de suma maxima */
{
  list<int>::iterator it = l.begin(); // prefijo vacio
  int lmin_smax = 0;  // longitud de un prefijo vacio
  double smax_lmin = 0; // suma de un prefijo vacio

  // Inv: lmin_smax = ...,  smax_lmin = ..., it tiene valores entre ...
  while (it!=l.end()){

    ++it;
  }
  return lmin_smax;
}

// otro: intervalos de tamaño k con numero maximo de impares
