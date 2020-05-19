
double presentats (const vector<Estudiant> &vest)
/* Pre: vest conté almenys un element */
/* Post: el resultat és el percentatge de presentats de vest */
{
 int numEst = vest.size();
 int n = 0; int i = 0;
/* Inv: 0 <= i <= numEst, n=nombre d’estudiants amb nota en vest[0..i-1] */
/* Cota: numest-i */
 while (i<numEst){ 
   if(vest[i].te_nota()) ++n;
   ++i;
}
 /* n és el nombre d'estudiants de vest amb nota */
 double p = n*100./numEst;
 return p;
}

