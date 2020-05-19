#include <iostream>
#include "BinTree.hh"
#include "ParInt.hh"
#include "BinTreeIOParInt.hh"
using namespace std;


// int cerca(BinTree<ParInt>& t, int n, int& s, int& h) {
//     ParInt t = t.value();
//     bool found = false;
//     if (!t.empty()) {
//         if (n == t.primer()) {
//             s = t.segon();
//             found = true;
//         }
//         else if (n == t.segon()) {
//             s = t.primer();
//             found = true;
//         }
//         if (found) return 0;
//         else {
//             int lol = cerca(t.left(),n,s,h+1);
//             if (lol != -1) return h;
//             int lel = cerca(t.right(),n,s,h);
//             if (lel != -1) return h;
//         }
//     }
//     else return -1;
// }

// int main () {
    
//     BinTree<ParInt> t;
//     read_bintree_parint(t);
    
//     int n;
//     while(cin >> n) {
//         int s, h = 0;
//         int p = cerca(t,n,s,h);
//         if (p != -1) {
//             cout << n << " " << s << " " << p;
//         }
//         else cout << "-1";
//         cout << endl;
//     }
// }

int cercar(const BinTree<ParInt>& a, int n, int& s) {
    if (not a.empty()) {
        if (a.value().primer() == n) {
            s = a.value().segon();
            return 0;
        }
        int left = cercar(a.left(), n, s);
        if (left != -1) return 1 + left;
        int right = cercar(a.right(), n, s);
        if (right != -1) return 1 + right;
    }
    return -1;
}

int main() {
    BinTree<ParInt> arbre;
    read_bintree_parint(arbre);

    int n, s;
    while (cin >> n) {
        int p = cercar(arbre, n, s);
        if (p != -1) {
            cout << n << ' ' << s << ' '  << p << endl;
        } else cout << -1 << endl;

    }
}