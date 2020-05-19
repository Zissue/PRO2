#include "CuaIOParInt.hh"

void llegirCuaParInt(queue<ParInt>& c) {
    ParInt inp;
    while(inp.llegir()) {
        c.push(inp);
    }
}
// Pre: c és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0 
// Post: s’han encuat a c els elements llegits fins al 0 0 (no inclòs)


void escriureCuaParInt(queue<ParInt> c){
    int size = c.size();
    for (int i = 0; i < size; i++) {
        c.front().escriure();
        c.pop();
    }
}
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de c