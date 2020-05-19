#include <iostream>
#include <stack>
#include "BinTree.hh"
using namespace std;

int fills(const BinTree<int>& a) {

	if (a.empty()) return 0;
	return 1 + fills(a.left()) + fills(a.right());

}

void cami_preferent(const BinTree<int>& a, stack<int>& c) {

	if (!a.empty()) {

		if (fills(a.left()) >= fills(a.right())) cami_preferent(a.left(), c);
		else cami_preferent(a.right(), c);

		c.push(a.value());
	} 	

}
