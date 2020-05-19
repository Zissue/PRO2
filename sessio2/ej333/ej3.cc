#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

#include <iostream>
#include <vector>
using namespace std;

void update(Cjt_estudiants& c1, const Cjt_estudiants& c2) {
    int n = c1.mida();
    for (int i = 1; i <= n; i++) {

        Estudiant e1 = c1.consultar_iessim(i);
        Estudiant e2 = c2.consultar_iessim(i);

        if (e1.te_nota() and e2.te_nota()) {
            if (e1.consultar_nota() < e2.consultar_nota()) c1.modificar_iessim(i, e2);
            if (e1.consultar_nota() > 10) c1.modificar_iessim(i, e2);
        }
        else if (!e1.te_nota() and e2.te_nota()) c1.modificar_iessim(i, e2);
    }
}

int main () {
    Cjt_estudiants c1;
    c1.llegir();
    Cjt_estudiants c2;
    c2.llegir();
    update(c1,c2);
    c1.escriure();
}