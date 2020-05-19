#include "BinTree.hh"
#include "Tabla.hh"
#include "Treecode.hh"
#include <iostream>
using namespace std;

list< pair<string,int> > preorder(const BinTree< pair<string,int> >& a) {
	list< pair<string,int> > l;
	if (!a.empty()) {
		l.push_back(a.value());
		l.splice(l.end(),preorder(a.left()));
		l.splice(l.end(),preorder(a.right()));
	}
	return l;
}

list< pair<string,int> > inorder(const BinTree< pair<string,int> >& a) {
	list< pair<string,int> > l;
	if (!a.empty()) {
		l.splice(l.end(),inorder(a.left()));
		l.push_back(a.value());
		l.splice(l.end(),inorder(a.right()));
	}
	return l;	
}

bool cerca(const BinTree< pair<string, int > >& a, const string& x) {

	if (a.empty()) return false;
	else return (a.value().first == x) or cerca(a.left(), x) or cerca(a.right(), x);

}

string codemaker(const string& x, const BinTree< pair<string, int> >& a, string& s) {

	if (!a.empty()) {
		if (a.value().first == x) return s;
		else {
			if (cerca(a.left(), x)) {
				s += "0";
				codemaker(x, a.left(), s);
				return s;
			}
			else if (cerca(a.right(), x)) {
				s += "1";
				codemaker(x, a.right(), s);
				return s;
			}
		}
	}
	return s;
}

int main () {
	
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "====================================================================================" << endl;
		Tabla chart;
		chart.leer();
		map<string, int> conj = chart.cons_tabla();
		Treecode arbol(conj);
		BinTree<pair<string, int> > t = arbol.cons_tree();
		
		cout << "Recorrido en preorden:" << endl;
		arbol.writelist("preorder");
		cout << "Recorrido en inorden:" << endl;
		arbol.writelist("inorder");

		// cout << "preorder or inorder?" << endl;
		// string orden;
		// while (cin >> orden) arbol.writelist(orden);

		// // Nodo raiz
		// cout << t.value().first << " - " << t.value().second << endl;

		// // // nodo iz-raiz
		// cout << t.left().value().first << " - " << t.left().value().second << endl;
		// // // cout << t.left().left().value().first << " - " << t.left().left().value().second << endl;
		// // // cout << t.left().right().value().first << " - " << t.left().right().value().second << endl;

		// // // nodo dre-raiz
		// cout << t.right().value().first << " - " << t.right().value().second << endl;
		// cout << "fck it" << endl;
		// // //nodo dre-iz
		// cout << t.right().left().value().first << " - " << t.right().left().value().second << endl;
		// cout << "ganamos?" << endl;
		// // // nodo dre-dre
		// cout << t.right().right().value().first << " - " << t.right().right().value().second << endl;
	}

	// pair<string, int> c, esq, dre;

	// c = make_pair("_ab", 16);
	// esq = make_pair("b", 7);
	// dre = make_pair("_a", 9);


	// pair<string, int> ee("",25), ed("",25);
	// BinTree< pair<string, int> > tee(ee), ted(ed);

	// pair<string, int> de("a",4), dd("_",5);
	// BinTree< pair<string, int> > tde(de), tdd(dd);	

	// BinTree< pair< string, int> > tesq(esq,tee,ted), tdre(dre,tde,tdd);

	// BinTree< pair<string, int> > tree(c,tesq,tdre);

	// string pal;
	// cin >> pal;

	// if (cerca(tree, pal)) cout << "Encontrado!" << endl;
	// else cout << "Noup." << endl;

	// string r = "";
	// cout << codemaker(pal, tree, r) << endl;

	// cout << "Recorrido en preorden:" << endl;
	// list< pair<string,int> > lpre = preorder(tree);
	// for (list< pair<string,int> >::iterator it = lpre.begin(); it != lpre.end(); it++) {
	// 	cout << it->first << " " << it->second << endl;
	// }

	// cout << "Recorrido en inorden:" << endl;

	// list< pair<string,int> > lin = inorder(tree);
	// for (list< pair<string,int> >::iterator it = lin.begin(); it != lin.end(); it++) {
	// 	cout << it->first << " " << it->second << endl;
	// }
	
}

// 5
// a 30
// b 12
// c 18
// d 15
// e 25

// 3
// a 4
// b 7
// _ 5
