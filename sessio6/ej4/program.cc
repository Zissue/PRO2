#include <iostream>
#include "ParInt.hh"
#include "BinTreeIOParInt.hh"
using namespace std;

int cerca(const BinTree<ParInt>& a, int n, int& s, int& h) {
    ParInt t = a.value();
    bool found = false;
    if (not a.empty()) {
        if (n == t.primer()) {
            s = t.segon();
            found = true;
        }
        else if (n == t.segon()) {
            s = t.primer();
            found = true;
        }
        if (found) return 0;
        else {
        	h++;
            int lol = cerca(a.left(), n, s, h);
            if (lol != -1) return h;
            h++;
            int lel = cerca(a.right(), n, s, h);
            if (lel != -1) return h;
        }
        return -99;
    }
    else return -1;
}

int main () {
    
    BinTree<ParInt> t;
    read_bintree_parint(t);
    
    int n;
    while(cin >> n) {
        int s, h = 0;
        int p = cerca(t,n,s,h);
        if (p != -1) {
            cout << n << " " << s << " " << p;
        }
        else cout << "-1";
        cout << endl;
    }
}