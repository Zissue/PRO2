#include <vector>
#include <iostream>
using namespace std;

int suma(const vector<int>& v, int i, int f) {
	int sum = 0;
	for (int j = i; j <= f; j++) {
		sum += v[j];
	}
	return sum;
}

 /* Pre: cert */
 /* Post: el resultat es el nombre d'elements frontissa de v */
// int comptatge_frontisses(const vector<int> &v) {

// 	int sumapost = suma(v, 1, v.size()-1);
// 	int sumaant = 0;
// 	int nf = 0;

// 	// Inv: 0 <= i <= v:size() i nf = nombre de frontisses a v[0..i-1]
// 	// i sumaant es la suma de v[0..i-1],
// 	// i sumapost es la suma de v[i + 1..v.size()-1] 
// 	for (int i = 0; i < v.size(); i++) {
// 		if (v[i] == sumapost - sumaant) nf++;
// 		sumaant += v[i];
// 		if (i < v.size()-1) sumapost -= v[i+1];
// 	}
// 	return nf;
// }

int comptatge_frontisses(const vector<int> &v) {

	int nf = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == suma(v, i+1, v.size()-1) - suma(v, 0, i-1)) nf++;
	}
	return nf;
}