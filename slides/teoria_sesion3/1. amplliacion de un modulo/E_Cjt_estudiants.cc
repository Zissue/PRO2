#include "E_Cjt_estudiants.hh"

void esborrar_estudiant(Cjt_estudiants &Cest, int dni)
{
  Cjt_estudiants Cestaux;
  int i = 1;
  while (dni!=Cest.consultar_iessim(i).consultar_DNI()) 
    {
      Cestaux.afegir_estudiant(Cest.consultar_iessim(i)); ++i;	
    } 
  // per la pre, segur que trobarem a Cest un estudiant amb DNI = dni;
  // en aquest punt, aquest estudiant és Cest.consultar_iessim(i);
  // ara hem d'afegir els elements següents a Cestaux     
  for (int j=i+1; j<=Cest.mida(); ++j) 
    Cestaux.afegir_estudiant(Cest.consultar_iessim(j));

  Cest = Cestaux; // s'ha de copiar el conjunt auxilar sobre el parametre
}

Estudiant estudiant_nota_max(const Cjt_estudiants &Cest)
{
  int i = 1;
  while (not Cest.consultar_iessim(i).te_nota()) ++i;
  int imax = i; ++i;
  // per la pre, segur que trobarem a Cest un estudiant amb nota;
  // imax n'és el primer; comprovem la resta
  while (i<=Cest.mida()){
    if (Cest.consultar_iessim(i).te_nota())
      if (Cest.consultar_iessim(imax).consultar_nota() <
	  Cest.consultar_iessim(i).consultar_nota())  imax = i;   	    
    ++i;
  }	  
  return Cest.consultar_iessim(imax);
}
 
