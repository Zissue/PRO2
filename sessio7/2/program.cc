#include <iostream>
#include <map>
using namespace std;

int main () {
    
    pair<char, string> p;
    map<string, int> list;
    
    while (cin >> p.first >> p.second) {
        
        map<string, int>::iterator it = list.find(p.second);
        
        if (p.first == 'f') {
            if (it == list.end()) cout << '0';
            else cout << list[p.second];
            cout << endl;
        }
        else if (p.first == 'e') {
            if (it != list.end()) {
                if (list[p.second] == 1) list.erase(it);
                else list[p.second]--;
            }
        }
        else if (p.first == 'a') {
            if (it == list.end()) list.insert(make_pair(p.second,1));
            else list[p.second]++;
        }
    }
}

