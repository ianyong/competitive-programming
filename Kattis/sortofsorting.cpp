#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_NAMES 200

int n;
string names[MAX_NAMES];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> names[i];
        }
        stable_sort(names, names + n, [](string s1, string s2) -> bool {
            return s1.compare(0, 2, s2, 0, 2) < 0;
        });
        for (int i = 0; i < n; i++) {
            cout << names[i] << endl;
        }
        cout << endl;
    }
}