// (c) FiberHub, https://fiberhub.tk
//Llibreries necessàries: Cjt_estudiants, Estudiant

#include "Cjt_estudiants.hh"

/* Pre: tots els dni de c hi són al p.i. */
/* Post: cada Estudiant del paràmetre implicit conté la millor nota entre 
		 l'original i la que pugui tenir a c */
void Cjt_estudiants::unir_conjunts(const Cjt_estudiants & c) {
	if (c.imax != -1) {
		for (int i = 0; i < c.nest; ++i) {
			if (c.vest[i].te_nota()) {
				int dni = c.vest[i].consultar_DNI();
				double nota = c.vest[i].consultar_nota();
				int b = cerca_dicot(vest, i, nest-1, dni);

				if (dni == vest[b].consultar_DNI()) {           
						if (not vest[b].te_nota()) vest[b].afegir_nota(nota);
						else if (vest[b].consultar_nota() < nota) vest[b].modificar_nota(nota);

				if (imax == -1 or nota > vest[imax].consultar_nota() or
					 (nota == vest[imax].consultar_nota() and dni < vest[imax].consultar_DNI())) imax = b; 
				}
			}
		}
	}
}

/* Pre: a l'entrada estàndar hi ha una seqüència d'Estudiant (seguida d'un
		Estudiant amb dni 0 que no forma part de la seqüència), amb els dni
		ordenats creixentment i tots hi són al p.i. */
/* Post: cada Estudiant del paràmetre implicit conté la millor nota entre l'original
		 i la que pugui tenir a la seqüència */ 
void Cjt_estudiants::actualitzar_conjunt() {
	Estudiant est;
	est.llegir();
	int b = 0;
	int dni = est.consultar_DNI();

	while (dni != 0)  {
		b = cerca_dicot(vest, b, nest-1, dni);

		if (est.te_nota()) {
			double nota = est.consultar_nota();
			if (not vest[b].te_nota()) vest[b].afegir_nota(nota);
			else if (vest[b].consultar_nota() < nota) vest[b].modificar_nota(nota);

			if (imax == -1 or nota > vest[imax].consultar_nota() or
				 (nota == vest[imax].consultar_nota() and dni < vest[imax].consultar_DNI())) imax = b; 
		}
		est.llegir();
		dni = est.consultar_DNI();
	}
}