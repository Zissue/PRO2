/* Pre: el parametre implicit no es buit */
/* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
T max_suma_cami() const {
	T sum = 0;
	if (primer_node != nullptr) {
		sum = primer_node->info;
		sumi(primer_node, sum);
		return sum;
	}
	else return sum;
}

static void sumi(node_arbreGen* n, T& count) {
	if (n != nullptr) {
		int ari = (n->seg).size();
		if (ari > 0) {
			int max = (n->seg[0])->info;
			node_arbreGen* aux = n->seg[0];
			for (int i = 1; i < ari; i++) {
				if (n->seg[i] != nullptr) {
					if ((n->seg[i])->info > max) {
						max = (n->seg[i])->info;
						aux = n->seg[i];
					}
				}
			}
			count += max;
			sumi(aux, count);
		}
	}
}