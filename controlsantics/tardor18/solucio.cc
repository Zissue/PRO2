// Poseu aqui vostre nom, cognoms i grup de laboratori

// ZIXUAN, SUN, GRUP 32

#include "Cjt_estudiants.hh"

// Traieu els comentaris // abans de posar codi a les funcions


/* Pre: tots els dni de c hi són al p.i. */
/* Post: cada Estudiant del p.i. conté la millor nota entre 
   l'original i la que pugui tenir a c */ 
void Cjt_estudiants::unir_conjunts(const Cjt_estudiants& c){

    if (c.imax != -1) {
        for (int i = 0; i < c.nest; i++) {
            if (c.vest[i].te_nota()) {
                int dnic = c.vest[i].consultar_DNI();
                double notac = c.vest[i].consultar_nota();
                int b = cerca_dicot(vest, i, nest-1, dnic);

                if (dnic == vest[b].consultar_DNI()) {
                    if (!vest[b].te_nota())
                        vest[b].afegir_nota(notac);
                    else if (notac > vest[b].consultar_nota())
                            vest[b].modificar_nota(notac);
                }

                if (imax == -1 or notac > vest[imax].consultar_nota() or 
                (notac == vest[imax].consultar_nota() and dnic < vest[imax].consultar_DNI()))
                    imax = b;
            }
        }
    }
} 

/* Pre: a l'entrada estàndar hi ha una seqüència d'Estudiant (seguida d'un
   Estudiant amb dni 0 que no forma part de la seqüència), amb els dni
   ordenats creixentment i tots hi són al p.i. */
/* Post: cada Estudiant del paràmetre implicit conté la millor nota entre l'original
   i la que pugui tenir a la seqüència */ 

void Cjt_estudiants::actualitzar_conjunt() {

    Estudiant std;
    std.llegir();
    int b = 0;
    int dni = std.consultar_DNI();

    while (dni != 0) {
        b = cerca_dicot(vest, b, nest-1, dni);

        if (std.te_nota()) {
            double nota = std.consultar_nota();

            if (!vest[b].te_nota()) vest[b].afegir_nota(nota);
            else if (vest[b].consultar_nota() < nota) vest[b].modificar_nota(nota);

            if (imax == -1 or nota > vest[imax].consultar_nota() or
            (nota == vest[imax].consultar_nota() and dni < vest[imax].consultar_DNI()))
                imax = b;
        }
        std.llegir();
        dni = std.consultar_DNI();
    }

}
