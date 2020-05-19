// (c) FiberHub, https://fiberhub.tk
//Llibreries necessàries: Cjt_estudiants, Estudiant

#include "Cjt_estudiants.hh"

/* Pre: 1 <= i <= mida()
		L'estudiant i-èsim té notes assignades per a tots els exàmens parcials de 
		l'assignatura. La nota de cada examen parcial pot ser -1, si l'estudiant 
		no s'ha presentat a aquest examen parcial, o una nota vàlida en el rang 
		[0...Estudiant::nota_maxima()]. */
/* Post: L'estudiant i-èsim passa a tenir assignada la seva nota global en 
		 l'assignatura, que pot ser -1, si es considera que la seva qualificació 
		 global ha de ser NP (No Presentat), o una nota vàlida en el rang 
		 [0...Estudiant::nota_maxima()], que correspon a la suma ponderada de les 
		 seves notes en els exàmens parcials de l'assignatura als quals s'ha 
		 presentat. */
void Cjt_estudiants::avaluacio_global_iesim(int i) {
	Estudiant est = consultar_iesim(i);

	double pes_np = 0, nota_global = 0;
	int n_ex_parcials = nombre_ex_parcials();

	for (int j = 1; j <= n_ex_parcials; ++j) {
		if (est.consultar_nota_parcial(j) == -1) pes_np += pes_parcial(j);
		else nota_global += est.consultar_nota_parcial(j) * pes_parcial(j);
	}

	if (pes_np > 0.5) est.assignar_nota_global(-1);
	else est.assignar_nota_global(nota_global);
	vest[i-1] = est;
}

/* Pre: Tots els estudiants del paràmetre implícit tenen notes assignades per 
		a tots els exàmens parcials i també tenen assignada la seva nota global en 
		l'assignatura. La nota de cada examen parcial pot ser -1, si l'estudiant no 
		s'ha presentat a aquest examen parcial, o una nota vàlida en el rang
		[0...Estudiant::nota_maxima()]. */
/* Post: Al canal de sortida estàndard s'han escrit els identificadors dels 
		 exàmens parcials als quals s'han presentat tots els estudiants que tenen 
		 una nota global en l'assignatura més gran o igual a 5. Els identificadors 
		 d'aquests exàmens parcials estan ordenats en ordre creixent. */

void Cjt_estudiants::parcials_presentats_aprovats() const {

	vector<bool> subconj(nombre_parcials, true);
	
    for (int i = 0; i < nest; ++i) {
		if (vest[i].consultar_nota_global() >= 5.0) {
			for (int j = 1; j <= nombre_parcials; ++j) {
				if (vest[i].consultar_nota_parcial(j) == -1) subconj[j-1] = false;
			}
		} 
	}

	cout << endl << "Examens parcials presentats per tots els estudiants aprovats: ";
	
	for (int j = 1; j <= nombre_parcials; ++j) {
		if (subconj[j-1]) cout << " " << j;
	}
	cout << endl;
}

