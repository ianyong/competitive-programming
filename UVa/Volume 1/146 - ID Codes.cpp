#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char code[51];

int main() {
    while (true) {
        scanf("%s", code);
        if (strcmp(code, "#") == 0) {
            break;
        }
        next_permutation(code, code + strlen(code)) ? printf("%s\n", code) : printf("No Successor\n");
    }
}
