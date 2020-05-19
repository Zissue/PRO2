
/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
bool buscar(const T& x) const {
	return cerca(primer_node, x);
}

static bool cerca(node_arbreGen* n, const T& x) {
	if (n == nullptr) return false;
	else {
		if (n->info == x) return true;

		int ari = (n->seg).size();
		for (int i = 0; i < ari; i++) {
			if (cerca(n->seg[i], x)) return true;
		}
	}
	return false;
}