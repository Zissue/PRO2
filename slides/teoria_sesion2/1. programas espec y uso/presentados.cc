#include "Estudiant.hh"
#include <vector>

double presentats (const vector<Estudiant> &vest)
/* Pre: vest conté almenys un element <=> vest.size()>0 */
/* Post: el resultat és el percentatge de presentats de vest */
{
  int numEst = vest.size();
  int n = 0;
  for (int i=0; i<numEst; ++i) if(vest[i].te_nota()) ++n;
  /* n és el nombre d'estudiants de vest amb nota */
  double p = n*100./numEst;
  return p;
}

// redundante e ineficiente
//{
// Estudiant e = vest[i];
//  if(e.te_nota()) ++n;
// ....
//}
