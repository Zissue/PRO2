
/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
T maxim() const {
	int i;
	if (primer_node != nullptr) {
		i = primer_node->info;
		max_arbre(primer_node, i);	
	}
	else i = 0;
	return i;
}


static void max_arbre(node_arbreNari* node, int& i) {
	if (node != nullptr) {
		if (node->info > i) i = node->info;
		for (int j = 0; j < (node->seg).size(); j++) {
			max_arbre(node->seg[j], i);
		}
	}
}