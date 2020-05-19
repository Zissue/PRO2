#include "LlistaIOParInt.hh"

// Pre: l és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)
void LlegirLlistaParInt(list<ParInt>& l) {
    
    ParInt inp;
    list<ParInt>::iterator it = l.end();
    
    while (inp.llegir()) {
        l.insert(it,inp);
    }
    
}

// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de l
void EscriureLlistaParInt(const list<ParInt>& l) {
    
    for (list<ParInt>::const_iterator cit = l.begin(); cit != l.end(); cit++) {
        (*cit).escriure();
    }
    
}
