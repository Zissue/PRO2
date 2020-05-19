int suma_vect_int(const vector<int> &v)
/* Pre: cert */
/* Post: el valor retornat és la suma de v */
{
  // dos opciones
  return  i_suma_vect_int(v,v.size()-1);
  return  ii_suma_vect_int(v, 0, v[0]);
}

int i_suma_vect_int(const vector<int> &v, int i)
/* Pre: v.size()>0, 0<=i<v.size() */
/* Post: el valor retornat és la suma de v[0..i] */
{
  int s;
  if (i==0) s = v[i];
  else { // i>0
    s = i_suma_vect_int(v,i-1);
    /* HI: s és la suma de v[0..i-1] */
    s+=v[i]; 
 }
  return s;
}

// si i=0:  suma de v[0..0] = v[0]

// si i>0:  suma de v[0..i] = suma v[0..i-1] + v[i]
//          suma v[0..i-1] se obtiene con la recursividad 
//          i-1 cumple la pre; v[i] se accede correctamente

int ii_suma_vect_int(const vector<int> &v, int i, int& s)
/* Pre: v.size()>0, 0<=i<v.size(), s és la suma de v[0..i] */
/* Post: el valor retornat és la suma de v */
{
  int sum;
  if (i==vsize()-1) sum = s;
  else {
    sum = ii_suma_vect_int(v, i+1, s+v[i+1]);
  }
}

// si i=vsize()-1: la s de la pre vale suma de v[0..vsize()-1]
//                 equivale a la suma total de v
//
// si i<vsize()-1: si llamo con i+1, la s ha de cumplir la nueva pre:
//                 s= suma de v[0..i+1] =  suma de v[0..i] + v[i+1]=
//                 s (antigua) + v[i+1]
//
//                 i+1 cumple la pre; v[i+1] se accede correctamente

// la suma total se calcula:

