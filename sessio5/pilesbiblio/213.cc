#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void op1(vector< stack<string> >& cat) {
    string t; 
    int n;
    cin >> t >> n;
    cat[n-1].push(t);
}

void op2(vector< stack<string> >& cat) {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) cat[n-1].pop();
}

void op3(const vector< stack<string> >& cat) {
    int n;
    cin >> n;

    cout << "Pila de la categoria " << n << endl;

    int size = cat[n-1].size();
    stack<string> p(cat[n-1]);
    
    if (!p.empty()) {
        for (int i = 0; i < size; i++) {
            cout << p.top() << endl;
            p.pop();
        }
    }
}

int main () {
    int n;
    cin >> n;
    
    vector< stack<string> > cat(n);
    int op;
    
    cin >> op;
    while (op != -4) {
        if (op == -1) op1(cat);
        else if (op == -2) op2(cat);
        else {
            op3(cat);
            cout << endl;
        }
        cin >> op; 
    }
}
