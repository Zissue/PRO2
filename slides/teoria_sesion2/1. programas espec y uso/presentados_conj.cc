#include "Cjt_estudiants.hh"

double presentats (const Cjt_estudiants  &c)
/* Pre: c conté almenys un element */
/* Post: el resultat és el percentatge de presentats de c */
{
  int numEst = c.mida();
  int n = 0;
  for (int i=1; i<=numEst; ++i) 
    if(c.consultar_iessim(i).te_nota()) ++n;
  /* n és el nombre d'estudiants de c amb nota */
  return n*100./numEst;
}


void actualizar_nota (Cjt_estudiants  &c, const& Estudiant e)
/* Pre: existeix un element de c amb el mateix DNI que e */
/* Post: si la nota d'e millora la del seu corresponent en c,
   aquesta s'actualitza, en cas contrari c no canvia */
{
  // dues versions: amb estudiant auxiliar o sense

}
