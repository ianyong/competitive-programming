#include <iostream>
#include <string>
#include <map>
using namespace std;

#define TERMINATION_STR "#"

map<string, string> greetingsMap = {
    { "HELLO", "ENGLISH" },
    { "HOLA", "SPANISH" },
    { "HALLO", "GERMAN" },
    { "BONJOUR", "FRENCH" },
    { "CIAO", "ITALIAN" },
    { "ZDRAVSTVUJTE", "RUSSIAN" }
};

string input;
int i;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> input;
        if (input == TERMINATION_STR) {
            break;
        }
        cout << "Case " << ++i << ": ";
        if (greetingsMap.find(input) != greetingsMap.end()) {
            cout << greetingsMap[input] << '\n';
        } else {
            cout << "UNKNOWN" << '\n';
        }
    }
}
