#include <cstdio>
using namespace std;

int t, n;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        n = ((n * 63 + 7492) * 5 - 498) % 100 / 10;
        if (n < 0) {
            n *= -1;
        }
        printf("%d\n", n);
    }
}
