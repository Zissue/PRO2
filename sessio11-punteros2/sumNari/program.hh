
/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
void arbsuma(ArbreNari& asum) const {
	if (primer_node == nullptr) {
		asum.N = 0;
		asum.primer_node = nullptr;
	}
	else {
		asum.N = N;
		asum.primer_node = modnod(primer_node);
	}
}

static void sumnode(int& i, node_arbreNari* n) {
	if (n != nullptr) {
		i += n->info;
		for (int j = 0; j < (n->seg).size(); j++) {
			sumnode(i, n->seg[j]);
		}
	}
}

static node_arbreNari* modnod(node_arbreNari* n) {
	node_arbreNari* aux;
	if (n == nullptr) aux = nullptr;
	else {
		aux = new node_arbreNari;

		int count = 0;
		sumnode(count, n);
		aux->info = count;

		int ari = (n->seg).size();
		aux->seg = vector<node_arbreNari*>(ari);

		for(int i = 0; i < ari; i++) {
			aux->seg[i] = modnod(n->seg[i]);	
		}
	}
	return aux;
}