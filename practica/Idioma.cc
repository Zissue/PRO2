/** @file Idioma.cc
    @brief Implementación de la clase Idioma
*/

#include "Idioma.hh"
using namespace std;

    // Operaciones privadas //

string Idioma::next_symbol(const string& s, int& i) 
{
    string out;

    if (s[i] >= 0) {
        out = string(1, s[i]);
        ++i; 
    }
    else {
        out = string(s, i, 2);
        i += 2;
    }
    return out;
}

void Idioma::update_codigos() 
{
    for (map<string, int>::iterator it = freqchart.cons_it_begin(); it != freqchart.cons_it_end(); it++) {
        string s = freqchart.cons_it_esim(it).first;
        string p = "";
        codigos.insert(codigos.end(), make_pair(s, p));
        codigos[s] = treecode.code_char(s);
    }
}

void Idioma::update_treecode(Tabla& nueva) 
{
    treecode.buildTreecode(nueva);
    treecode.update_orders();
}

    // Constructoras //

Idioma::Idioma() {}

Idioma::Idioma(Tabla& chart) 
{
    freqchart = chart;
    update_treecode(chart);
    update_codigos();
}


    // Modificadoras //

void Idioma::sumar_tablas(Tabla& nueva) 
{
    freqchart.merge_chart(nueva);
    update_treecode(freqchart);
    update_codigos();
}


    // Entrada / Salida //


    // Consultoras //

void Idioma::cout_codifica(const string& text) 
{
    int i = 0;
    while (i < text.length()) {
        string aux = next_symbol(text, i);
        cout << codigos[aux];
    }
    cout << endl;
}

void Idioma::escribir_tabla() 
{
    freqchart.escribir();
}

void Idioma::escribir_treecode() 
{
    cout << "recorrido en preorden:" << endl;
    treecode.writelist("preorder");
    cout << "recorrido en inorden:" << endl;
    treecode.writelist("inorder");
}

void Idioma::escribir_codigos() const 
{
    for (map<string, string>::const_iterator it = codigos.begin(); it != codigos.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void Idioma::escribir_char_cod(const string& c) const 
{
    map<string,string>::const_iterator it = codigos.find(c);
    cout << it->first << " " << it->second << endl;
}

bool Idioma::cons_char(const string& c) 
{
    map<string,string>::iterator it = codigos.find(c);
    return it != codigos.end();
}

pair<bool, string> Idioma::belong_text(const string& text) 
{
    string aux = "";
    bool found = false;

    int i = 0;
    int n = text.length();

    while (i < n) {
        aux = next_symbol(text, i);
        found = !(cons_char(aux));

        if (found) return make_pair(false, aux);
    }
    return make_pair(true, "");
}

pair<bool, int> Idioma::belong_and_decode(const string& text, string& decoded) const 
{
    pair<string, int> d = treecode.decode(text);

    decoded = d.first;
    int p = d.second;

    if (p == text.size()) return make_pair(true, -1);
    return make_pair(false, p);
}