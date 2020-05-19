#include "CuaIOParInt.hh"
#include <iostream>
#include <queue>
using namespace std;

void distrib (queue<ParInt>& inp, queue<ParInt>& q1, queue<ParInt>& q2) {
    
    int t1 = 0, t2 = 0;
    
    while(!inp.empty()) {

        
        ParInt aux = inp.front();
        int t = aux.segon();

        if (t1+t <= t2+t) {
            q1.push(aux);
            t1 += t;
        }
        else {
            q2.push(aux);
            t2 += t;
        }
        inp.pop();
    }
}

int main () {

    queue<ParInt> inp, q1, q2;

    llegirCuaParInt(inp);

    distrib(inp,q1,q2);

    escriureCuaParInt(q1);

    cout << endl;

    escriureCuaParInt(q2);
}