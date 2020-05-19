
typedef vector <vector<int> > Matriz;

void producte_Matriz_int(const Matriz& m1, const Matriz& m2, Matriz& prod)
  /* Pre: num. col. de m1 = num. fil de m2 */
  /* Post: prod es el producto de m1 y m2 */
{
  int fil = m1.size(); int col1 = m1[0].size(); int col2 = m2[0].size();
  prod = Matriz(fil, vector<int>(col2,0));
  for (int i = 0; i < fil; ++i) 
    for (int j = 0; j < col2; ++j) 
      for (int k = 0; k < col1; ++k) 
	p[i][j] += m1[i][k] * m2[k][j];
}
      
// version while con invariantes

void producte_Matriz_int(const Matriz& m1, const Matriz& m2, Matriz& prod)
  /* Pre: num. col. de m1 = num. fil de m2 */
  /* Post: prod es el producto de m1 y m2 */
{
  int fil = m1.size(); int col1 = m1[0].size(); int col2 = m2[0].size();
  prod = Matriz(fil, vector<int>( col2,0)); // inic. sofisticada
  int i=0;
  /* Inv1: prod[0..i-1] es el prod de m1[0..i-1] y m2, 0<=i<=fil */
  /* Cota1: fil-i */
  while (i<fil){   
    int j=0;
    /* Inv2: Inv1 + prod[i][0..j-1] es el prod de m1[i] y m2[][0..j-1] 
       (las columnas de m2 desde la 0 a la j-1), 0<=j<=col2 */
    /* Cota2: col2-j */
    while (j<col2){  
      int k = 0;
      /* Inv3: Inv2 + prod[i][j] es la suma de m1[i][0..k-1] * m2[0..k-1][j], 
         0<=k<=col1 */
      /* Cota3: col1-j */
      while ( k < col1) {
	prod[i][j] += m1[i][k] * m2[k][j];
	++k;
      }
      ++j;
    }
    ++i;
  }
}
