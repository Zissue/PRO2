#include <iostream>
#include <vector>
#include "Estudiant.hh"

using namespace std;

void readB(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}

void readB(vector<double>& v) {
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}

double msele(const vector<double>& notes, const vector<int>& b) {
    double sum = 0.0;
    for (int i = 0; i < b.size(); i++) {
        sum += notes[b[i]-1];
    }
    return (sum/b.size());
}

int main () {
    int m, n, s;
    cin >> m >> n >> s;
    vector<int> b(s);
    readB(b);
    int dni;
    while (cin >> dni) {
        vector<double> notes(n);
        readB(notes);
        cout << dni << " " << msele(notes,b) << endl;
    }
}
