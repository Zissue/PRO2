/** @file Tabla.cc
    @brief Implementación de la clase Tabla
*/

#include "Tabla.hh"
using namespace std;

    // Operaciones privadas //

bool Tabla::exist_char(const string& s) 
{
    map<string, int>::iterator it = chart.find(s);
    return it != chart.end();
}


    // Constructoras //

Tabla::Tabla() {}


    // Modificadoras //

void Tabla::merge_chart(Tabla& nueva) 
{
    
    map<string, int>::iterator ito = chart.begin();
    map<string, int>::iterator itn = nueva.cons_it_begin();

    while (itn != nueva.cons_it_end() and ito != chart.end()) {
        
        if (ito->first == nueva.cons_it_esim(itn).first) {
            ito->second += nueva.cons_it_esim(itn).second;
            ito++;
            itn++;
        }
        else {
            if (ito->first < nueva.cons_it_esim(itn).first) ito++;
            else {
                chart.insert(ito, *(itn));
                itn++;
            }
        }
    }   
    
    while (itn != nueva.cons_it_end()) {
        chart.insert(ito, *(itn));
        itn++;
    }
}


    // Entrada / Salida //

void Tabla::leer() 
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        pair<string, int> p;
        cin >> p.first >> p.second;

        chart.insert(p);
    }
}

void Tabla::escribir() 
{
    for (map<string,int>::iterator it = chart.begin(); it != chart.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}


    // Consultoras //

pair<string, int> Tabla::cons_it_esim(map<string, int>::const_iterator it) const
{
    return *it;
}

map<string, int>::iterator Tabla::cons_it_begin()
{
    return chart.begin();
}

map<string, int>::iterator Tabla::cons_it_end()
{
    return chart.end();
}

int Tabla::size() const
{
    return chart.size();
}