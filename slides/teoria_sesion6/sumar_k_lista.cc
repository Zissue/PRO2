
void suma_llista_k(list<int> &l, int k)
/* Pre: l=L */
/* Post: Cada element d'l es la suma de k i l'element de L 
         a la seva mateixa posició */ 
{
  list<int>::iterator it;
  it = l.begin();      
  /* Inv: Els elements d'l de l'inici fins a la posició anterior
  a la que marca it són la suma de k mes el element corresponent
  de L. A partir de it fins al final de l, els elements son els
  mateixos que a L; it marca un element existent d'l o l.end() */
  /* Cota: num. d'elements d'l entre it i l.end() */
  while(it != l.end()){
    (*it)+=k;
    ++it;
  }
}

