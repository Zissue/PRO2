#include <iostream>
#include <list>
using namespace std;

void invertir(list<int>& l, int m) {

	list<int>::iterator it = l.begin();  //1
	while (m > 0) {						 //2		

		int x = *it;

		it = l.erase(it);				 //3

		l.insert(l.begin(),x);			 //4	
		
		--m;

	}
}

int main () {
	list<int> l;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		l.insert(l.end(),x);
	}
	// cout << "xd" << endl;
	// for(list<int>::iterator it = l.begin(); it != l.end(); it++) {
	// 	cout << *it << " ";
	// }
	// cout << "xd" << endl;

	cout << endl;
	int m;
	cin >> m;
	invertir(l,m);

	for(list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}