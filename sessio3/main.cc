#include <iostream>
#include <vector>
#include "Cjt_estudiants.hh"
using namespace std;

int main() {
    Cjt_estudiants cjest;
    cjest.llegir();
    cjest.esborrar_estudiant(3);
    cjest.escriure();
}
