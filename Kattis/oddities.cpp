#include <cstdio>
using namespace std;

int n, x;

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        if (x % 2) {
            printf("%d is odd\n", x);
        } else {
            printf("%d is even\n", x);
        }
    }
}
