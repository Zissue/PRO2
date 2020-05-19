#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

vector<Estudiant> llegir_est() {
    int n;
    cin >> n;
    vector<Estudiant> estudiants(n);
    for (int i = 0; i < n; i++) estudiants[i].llegir();
    return estudiants;
}

/*void simplificar_vec(vector<Estudiant> estudiants) {

    int n = estudiants.size();
    int dnicurr = -1;
    double ncurr = -2.0;
    bool first = true;

    for (int i = 1; i < n; i++) {
        if (dnicurr != estudiants[i].consultar_DNI()) {
            if (first) {
                first = false;
            }
            else {
                if (estudiants[i-1].te_nota()) cout << ncurr << endl;
                else cout << "NP" << endl;
            }
            cout << estudiants[i].consultar_DNI() << " ";
            dnicurr = estudiants[i].consultar_DNI();
            if (estudiants[i].te_nota()) ncurr = estudiants[i].consultar_nota();
            else ncurr = -1.0;
        }
        else {
            if (estudiants[i].te_nota() and ncurr < estudiants[i].consultar_nota()) {
                dnicurr = estudiants[i].consultar_DNI();
            }
        }
    }
    cout << ncurr << endl;
}*/

/*vector<Estudiant> simplificar_vec(vector<Estudiant> estudiants) {

    int n = estudiants.size();
    int dnicurr = -1, count = 0;
    double ncurr = -1.0;
    vector<Estudiant> simplificat;

    for (int i = 0; i < n; i++) {
        if (dnicurr == estudiants[i].consultar_DNI()) {
            if (estudiants[i].te_nota() and ncurr < estudiants[i].consultar_nota()) {
                if (estudiants[i].te_nota())
                    simplificat[count].modificar_nota(estudiants[i].consultar_nota());
                else simplificat[count].afegir_nota(estudiants[i].consultar_nota());
                simplificat[count].modificar_nota(estudiants[i].consultar_nota());
            }
        }
        else {
            simplificat.push_back(estudiants[i]);
            dnicurr = estudiants[i].consultar_DNI();
            if (estudiants[i].te_nota()) ncurr = estudiants[i].consultar_nota();
            else ncurr = -1.0;
            count++;
        }
    }
    return simplificat;
}*/

vector<Estudiant> simplificar_notes(const vector <Estudiant>& vin) {
    
    vector<Estudiant> vout;
    int count = -1;
    
    for (int i = 0; i < vin.size(); ++i) {
        if (i == 0 or (vin[i].consultar_DNI() != vin[i-1].consultar_DNI())) {
            vout.push_back(vin[i]);
            count++;
        }
        else if (vin[i].te_nota()){
            if ((not vout[count].te_nota()) 
            or vout[count].consultar_nota() < vin[i].consultar_nota())
                vout[count] = vin[i];
        }
    }
    return vout;
}

void escriure(const vector<Estudiant>& estudiants) {
    int n = estudiants.size();
    for (int i = 0; i < n; i++) {
        estudiants[i].escriure();
    }
}

int main () {
    vector<Estudiant> estudiants = llegir_est();
    estudiants = simplificar_notes(estudiants);
    escriure(estudiants);
    //simplificar_vec(estudiants);
}