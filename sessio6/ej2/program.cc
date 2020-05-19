#include <iostream>
#include <list>
#include "Estudiant.hh"
#include "LlistaIOEstudiant.hh"
using namespace std;

int main () {
    list<Estudiant> l;
    LlegirLlistaEstudiant(l);

    int dni;
    cin >> dni;

    int count = 0;
    for (list<Estudiant>::const_iterator it = l.begin(); it != l.end(); it++) {
        if ((*it).consultar_DNI() == dni) count++;
    }

    cout << dni << " " << count << endl;
}