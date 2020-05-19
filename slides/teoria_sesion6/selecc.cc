void ordena_per_seleccio(vector<double>& v)
/* Pre: v=V */
/* Post: v conte els mateixos elements que V i esta ordenat */
{
  int i = 0;
  while (i < v.size()) {
    int k = posicio_minim(v, i);
    /* i <= k < v.size(), 
       v[k] es menor o igual que tot elem en v[i..v.size()-1] */
    intercanvia(v[k], v[i]);
    ++i;
  }
}

Para abreviar, definimos ORD(v,i) = v[0..i-1] está ordenado

Supongamos que tras cada vuelta se cumple ORD(v,i). 

Entonces, tras la ultima vuelta se cumple ORD(v,v.size()), 
que equivale a la Post (TODO el vector está ordenado)

Antes de empezar el bucle, se cumple ORD(v,0) ya que si i=0
tenemos un trozo vacio de vector, que obviamente esta ordenado

Entonces falta garantizar que 

  v[0..i-1] esta ordenado  y  v[k] es el minimo del resto => 
  si intercambio v[i] con v[k], v[0..i] esta ordenado?

Eso se consigue manteniendo esta otra propiedad:

  todo elemento de v[i..v.size()-1] es mayor o igual que 
  todo elemento de v[0..i-1])

Asi llegamos al invariante del bucle:

a) 0<=i<=v.size(),
b) v[0..i-1] esta ordenado,
c) todo elemento de v[i..v.size()-1] es mayor o igual que 
   todo elemento de v[0..i-1])

