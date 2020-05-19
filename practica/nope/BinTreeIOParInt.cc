// (c) FIBerHub, https://fiberhub.tk

#include <iostream>
#include "ParInt.hh"
#include "BinTree.hh"
using namespace std;

// Pre: a és buit; el canal estandar d’entrada conté un nombre
// parell d’enters, que representa un arbre binari en preordre,
// on el parell 0 0 representa un arbre buit
// Post: a conté l’arbre que hi havia al canal estandar d’entrada
void read_bintree_parint(BinTree<ParInt>& a) {
    ParInt inp;
    if (inp.llegir()) {
        BinTree<ParInt> e, d;
        read_bintree_parint(e);
        read_bintree_parint(d);
        a = BinTree<ParInt> (inp, e, d);
    }
}

// Pre: a = A
// Post: s’han escrit al canal estandar de sortida els elements
// d’a recorrreguts en inordre, a = A
void write_bintree_parint(const BinTree<ParInt>& a) {
    if (not a.empty()) {
        write_bintree_parint(a.right());
        a.value().escriure();
        write_bintree_parint(a.left());
    }
}
