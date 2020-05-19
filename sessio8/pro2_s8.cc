/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 
En este ejemplo se construye un programa modular que ofrece un menú de opciones para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.

Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo
de proyecto completamente documentado, incluyendo los elementos privados.
*/

/** @file pro2_s8.cc
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Prenda.hh"
#include "Lavadora.hh"
#include "Cubeta.hh"
#ifndef NO_DIAGRAM // explicado en Prenda.hh
#include "readbool.hh"

#endif

/** @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/
int main ()
{
    int op;
    
    Lavadora l;
    Cubeta c;
     
    while (cin >> op and op != -8) {
        // inicializa lavadora l
        if (op == -1) {
            if (!l.esta_inicializada()) {
                int p;
                cin >> p;
                bool b = readbool();
                if (p > 0) l.inicializar(p, b);
            }
        }
        // anade prenda p a la lavadora l
        else if (op == -2 and l.esta_inicializada()) { 
            int peso;   cin >> peso;
            bool b = readbool();
            if (peso > 0) {
                Prenda p(peso, b);
                if (p.consul_color() == l.consultar_color() and l.consultar_peso() + p.consul_peso() <= l.consultar_peso_maximo()) l.anadir_prenda(p);
            }
        }
        // anade prenda p a la cubeta c
        else if (op == -3) {
            int peso;
            cin >> peso;
            bool b = readbool();
            if (peso > 0)  {
                Prenda p1(peso, b);
                c.anadir_prenda(p1);
            }
        }
        // la cubeta completa el lavado de la lavadora l
        else if (op == -4) {
            if (l.esta_inicializada()) c.completar_lavadora(l);
            //else cout << "   Lavadora:" << endl << "Lavadora no inicializada" << endl;
        }
        // realiza un lavado
        else if (op == -5 and l.esta_inicializada()) {
            l.lavado();
        }
        // escribe el contenido de la cubeta c
        else if (op == -6) {
            cout << "   Cubeta:" << endl;
            c.escribir();
        }
        // escribe el contenido de la lavadora l
        else {
            if (l.esta_inicializada()) {
                cout << "   Lavadora:" << endl;
                l.escribir();
            }
            else {
                cout << "   Lavadora:" << endl << "Lavadora no inicializada" << endl;
                cout << endl;
            }
        }
    }
}

