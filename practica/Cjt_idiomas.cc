/** @file Cjt_idiomas.cc
    @brief Implementación de la clase Cjt_idiomas
*/

#include "Cjt_idiomas.hh"
using namespace std;

    // Operaciones privadas //

void Cjt_idiomas::mod_idioma(const string& lang) 
{
    Tabla nueva;
    nueva.leer();

    cidiomas[lang].sumar_tablas(nueva);
}

void Cjt_idiomas::add_idioma(const string& lang) 
{
    Tabla chart;
    chart.leer();

    Idioma id(chart);

    cidiomas.insert(make_pair(lang,id));
}

bool Cjt_idiomas::exist_idioma(const string& lang) 
{
    map<string, Idioma>::iterator it = cidiomas.find(lang);
    return it != cidiomas.end();
}


    // Constructoras //

Cjt_idiomas::Cjt_idiomas() {}


    // Modificadoras //

void Cjt_idiomas::update_cjt(const string& lang) 
{
    if (exist_idioma(lang)) {
        mod_idioma(lang);
        cout << "Modificado " << lang << endl;
    }
    else {
        add_idioma(lang);
        cout << "Anadido " << lang<< endl;
    }
    cout << endl;
}


    // Entrada / Salida //

void Cjt_idiomas::leer(int n) 
{
    for (int i = 0; i < n; i++) {
        string idioma;
        cin >> idioma;
        add_idioma(idioma);
    }
}


    // Consultoras //

void Cjt_idiomas::codifica(const string& idioma, const string& text) 
{
    cout << "Codifica en " << idioma << " el texto:" << endl;
    cout << text << endl;

    if (exist_idioma(idioma)) {

        pair<bool, string> p = cidiomas[idioma].belong_text(text);

        if (p.first and p.second == "") cidiomas[idioma].cout_codifica(text);
        else {
            cout << "El texto no pertenece al idioma; ";
            cout << "primer caracter que falla: " << p.second << endl;
        }
    }
    else {
        cout << "El idioma no existe" << endl;
    }
    cout << endl;
}

void Cjt_idiomas::decodifica(const string& idioma, const string& text) 
{
    cout << "Decodifica en " << idioma << " el texto:" << endl;
    cout << text << endl;

    if (exist_idioma(idioma)) {

        string decoded = "";

        pair<bool, int> p = cidiomas[idioma].belong_and_decode(text, decoded);

        if (p.first) cout << decoded << endl;
        else {
            cout << "El texto no procede de una codificacion del idioma; ";
            cout << "ultima posicion del codigo correspondiente al ultimo ";
            cout << "caracter que se podria decodificar: " << p.second << endl;
        }
    }
    else {
        cout << "El idioma no existe" << endl;
    }
    cout << endl;
}

void Cjt_idiomas::cons_chart(const string& lang) 
{
    cout << "Tabla de frecuencias de " << lang << ":" << endl;

    if (exist_idioma(lang)) {
        cidiomas[lang].escribir_tabla();
        cout << endl;   
    }
    else cout << "El idioma no existe" << endl << endl;

}

void Cjt_idiomas::cons_treecode(const string& lang) 
{
    cout << "Treecode de " << lang << ":" << endl;

    if (exist_idioma(lang)) {
        cidiomas[lang].escribir_treecode();
    }
    else cout << "El idioma no existe" << endl;
    cout << endl;
}

void Cjt_idiomas::cons_codigos(const string& lang) 
{
    string w;
    cin >> w;

    bool error = false;

    if (exist_idioma(lang)) {

        if (w != "todos") {
            error = !(cidiomas[lang].cons_char(w));
            if (!error) {
                cout << "Codigo de " << w << " en " << lang << ":" << endl;
                cidiomas[lang].escribir_char_cod(w);
            }
        }
        else {
            cout << "Codigos de " << lang << ":" << endl;
            cidiomas[lang].escribir_codigos();  
        }
    }
    else error = true;

    if (error) {
        if (w != "todos") {
            cout << "Codigo de " << w << " en " << lang << ":" << endl;
            cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
        }
        else {
            cout << "Codigos de " << lang << ":" << endl;
            cout << "El idioma no existe" << endl;
        }
    }
    cout << endl;
}
