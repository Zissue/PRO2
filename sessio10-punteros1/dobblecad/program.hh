
/* Pre: cert */
/* Post: si m és NULL, el resultat, u i a són NULL; en cas
       contrari, el resultat apunta al primer node d'una cadena de
       nodes que són còpia de la cadena que té el node apuntat per m
       com a primer, u apunta a l'últim node, a és o bé NULL si oact
       no apunta a cap node de la cadena que comença amb m o bé apunta
       al node còpia del node apuntat per oact */
node_llista* copia_node_llista_it (node_llista* m, 
                                   node_llista* oact, 
                                   node_llista* &u, 
                                   node_llista* &a) 
{
    node_llista* first;

    if (m == nullptr) first = u = a = nullptr;
    else {
        first = new node_llista;
        first->info = m->info;
        first->ant = nullptr;
        
        if (oact == m) a = first;

        node_llista* pcopy = first;

        while (m->seg != nullptr) {
            m = m->seg;
            pcopy->seg = new node_llista;
            (pcopy->seg)->ant = pcopy;
            pcopy = pcopy->seg;
            pcopy->info = m->info;
            if (m == oact) a = pcopy;
        }

        pcopy->seg = nullptr;
        u = pcopy;
        if (oact == nullptr) a = nullptr;
    }
    return first;
}


/* Pre: cert */
/* Post: El p.i. passa a ser una còpia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
Llista& operator=(const Llista& original) {

    if (this != &original) {

        esborra_node_llista(primer_node);
        longitud = original.longitud;
        primer_node = copia_node_llista_it(original.primer_node, original.act,
            ultim_node, act);
    }

    return *this;
}