#include <iostream>
#include <queue>
using namespace std;

void calc(queue<int> seq, int& min, int& max) {
    max = -1000; min = 1000;
    while (!seq.empty()) {
        int front = seq.front();
        if (max < front) max = front;
        if (min > front) min = front;
        seq.pop();
    }
}

int main () {
    int n, max = -1000, min = 1000;
    double av = 0.0;
    queue<int> seq;

    while (cin >> n and n >= -1001 and n <= 1000) {
        if (n != -1001) {
            seq.push(n);
            if (max < n) max = n;
            if (min > n) min = n;
            av += n;
        } 
        else if (!seq.empty()) {
            int front = seq.front();
            seq.pop(); 
            av -= front;
            if (front == max or front == min) calc(seq,min,max);
        }
        if (seq.empty()) {
            cout << '0' << endl;
            max = -1000; min = 1000; 
        }
        else {
            cout << "min " << min << "; max " << max << "; media " << (av/seq.size()) << endl;
        }
    }
}