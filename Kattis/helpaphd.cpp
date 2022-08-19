#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string input;
int N, a, b;

int main() {
    scanf("%d ", &N);
    while (N--) {
        getline(cin, input);
        if (input == "P=NP") {
            printf("skipped\n");
            continue;
        }
        sscanf(input.c_str(), "%d+%d", &a, &b);
        printf("%d\n", a + b);
    }
}
