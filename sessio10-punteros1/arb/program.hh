
public:

/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
void arb_sumes(Arbre<int> &asum) const {
    asum.primer_node = aux_sumas(primer_node);
}

private:

/* Pre: cierto */
/* Post: Si m es NULL, el resultado es NULL; en otro caso, m apunta al nodo 
raíz de una jerarquía de nodos que representa un árbol A, y n apunta al nodo 
raíz de una jerarquía de nodos que representa el árbol de sumas de A. */
static node_arbre* aux_sumas(node_arbre* m) {
    
    node_arbre* aux;

    if (m == nullptr) aux = nullptr;
    else {

        aux = new node_arbre;

        aux->info = m->info;

        aux->segE = aux_sumas(m->segE);
        if (aux->segE != nullptr) aux->info += (aux->segE)->info;

        aux->segD = aux_sumas(m->segD);
        if (aux->segD != nullptr) aux->info += (aux->segD)->info;

    }
    return aux;
}