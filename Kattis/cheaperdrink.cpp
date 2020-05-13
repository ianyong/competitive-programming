#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s;
vector<string> magnets;

string turnUpsideDown(string s);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        string s2 = turnUpsideDown(s);
        magnets.push_back(s2.empty() || s < s2 ? s : s2);
    }
    sort(magnets.begin(), magnets.end(), [](const string& s1, const string& s2) {
        return s1 + s2 < s2 + s1;
    });
    for (string s : magnets) cout << s;
}

string turnUpsideDown(string s) {
    reverse(s.begin(), s.end());
    for (char& c : s) {
        if (c == '6') c = '9';
        else if (c == '9') c = '6';
        else if (!(c == '0' || c == '1' || c == '8')) return "";
    }
    return s;
}