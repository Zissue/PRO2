#include <iostream>
#include "Cjt_estudiants.hh"

using namespace std;


int main() {
  cout.setf(ios::fixed);
  cout.precision(2);
  int ne;
  cin >> ne;
  Cjt_estudiants c(ne);
  c.llegir();
  bool acabar = false;
  string op; 
  cin >> op;
  while (not acabar)
  {
     if (op == "escriure")
     {
        cout << endl << "Conjunt:" << endl;
        c.escriure();
        cout << endl;
     }
     else if (op == "posicio")
     {
        int d;
        cin >> d;
        pair<bool, int> r = c.posicio_estudiant(d);
        if (not r.first)
           cout << endl << "L'estudiant amb DNI " << d << " no pertany al conjunt." << endl;
        else
           cout << endl << "La posicio de l'estudiant amb DNI " << d << " es " << r.second << endl;
     }
     else if (op == "modificar")
     {
        int p;
        cin >> p;
        Estudiant e = c.consultar_iesim(p);
        int j;
        double x;
        cin >> j >> x;
        e.modificar_nota_parcial(j, x);
        c.modificar_iesim(p, e);
     }
     else if (op == "consultar")
     {
        int i;
        cin >> i;
        cout << "La nota global de l'estudiant " << i << "-esim es " << c.consultar_iesim(i).consultar_nota_global() << endl;
     }
     else if (op == "presentats") c.parcials_presentats_aprovats();
     else acabar = true;
     cin >> op;
  }
}
