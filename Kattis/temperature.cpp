#include <cstdio>
using namespace std;

int X, Y;

int main() {
    scanf("%d %d", &X, &Y);
    if (Y == 1) {
        if (X == 0) {
            printf("ALL GOOD\n");
        } else {
            printf("IMPOSSIBLE\n");
        }
    } else {
        printf("%lf\n", X / (1.0 - Y));
    }
}
