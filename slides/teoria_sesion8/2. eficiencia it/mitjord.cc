#include "utils.PRO2"
#include <vector>

int suma(const vector<int> &v, int i)
/* Pre; i>=0 */
/* Post: El resultat és la suma de v[0..i-1] */
{
  int s=0;
  for (int j=0; j<i;++j)
    s+=v[j];
  return s;
}

bool mitjord(const vector<int> &v)
/* Pre: v.size()> 0 */
/* Post: El resultat indica si v está mitjanament ordenat */
{
  int i=1;
  bool b=true;
  //Inv: v[0..i-1] está mitjanament ordenat;
  //     si not b llavors v[i] no está mitjanament ordenat
  while (i<v.size() and b)
    if (v[i]<double(suma(v,i))/i) b=false;
    else ++i;
  return b;
}

bool mitjord_ef(const vector<int> &v){
/* Pre: v.size()> 0 */
/* Post: El resultat indica si v está mitjanament ordenat */
  int i=1;
  bool b=true;
  int s=v[0];
  //Inv: v[0..i-1] està mitjanament ordenat;
  //     si not b llavors v[i] no està mitjanament ordenat;
  //     s= suma v[0..i-1]; 1<=i; i<=v.size();
  while (i<v.size() and b) 
    if (v[i]<double(s)/i) b=false;
    else {
      s+=v[i]; 
      ++i;
    }
  return b;
}

int main(){

  vector<int> v;
  cout << "nombre d'elements: " << endl;
  int n;
  cin >> n;

  for (int i=0; i<n; ++i) v.push_back(i);
  cout << "Vector creat amb "<< n << " elements." << endl;
  
  cout << "Ordenat en mitjana ef: " <<  mitjord_ef(v) << endl;
  cout << "Ordenat en mitjana inef: " <<   mitjord(v) << endl;
}
