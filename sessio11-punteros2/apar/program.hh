
/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
int freq(const T& x) const {
	if (primer_node == nullptr) return 0;
	else {
		int count = 0;
		countx(primer_node, count, x);
		return count;
	}
}

static void countx(node_arbreGen* n, int& count, const T& x) {
	if (n != nullptr) {
		if (n->info == x) count++;
		int ari = (n->seg).size();
		for (int i = 0; i < ari; i++) {
			countx(n->seg[i], count, x);
		}
	}
}