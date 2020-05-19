#include "LlistaIOEstudiant.hh"
using namespace std;

// Pre: l és buida; el canal estandar d’entrada conté parelles
// de valors <enter, double>, acabat per un parell 0 0 
// Post: s’han afegit al final de l els estudiants llegits fins al 0 0 (no inclòs)
void LlegirLlistaEstudiant(list<Estudiant>& l) {
    
    Estudiant aux;
	aux.llegir();
	while (not (aux.consultar_DNI() == 0 and aux.consultar_nota() == 0)) {
		l.push_back(aux);
		aux.llegir();
	}
}   

// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de l
void EscriureLlistaEstudiant(list<Estudiant>& l) {

    list<Estudiant>::const_iterator it = l.begin();

    while (it != l.end()) {
        (*it).escriure();
        it++;
    }
}