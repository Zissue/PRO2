
typedef vector <vector<int> > Matriz;

Matriz sumar_Matriz_int(const Matriz& m1, const Matriz& m2)
/* Pre: m1 y m2 son de la misma dimensión */
/* Post: el resultado es la suma de m1 y m2 */
{
  int fil = m1.size(); int col = m1[0].size(); 
  Matriz suma (fil, vector<int>(col)); 
  for (int i=0; i<fil; ++i)               
    for (int j=0; j<col; ++j)
      suma[i][j] = m1[i][j] + m2[i][j];     
  return suma;
} 



// version void + while
void sumar_Matriz_int(const Matriz& m1, const Matriz& m2, Matriz& suma)
/* Pre: m1 y m2 son de la misma dimensión */
/* Post: el resultado es la suma de m1 y m2 */
{
  int fil = m1.size(); int col = m1[0].size(); 
  suma = Matriz (fil, vector<int>(col));  
  int i=0;
  /* Inv1: suma[0..i-1] es la suma de m1[0..i-1] y m2[0..i-1], 0<=i<=fil */
  /* Cota1: fil-i */
  while (i<fil){   
    int j=0;
    /* Inv2: Inv1 + suma[i][0..j-1] es la suma de m1[i][0..j-1] y m2[i][0..j-1],
             0<=j<=col */
    /* Cota2: col-j */
    while (j<col){
      suma[i][j] = m1[i][j] + m2[i][j];   
      ++j;
    }
    ++i;
  }
}
