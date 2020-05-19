/** @file Treecode.cc
    @brief Implementación de la clase Treecode
*/

#include "Treecode.hh"
using namespace std;

    // Operaciones privadas //

bool operator<(const BinTree< pair<string,int> >& a1, const BinTree< pair<string,int> >& a2) 
{
    if (a1.value().second != a2.value().second) {
        return (a1.value().second < a2.value().second);
    }
    return (a1.value().first < a2.value().first);
}

list< pair<string,int> > Treecode::preorder(const BinTree< pair<string,int> >& a) 
{
    list< pair<string,int> > l;
    if (!a.empty()) {
        l.push_back(a.value());
        l.splice(l.end(),preorder(a.left()));
        l.splice(l.end(),preorder(a.right()));
    }
    return l;
}

list< pair<string,int> > Treecode::inorder(const BinTree< pair<string,int> >& a) 
{
    list< pair<string,int> > l;
    if (!a.empty()) {
        l.splice(l.end(),inorder(a.left()));
        l.push_back(a.value());
        l.splice(l.end(),inorder(a.right()));
    }
    return l;   
}

void Treecode::transformNodes(Tabla& t, set< BinTree< pair<string, int> > >& aux) 
{
    for (map<string, int>::iterator it = t.cons_it_begin(); it != t.cons_it_end(); it++) {

        pair<string,int> p = t.cons_it_esim(it);

        BinTree< pair<string, int> > treeaux(p);

        aux.insert(treeaux);
    }
}

pair<string,int> Treecode::sumPairs(const pair<string,int>& p1, const pair<string,int>& p2) 
{
    pair<string, int> result;

    if (p1.first < p2.first) result.first = p1.first + p2.first;
    else result.first = p2.first + p1.first;

    result.second = p1.second + p2.second;

    return result;
}

void Treecode::decodificar(const string& text, int& i, int& pos, string& decoded, const BinTree< pair<string, int> >& a) const
{
    if (!a.empty() and i <= text.size()) {

        // a es una hoja
        if (a.left().empty() and a.right().empty()) {
            decoded += a.value().first;
            pos = i;
            decodificar(text, i, pos, decoded, arbol);
        }
        else {
            if (text[i] == '0') {
                i++;
                decodificar(text, i, pos, decoded, a.left());
            }
            else {
                i++;
                decodificar(text, i, pos, decoded, a.right());
            }
        }
    }
}

string Treecode::codemaker(const string& x, const BinTree< pair<string, int> >& a, string& s) 
{
    if (!a.empty()) {
        if (a.value().first == x) return s;
        else {
            if (cerca(a.left(), x)) {
                s += "0";
                codemaker(x, a.left(), s);
                return s;
            }
            else {
                s += "1";
                codemaker(x, a.right(), s);
                return s;
            }
        }
    }
    return s;
}

bool Treecode::cerca(const BinTree< pair<string, int > >& a, const string& x) 
{
    if (a.empty()) return false;
    else return (a.value().first == x) or cerca(a.left(), x) or cerca(a.right(), x);
}


    // Constructoras //

Treecode::Treecode() {}

Treecode::Treecode(Tabla& nueva) 
{
    buildTreecode(nueva);
    update_orders();
}


    // Modificadoras //

void Treecode::buildTreecode(Tabla& t)
{
    set< BinTree< pair< string, int> > > aux;
    set< BinTree< pair< string, int> > >::iterator it;

    transformNodes(t, aux);
    
    int n = t.size();

    for (int i = 0; i < n-1; i++) {
        
        pair <string, int> pesq = (aux.begin())->value();
        
        BinTree< pair< string, int> > esq = *(aux.begin());
        
        it = aux.begin();
        aux.erase(it);

        pair<string, int> pdre = (aux.begin())->value();
        
        BinTree< pair< string, int> > dre = *(aux.begin());

        it = aux.begin();
        aux.erase(it);
        
        pair<string, int> pc = sumPairs(pdre, pesq);
        
        BinTree< pair< string, int> > cnode(pc, esq, dre);

        aux.insert(cnode);
    }
    
    it = aux.begin();
    if (aux.size() == 1) arbol = (*it);
    else cout << "error, queda más de 1 nodo en el conjunto" << endl;
}

void Treecode::update_orders() 
{
    lpre = preorder(arbol);
    lin = inorder(arbol);
}


    // Entrada / Salida //

void Treecode::writelist(const string& orden) 
{
    if (orden == "preorder") {
        for (list< pair<string,int> >::iterator it = lpre.begin(); it != lpre.end(); it++) {
            cout << it->first << " " << it->second << endl;
        }
    }
    else {
        if (orden == "inorder") {
            for (list< pair<string,int> >::iterator it = lin.begin(); it != lin.end(); it++) {
                cout << it->first << " " << it->second << endl;
            }
        }
    }
}


    // Consultoras //

pair<string, int> Treecode::decode(const string& text) const 
{
    string s = "";
    int i = 0, pos = 0;

    decodificar(text, i, pos, s, arbol);
  
    pair<string, int> p(s, pos);
    return p;
}

string Treecode::code_char(const string& character)
{
    string s = "";
    return codemaker(character, arbol, s);
}