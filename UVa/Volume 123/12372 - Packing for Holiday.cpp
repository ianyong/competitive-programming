#include <cstdio>
using namespace std;

int T, L, W, H;

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d %d %d", &L, &W, &H);
        printf("Case %d: ", i);
        if (L <= 20 && W <= 20 && H <= 20) {
            printf("good\n");
        } else {
            printf("bad\n");
        }
    }
}
