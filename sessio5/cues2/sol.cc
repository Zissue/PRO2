#include <iostream>
#include <queue>
using namespace std;

void recalcular_min_max(queue<int> q, int& min, int& max) {
	max = -1000, min = 1000;
	while (!q.empty()) {
		if (max < q.front()) max = q.front();
		if (min > q.front()) min = q.front();
		q.pop();
	}
}

int main() {
	int x, max = -1000, min = 1000;
	double total = 0;
	queue<int> q;

	while (cin >> x and x >= -1001 and x <= 1000) {
		if (x != -1001) {
			q.push(x);
			if (x > max) max = x;
			if (x < min) min = x;
			total += x;
		} 
        else if (!q.empty()) {
			int num = q.front();
			q.pop();
			total -= num;
			if (num == max or num == min) recalcular_min_max(q, min, max);
		}

		if (q.empty()) {
			cout << '0' << endl;
			max = -1000, min = 1000;
		} 
        else cout << "min " << min << "; max " << max << "; media " << (total/q.size()) << endl;
	}
}