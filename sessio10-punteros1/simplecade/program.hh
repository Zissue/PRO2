   
/* Pre: cert */
/* Post: si m és NULL, el resultat és NULL; en cas contrari, el
   resultat apunta al primer node d'una cadena de nodes que són
   còpia de de la cadena que té el node apuntat per m com a primer */
node_pila* copia_node_pila_it(node_pila* m) {

	node_pila* first;

	if (m == nullptr) first = nullptr;
	else {
		node_pila* aux;
		first = aux = new node_pila;

		while (m != nullptr) {
			aux->info = m->info;
			m = m->seguent;

			if (m != nullptr) {
				aux->seguent = new node_pila;
				aux = aux->seguent;
			}
		}
		aux->seguent = nullptr;
	}
	return first;
}
    
/* Pre: cert */
/* Post: El p.i. passa a ser una còpia d'original i qualsevol
   contingut anterior del p.i. ha estat esborrat (excepte si el
   p.i. i original ja eren el mateix objecte) */

Pila& operator=(const Pila& original) {

	if (this != &original) {
		esborra_node_pila(primer_node);
		altura = original.altura;
		primer_node = copia_node_pila_it(original.primer_node);
	}
	return *this;
} 