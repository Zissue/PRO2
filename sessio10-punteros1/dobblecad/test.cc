#include <iostream>
using namespace std;

int main () {
	char* n = new char;
	cin >> *n;
	cout << *n << endl;
	cout << n << endl;
	cout << &n << endl;
}