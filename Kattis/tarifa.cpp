#include <cstdio>
using namespace std;

int X, N, P;

int main() {
    scanf("%d %d", &X, &N);
    X *= N + 1;
    while (N--) {
        scanf("%d", &P);
        X -= P;
    }
    printf("%d\n", X);
}
